#ifndef __VIEW_HPP__
#define __VIEW_HPP__

#include "event/event.hpp"

#include <iostream>
#include <map>
#include <memory>
#include <vector>

namespace controller {
class Controller;
};

namespace view {

class View {
 public:
  View(std::string name) : name{std::move(name)} {};
  virtual ~View() = default;

  virtual void load() = 0;

  void subscribe(event::Event event,
                 std::shared_ptr<controller::Controller> controller);

 protected:
  std::string name;
  std::map<event::Event, std::vector<std::shared_ptr<controller::Controller>>>
      controllers;
};

};  // namespace view

#endif  //__VIEW_HPP__