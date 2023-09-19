#include <string>
#include <iostream>
#include "instruction.hpp"

void dummyInst::execute(){
    std::cout << "Executed dummyInst!\n";
}

void XCH::execute(){
    //Exchange regA and regB
    long temp = hwPtr->getregA();
    hwPtr->setregA(hwPtr->getregB());
    hwPtr->setregB(temp);
    hwPtr->incprogC();
    std::cout << "Executed XCH!\n"; 
}

void LDI::execute(){
    //Load value to A
    if (isInRange(value)) {
        hwPtr->setregA(value);
    } else {
        std::cout << "Int is out of range in LDI!\n";
    }
    hwPtr->incprogC();
    std::cout << "Executed LDI!\n"; 
}

void ADD::execute(){
    //A = A+B
    long sum = hwPtr->getregA() + hwPtr->getregB();

    //overflow
    if (!isInRange(sum)) {
        hwPtr->setOverflowBit();
        hwPtr->setregA(sum - maxLim);
    } else {
        hwPtr->clearZeroResultBit();
        hwPtr->setregA(sum);
    }

    //zero result
    if (sum == 0) {hwPtr->setZeroResultBit();}
    else {hwPtr->clearZeroResultBit();}

    hwPtr->incprogC();
    std::cout << "Executed ADD!\n"; 
}

void DEC::execute(){
    //Declare Symbol
    hwPtr->addSymbol(symbol);
    hwPtr->incprogC();
    std::cout << "Executed DEC!\n"; 
}

void STR::execute(){
    //Store symbol
    std::string storageElement = std::to_string(hwPtr->getregA());
    hwPtr->setValOfSymbol(symbol, storageElement);
    hwPtr->incprogC();
    std::cout << "Executed STR!\n"; 
}

void LDA::execute(){
    //Load A
    long value = std::stol(hwPtr->getValOfSymbol(symbol));
    hwPtr->setregA(value);
    hwPtr->incprogC();
    std::cout << "Executed LDA!\n"; 
}

void LDB::execute(){
    //Load B
    long value = std::stol(hwPtr->getValOfSymbol(symbol));
    hwPtr->setregB(value);
    hwPtr->incprogC();
    std::cout << "Executed LDB!\n"; 
}

void JMP::execute(){
    //Jump to loc
    hwPtr->setprogC(loc);
    std::cout << "Executed JMP!\n"; 
}

void JZS::execute(){
    //Jump if zero
    if (hwPtr->getZeroResultBit()){hwPtr->setprogC(loc);}
    else {hwPtr->incprogC();}
    std::cout << "Executed JZS!\n"; 
}

void JVS::execute(){
    //Jump on overflow
    if (hwPtr->getOverflowBit()) {hwPtr->setprogC(loc);}
    else {hwPtr->incprogC();}
    std::cout << "Executed JVS!\n"; 
}

void HLT::execute(){
    //Halt
    hwPtr->setHalt();
    std::cout << "Executed HLT!\n"; 
}