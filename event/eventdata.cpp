#include "eventdata.hpp"
#include "controller/controller.hpp"

namespace event {

void EventDataGetOffice::accept(
    std::shared_ptr<controller::Controller> controller) {
  controller->visit(shared_from_this());
}

void EventDataGetOffices::accept(
    std::shared_ptr<controller::Controller> controller) {
  controller->visit(shared_from_this());
}

};  // namespace event
