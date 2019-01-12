#ifndef _HARDWARE_LC3_
#define _HARDWARE_LC3_

#include <iostream>
#include <string>
#include <cstdlib>

class VMlc3{
private:
  /*
    MEMORY
    65536 locations which stores a 16-bit value.
    This means it can store a total of only 128kb.
  */
  uint16_t memory[UINT16_MAX];
  /*
    REGISTERS
    8 general purpose registers (R0-R7)
    1 program counter (PC) register
    1 condition flags (COND) register
  */
  enum {
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC,
    R_COND,
    R_COUNT
  };
  /* Registers will be store in array */
  uint16_t reg[R_COUNT];
  /* CONDITION FLAGS */
  enum {
    FL_POS = 1 << 0,  // POSITICE - greater than zero
    FL_ZRO = 1 << 1,  // ZERO
    FL_NEG = 1 << 2  // NEGATIVE
  };
  /*
    INSTRUCTIONS SET
  */
  enum {
    OP_BR = 0,  // BRANCH
    OP_ADD,     // ADD
    OP_LD,      // LOAD - read data from memory to register, PC-relative mode
    OP_ST,      // STORE - write data from register to memory, PC-relative mode
    OP_JSR,     // JUMP REGISTER
    OP_AND,     // BITWISE AND
    OP_LDR,     // LOAD REGISTER - base + offset mode
    OP_STR,     // STORE REGISTER - base + offset mode
    OP_RTI,     // ************UNUSED************
    OP_NOT,     // BITWISE NOT
    OP_LDI,     // LOAD INDIRECT - indirect mode
    OP_STI,     // STORE INDIRECT - indirect mode
    OP_JMP,     // JUMP
    OP_RES,     // RESERVED (************UNUSED************)
    OP_LEA,     // LOAD EFFECTIVE ADDRESS - compute address, save in register
    OP_TRAP     // EXECUTE TRAP - call a service routine
  };

private:
  std::string fileToProc;

  uint16_t mem_read(uint16_t address);
  uint16_t sign_extend(uint16_t x, int bit_count);
  void update_flag(uint16_t r);

public:
    int main_vmlc3();

    VMlc3(int argc, char *argv[])
    {
      fileToProc = argv[argc-1];
    }

};
#endif
