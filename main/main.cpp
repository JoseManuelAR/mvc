#include "model/memory.hpp"

#include <iostream>

main(int argc, char **argv) {
  model::Memory memoryModel;

  memoryModel.addOffice(1, "office1");
  auto office = memoryModel.getOffice(1);
  if (office) {
    std::cout << "Office found!" << std::endl;
  }
  return 0;
}