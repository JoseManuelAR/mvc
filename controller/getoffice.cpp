#include "getoffice.hpp"

#include <iostream>

namespace controller {

GetOffice::GetOffice(std::string name) : Controller{std::move(name)} {
  std::cout << "GetOffice" << std::endl;
}

void GetOffice::subscribe(const std::shared_ptr<view::View>& view) {
  view->subscribe(event::Event::getOffice, shared_from_this());
}

}  // namespace controller
