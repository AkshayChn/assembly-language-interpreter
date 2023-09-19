## Project 4

This is a Assembly Language Interpreter (ALI) for a Simple AssemblyLanguage (SAL). SAL's instruction set is specified in the table below.

Instruction | Explanation | 
DEC symbol  | Declares a symbolic variable consisting of alphabetical characters (e.g., abc). The variable is stored at an available location in data memory.
LDA symbol  | Loads 32-bit word at data memory address of symbol into the accumulator. 
LDB symbol  |  Loads 32-bit word at data memory address symbol into B.
LDI value   | Loads the integer value into the accumulator register. The value could be negative.
STR symbol  | Stores content of accumulator into data memory at address of symbol.
XCH         | Exchanges the content registers A and B.
JMP number  | Transfers control to instruction at address number in program memory.
JZS number  | Transfers control to instruction at address number if the zero-result bit is set.
JVS number  | Transfers control to instruction at address number if the overflow bit is set.
ADD         | Adds the content of registers A and B. The sum is stored in A. The overflow and zero-result bits are set or cleared as needed.
HLT         | Terminates program execution.


Note:
- `main()` is in the ali.cpp file.
- All instructions stored into the memory are printed in the beginning after parsing the file.

How to compile:
- Run `make`

How to run:
- Run the program with `./output`
- Enter the name of the file containing the SAL source.
- Use the command loop.
