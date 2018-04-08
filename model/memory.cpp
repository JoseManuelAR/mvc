#include "memory.hpp"

#include <iostream>

model::Memory::Memory() { std::cout << "Memory" << std::endl; }

int model::Memory::addOffice(Office::Key key, std::string name) {
  std::cout << "addOffice" << std::endl;

  offices.emplace_back(Office(key, name));
}

std::optional<model::Office> model::Memory::getOffice(
    model::Office::Key key) const {
  std::cout << "getOffice" << std::endl;
  for (auto office : offices) {
    if (office == key) {
      return office;
    }
  }
  return std::nullopt;
}
