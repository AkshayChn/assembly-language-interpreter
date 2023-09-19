#ifndef HARDWARE_H
#define HARDWARE_H

#include <string>
#include <map>

//forward declaration
class Instruction;

//Symbol table is a map
typedef std::map<std::string, int> SymbolTable;

class Hardware {
    public:
        //Memory
        Instruction *instMem[128];
        std::string dataMem[128];

        //Registers
        long regA;
        long regB;

        //Program counter
        long progC;

        //Flags
        bool zeroResultBit;
        bool overflowBit;
        
        //constructor
        Hardware();

        //symbol table
        SymbolTable symT;
        int dataMemSize;

        int instMemSize;
        
        bool halt; //to indicate hardware halt

        // trivial getters and setters and other methods
        void addSymbol(std::string sym) {symT[sym] = dataMemSize; dataMemSize++;}
        void setValOfSymbol(std::string sym, std::string val){dataMem[symT[sym]] = val;}
        std::string getValOfSymbol(std::string sym){return dataMem[symT[sym]];}

        long getregA(){return regA;}
        void setregA(long s){regA = s;}

        long getregB(){return regB;}
        void setregB(long s){regB = s;}

        long getprogC(){return progC;}
        void setprogC(long s){progC = s;}
        void incprogC(){if (progC < 127) progC++;}

        bool getZeroResultBit(){return zeroResultBit;}
        void setZeroResultBit(){zeroResultBit = 1;}
        void clearZeroResultBit(){zeroResultBit = 0;}

        bool getOverflowBit(){return overflowBit;}
        void setOverflowBit(){overflowBit = 1;}
        void clearOverflowBit(){overflowBit = 0;}
        
        void addInstToMem(Instruction* ip){instMem[instMemSize] = ip; instMemSize++;}

        bool getHalt(){return halt;}
        void setHalt(){halt = 1;}
};

#endif