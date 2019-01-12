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
          {
            uint16_t r0 = (instr >> 9) & 0x7; /* destination register (DR) */
            uint16_t r1 = (instr >> 6) & 0x7; /* first operand (SR1) */
            uint16_t imm_flag = (instr >> 5) & 0x1; /* immediate mode or register mode */
            if(imm_flag)
            {
              uint16_t imm5 = sign_extend(instr & 0x1F, 5); // Sign extend from 5 bits to 16 bits
              reg[r0] = reg[r1] + imm5;
            }
            else
            {
              uint16_t r2 = instr & 0x7;
              reg[r0] = reg[r1] + reg[r2];
            }
            update_flags(r0);
          }
          break;
        case OP_AND:
          {
            uint16_t r0 = (instr >> 9) & 0x7; /* destination register (DR) */
            uint16_t r1 = (instr >> 6) & 0x7; /* first operand (SR1) */
            uint16_t imm_flag = (instr >> 5) & 0x1; /* immediate mode or register mode */

            if(imm_flag)
            {
              uint16_t imm5 = sign_extend(instr & 0x1F, 5); // Sign extend from 5 bits to 16 bits
              reg[r0] = reg[r1] & imm5;
            }
            else
            {
              uint16_t r2 = instr & 0x7;
              reg[r0] = reg[r1] & reg[r2];
            }
            update_flags(r0);
          }
          break;
        case OP_NOT:
          {
            int16_t r0 = (instr >> 9) & 0x7; /* destination register (DR) */
            uint16_t r1 = (instr >> 6) & 0x7; /* operand (SR) */
            reg[r0] = ~reg[1];
            update_flags(r0);
          }
          break;
        case OP_BR:
          {
            uint16_t pcOffset = sign_extend((instr & 0x1FF), 9);
            uint16_t condFlag = (instr >> 9) & 0x7;
            if(condFlag & reg[R_COND])
            {
              reg[R_PC] += pcOffset;
            }
          }
          break;
        case OP_JMP:
          {
            uint16_t r1 = (instr >> 6) & 0x7;
            reg[R_PC] = reg[r1];
          }
          break;
        case OP_JSR:
          {
            uint16_t r1 = (instr >> 6) & 0x7;
            uint16_t longPCoffset = sign_extend((instr & 0x7FF), 11);
            uint16_t longFlag = (instr >> 11) & 1;
            reg[R_R7] = reg[R_PC];
            if(longFlag)
            {
              reg[R_PC] += longPCoffset; // JSR
            }
            else
            {
              reg[R_PC] = reg[r1]; // JSRR
            }
          }
          break;
        case OP_LD:
          {
            uint16_t r0 = (instr >> 9) & 0x7;
            uint16_t pcOffset = sign_extend((instr & 0x1FF), 9);
            reg[r0] = mem_read(reg[R_PC] + pcOffset);
            update_flag(r0);
          }
          break;
        case OP_LDI:

          break;
        case OP_LDR:

          break;
        case OP_LEA:

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
          abort();
          break;
      }
    }
}

uint16_t VMlc3::mem_read(uint16_t address)
{

  return -1;
}

uint16_t VMlc3::sign_extend(uint16_t x, int bit_count)
{
  if ((x >> (bit_count - 1)) & 1)
  {
    x |= (0xFFFF << bit_count);
  }
  return x;
}

void VMlc3::update_flag(uint16_t r)
{
  if(reg[r] == 0)
  {
    reg[R_COND] = FL_ZRO;
  }
  else if(reg[r]>>15)
  {
    reg[R_COND] = FL_NEG;
  }
  else
  {
    reg[R_COND] = FL_POS;
  }
}
