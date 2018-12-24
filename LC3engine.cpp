#include "hardwareLC3.hpp"

int VMlc3::main_vmlc3()
{
    /* Set the PC to starting position */
    enum {
      PC_START = 0x3000
    };
    reg[R_PC] = PC_START;

    bool vmRunning = true;
    while(vmRunning)
    {
      uint16_t instr = mem_read(reg[R_PC]);
      uint16_t op = instr >> 12;

      ++reg[R_PC];
      switch (op) {
        case OP_ADD:

          break;
        case OP_AND:

          break;
        case OP_NOT:

          break;
        case OP_BR:

          break;
        case OP_JMP:

          break;
        case OP_JSR:

          break;
        case OP_LD:

          break;
        case OP_LDI:

          break;
        case OP_LDR:

          break;
        case OP_ST:

          break;
        case OP_STI:

          break;
        case OP_STR:

          break;
        case OP_TRAP:

          break;
        case OP_RES:
        case OP_RTI:
        default:

          break;
      }
    }
}
