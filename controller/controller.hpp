#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include "event/eventdata.hpp"
#include "model/model.hpp"
#include "view/view.hpp"

#include <memory>

namespace controller {

class Controller : public std::enable_shared_from_this<Controller> {
 public:
  Controller(std::string name) : name{std::move(name)}, model{} {};

  const std::string& getName() const { return name; }

  virtual void subscribe(const std::shared_ptr<view::View>& view) = 0;

  void notify(event::Event event, std::shared_ptr<event::EventData> eventData) {
    std::cout << "receiving event " << static_cast<std::uint32_t>(event)
              << std::endl;
    eventData->accept(shared_from_this());
  }

  void linkToModel(std::shared_ptr<model::Model> model) {
    this->model = model;
    model->linkToController(shared_from_this());
  }

  virtual void visit(std::shared_ptr<event::EventDataGetOffice> eventData){};
  virtual void visit(std::shared_ptr<event::EventDataGetOffices> eventData){};

 private:
  std::string name;
  std::shared_ptr<model::Model> model;
};

};  // namespace controller

#endif  //__CONTROLLER_HPP__