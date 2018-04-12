#include "memory.hpp"

#include <iostream>

namespace model {

Memory::Memory(std::string name) : Model{std::move(name)} {};

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

};  // namespace model
