#include <cstdio>
#include <cinttypes>

#include "hardwareLC3.hpp"

int main(int argc, const char *argv[])
{
  VMlc3 machine = new VMlc3();

  machine.main_vmlc3();

  return 0;
}
