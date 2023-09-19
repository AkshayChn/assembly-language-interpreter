#include <iostream>
#include <fstream>
#include "ali.hpp"

//constructor
ALI::ALI(){
    setNameOfFIle();
    parseFile();
}

void ALI::setNameOfFIle(){
    std::cout << "Enter the SAL Source File Name\n";
    std::cin >> nameOfFile;
}

void ALI::printHelpText(){

}

void ALI::parseFile(){
    std::ifstream sourceFile;
    sourceFile.open(nameOfFile);
    if (sourceFile.fail()){
        std::cout << "File does not exist\n";
        exit(1);
    }
    if (sourceFile.is_open()) {
        std::string s;
        while (std::getline(sourceFile, s)){
            parseLine(s);
        }
    }
}

void ALI::printAllInstructions(){
    std::cout << "Printing all the instructions in memory\n";
    for (int i = 0; i < hw->instMemSize; i++){
        (hw->instMem[i])->print();
    }
    std::cout << "\n";
}

void ALI::printAllRegs(){
    std::cout << "A:" << hw->getregA() << ", B: " << hw->getregB() << ", PC:" << hw->getprogC()
        << ", ZeroB: " << hw->getZeroResultBit() << ", OverfB: " << hw->getOverflowBit() << "\n";
}

void ALI::printDataMem(){
    std::cout << "Data Memory: ";
    for (int i = 0; i < hw->dataMemSize; i++){
        std::cout << hw->dataMem[i] << ", ";
    }
    std::cout << "\n";
}

void ALI::parseLine(std::string st){
    if (st == "") return;
    std::string instr = st.substr(0, 3);
    std::string argum = st.erase(0,4);

    // add the right instruction to memory
    if (instr == "DEC") {hw->addInstToMem(new DEC(hw, argum));}
    if (instr == "LDA") {hw->addInstToMem(new LDA(hw, argum));}
    if (instr == "LDB") {hw->addInstToMem(new LDB(hw, argum));}
    if (instr == "LDI") {hw->addInstToMem(new LDI(hw, std::stol(argum)));}
    if (instr == "STR") {hw->addInstToMem(new STR(hw, argum));}
    if (instr == "XCH") {hw->addInstToMem(new XCH(hw));}
    if (instr == "JMP") {hw->addInstToMem(new JMP(hw, std::stoi(argum)));}
    if (instr == "JZS") {hw->addInstToMem(new JZS(hw, std::stoi(argum)));}
    if (instr == "JVS") {hw->addInstToMem(new JVS(hw, std::stoi(argum)));}
    if (instr == "ADD") {hw->addInstToMem(new ADD(hw));}
    if (instr == "HLT") {hw->addInstToMem(new HLT(hw));}
}

void ALI::executeAllInstructions(){
    std::cout << "Executing all instructions\n";
    while (!hw->getHalt()){executeSingleInstruction();}
}

void ALI::executeSingleInstruction(){
    if (!hw->getHalt()) {
        if (hw->getprogC() >= hw->instMemSize){
            std::cout << "Last instruction reached\n";
            hw->setHalt();
        }
        else {
            (hw->instMem[hw->getprogC()])->print();
            (hw->instMem[hw->getprogC()])->execute();
            printAllRegs();
            std::cout << "\n";
        }
    }
}

void ALI::commandLoop(){
    std::cout << "Started Command Loop\n";
    std::string commandLetter = "";
    //std::cin.clear();

    //std::cout << "Enter s, a, or q\n";
    std::getline(std::cin, commandLetter);

    while (!hw->getHalt()){
        //std::cin.clear();
        std::cout << "Enter s, a, or q\n";
        std::getline(std::cin, commandLetter);

        if (commandLetter == "s") executeSingleInstruction();
        else if (commandLetter == "a") executeAllInstructions();
        else if (commandLetter == "q") {
            std::cout << "Quitting!\n";
            exit(0);
        }
        else {
            std::cout << "Command not recognized\n";
            //printHelpText();
        }
    }
}

//void codeToTestAllInstructionsManually();

int main(){
    ALI ali;
    ali.printAllInstructions();
    ali.commandLoop();
    ali.printDataMem();
    
    //codeToTestAllInstructionsManually();
}

/*****
void codeToTestAllInstructionsManually(){

    Hardware *h = new Hardware();
    std::cout << h <<"\n";
    std::cout << h->zeroResultBit <<"\n";
    (*h).instMem[0] = new dummyInst();

    std::cout << "test 1 ****\n";
    (((*h).instMem[0]))->print();
    // TESTING XCH
    std::cout << "test 2 ****\n";
    XCH *xch = new XCH(h);

    h->regA = 1;
    h->regB = 2;

    xch->execute();
    xch->print();
    std::cout << h->regA << " " << h->regB <<"\n";
    std::cout << xch->isInRange(1);
    //LDI
    Instruction *ldi = new LDI(h, 1234);
    ldi->execute();
    ldi->print();
    std::cout << h->regA << "\n";

    
    //ADD
    Instruction *add = new ADD(h);
    h->regA = 10;
    h->regB = add->maxLim;
    add->execute();
    add->print();

    std::cout << h->regA << " " << h->getOverflowBit() << " " << h->getZeroResultBit() << "\n";

    h->addSymbol("hello");
    h->setValOfSymbol("hello", "waht");
    std:: cout << h->getValOfSymbol("hello") << "\n";

    h->addSymbol("oi");
    h->setValOfSymbol("oi", "the hell");
    std:: cout << h->getValOfSymbol("oi") << "\n";
    std:: cout << h->getValOfSymbol("hello") << "\n";
    //DEC STR
    Instruction *dec = new DEC(h, "lol");
    Instruction *str = new STR(h, "lol");

    dec->execute();
    str->execute();

    std:: cout << h->getValOfSymbol("lol") << "\n";
    //LDA LDB
    Instruction *lda = new LDA(h, "lol");
    h->setregA(900);
    std::cout << h->getregA() << "\n";
    lda->execute();
    std::cout << h->getregA() << "\n";

    Instruction *ldb = new LDB(h, "lol");
    h->setregB(12340);
    std::cout << h->getregB() << "\n";
    ldb->execute();
    std::cout << h->getregB() << "\n";

    // TESTING JMP JZA JVS
    Instruction *jmp = new JMP(h, 2);
    Instruction *jzs = new JZS(h, 4);
    Instruction *jvs = new JVS(h, 60);

    std::cout << "Initial progC " << h->getprogC() <<"\n";

    jmp->execute();
    std::cout << "After JMP " << h->getprogC() <<"\n";

    h->clearZeroResultBit();
    jzs->execute();
    std::cout << "First JZS FAILS " << h->getprogC() <<"\n";
    h->setZeroResultBit();
    jzs->execute();
    std::cout << "Second JZS Passes " << h->getprogC() <<"\n";

    h->clearOverflowBit();
    jvs->execute();
    std::cout << "First JVS FAILS " << h->getprogC() <<"\n";
    h->setOverflowBit();
    jvs->execute();
    std::cout << "Second JVS Passes " << h->getprogC() <<"\n";
}
****/