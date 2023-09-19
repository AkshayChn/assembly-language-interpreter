#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <iostream>
#include "hardware.hpp"

class Instruction {
    public:
        std::string printString;
        std::string argValue;

        Hardware* hwPtr;

        //Pure virtual function
        virtual void execute()=0;

        //Concrete function Print
        void print(){
            std::cout << printString << " " << argValue << "\n";
        }

        long maxLim = 2147483647;
        long minLim = -2147483648;
        bool isInRange(long a){return a >= minLim && a <= maxLim;}
        
};
 
//Constructors for these classes are too trivial

//dummy instruction is just for testing and not actually used

class dummyInst: public Instruction {
    public:
        dummyInst(){
            printString = "DUMMY";
            argValue = "Nil";
        }

        void execute();
};

//the following are actual instrucitons according to spec
//constructors are trivial

class XCH: public Instruction {
    public:
        XCH(Hardware *hw){
            hwPtr = hw;
            printString = "XCH";
            argValue = "";
        }

        void execute();
};

class LDI: public Instruction {
    public:
        long value;

        LDI(Hardware *hw, long v){
            hwPtr = hw;
            printString = "LDI";
            argValue = std::to_string(v);
            value = v;
        }

        void execute();
};

class ADD: public Instruction {
    public:
        ADD(Hardware *hw){
            hwPtr = hw;
            printString = "ADD";
            argValue = "";
        }

        void execute();
};

class DEC: public Instruction {
    public:
        std::string symbol;
        DEC(Hardware *hw, std::string sym){
            hwPtr = hw;
            printString = "DEC";
            argValue = sym;
            symbol = sym;
        }

        void execute();
};

class STR: public Instruction {
    public:
        std::string symbol;
        STR(Hardware *hw, std::string sym){
            hwPtr = hw;
            printString = "STR";
            argValue = sym;
            symbol = sym;
        }

        void execute();
};

class LDA: public Instruction {
    public:
        std::string symbol;
        LDA(Hardware *hw, std::string sym){
            hwPtr = hw;
            printString = "LDA";
            argValue = sym;
            symbol = sym;
        }

        void execute();
};

class LDB: public Instruction {
    public:
        std::string symbol;
        LDB(Hardware *hw, std::string sym){
            hwPtr = hw;
            printString = "LDB";
            argValue = sym;
            symbol = sym;
        }

        void execute();
};

class JMP: public Instruction {
    public:
        int loc; 
        JMP(Hardware *hw, int i){
            hwPtr = hw;
            printString = "JMP";
            argValue = std::to_string(i);
            loc = i;
        }

        void execute();
};

class JZS: public Instruction {
    public:
        int loc; 
        JZS(Hardware *hw, int i){
            hwPtr = hw;
            printString = "JZS";
            argValue = std::to_string(i);
            loc = i;
        }

        void execute();
};

class JVS: public Instruction {
    public:
        int loc; 
        JVS(Hardware *hw, int i){
            hwPtr = hw;
            printString = "JVS";
            argValue = std::to_string(i);
            loc = i;
        }

        void execute();
};

class HLT: public Instruction {
    public:
        HLT(Hardware *hw){
            hwPtr = hw;
            printString = "HLT";
            argValue = "";
        }

        void execute();
};

#endif