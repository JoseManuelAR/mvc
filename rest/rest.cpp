#include "rest.hpp"
#include "controller/controller.hpp"
#include "event/eventdata.hpp"
#include "http-parser/http_parser.h"

#include <iostream>
#include <memory>

namespace view {
namespace rest {

Rest::Rest(std::string name, std::string address, std::string port)
    : View{std::move(name)}, listener{std::move(address), std::move(port)} {};

void Rest::load() {
  std::cout << "loading rest view " << std::endl;

  listener.addHandler(
      {"/offices", std::bind(&Rest::getOffices, this, std::placeholders::_1,
                             std::placeholders::_2, event::Event::getOffices)});
  listener.addHandler(
      {"/office/", std::bind(&Rest::getOffice, this, std::placeholders::_1,
                             std::placeholders::_2, event::Event::getOffice)});
  listener.listen();
}

void Rest::getOffices(const request& req, const response& res,
                      event::Event ev) {
  std::cout << "handling getOffices " << static_cast<std::uint32_t>(ev)
            << controllers[ev].size() << std::endl;

  for (auto controller : controllers[ev]) {
    controller->notify(ev, std::make_shared<event::EventDataGetOffices>());
  }
  /*auto& io_service = res.io_service();
  auto restofficesMessage =
      std::make_shared<RestOfficesMessage>(io_service, req, res);
  inQueue->push(restofficesMessage);

  std::cout << "new inQueue size: " << inQueue->size() << std::endl;*/
}

void Rest::getOffice(const request& req, const response& res, event::Event ev) {
  std::cout << "handling getOffice " << static_cast<std::uint32_t>(ev)
            << controllers[ev].size() << std::endl;

  std::size_t found = req.uri().path.find_last_of("/");
  std::string file = req.uri().path.substr(found + 1);

  for (auto controller : controllers[ev]) {
    controller->notify(ev, std::make_shared<event::EventDataGetOffice>(file));
  }

  /*auto& io_service = res.io_service();
  auto restofficeMessage =
      std::make_shared<RestOfficeMessage>(io_service, req, res);
  inQueue->push(restofficeMessage);

  std::cout << "new inQueue size: " << inQueue->size() << std::endl;*/
}

}  // namespace rest
}  // namespace view
