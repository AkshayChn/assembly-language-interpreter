#ifndef ALI_H
#define ALI_H

#include "instruction.hpp"

class ALI {
    public:
    Hardware *hw = new Hardware();
    std::string nameOfFile;

    //constructor
    ALI();
    
    void setNameOfFIle();
    void printHelpText();
    void parseFile();
    void parseLine(std::string st);
    void printAllInstructions();
    void printAllRegs();
    void printDataMem();

    void executeAllInstructions();
    void executeSingleInstruction();

    void commandLoop();
    
};

#endif