#include "getoffices.hpp"

#include <iostream>

namespace controller {

GetOffices::GetOffices(std::string name) : Controller{std::move(name)} {
  std::cout << "GetOffices" << std::endl;
}

void GetOffices::subscribe(const std::shared_ptr<view::View>& view) {
  view->subscribe(event::Event::getOffices, shared_from_this());
}

}  // namespace controller
