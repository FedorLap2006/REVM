#include <stdio.h>
#include <inttypes.h>

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

uint16_t reg[R_COUNT];

/*
  INSTRUCTIONS SET
*/

int main() {

  return 0;
}
