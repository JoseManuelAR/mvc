#include "view.hpp"
#include "controller/controller.hpp"

namespace view {

void View::subscribe(event::Event event,
                     std::shared_ptr<controller::Controller> controller) {
  controllers[event].push_back(controller);
  std::cout << name << " view subscribed controller: " << controller->getName()
            << " to " << static_cast<std::uint32_t>(event) << std::endl;
}

}  // namespace view