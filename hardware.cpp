#include "hardware.hpp"
#include <iostream>

//constructor
Hardware::Hardware(){
    //Regs
    regA = 0;
    regB = 0;
    progC = 0;

    //Flags
    zeroResultBit = 0;
    overflowBit = 0;

    //other pointers
    dataMemSize = 0;
    instMemSize = 0;

    halt = 0;
}


