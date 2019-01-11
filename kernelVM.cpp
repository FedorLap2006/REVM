#include <cstdio>
#include <cinttypes>
#include <iostream>

#include "hardwareLC3.hpp"

int main(int argc, const char *argv[])
{
  /*
  argc - 3
  argv - kernelVM machine_type file_name_to_execute
  */
  if(argc < 3){
    std::cout << "Few args!" << std::endl;
    std::cout << "./kernelVM.vexe [machine type] [program] ..." << std::endl;
    return -1;
  }

  VMlc3 machine = new VMlc3(argc-2, argv+2);
  machine.main_vmlc3();

  return 0;
}
