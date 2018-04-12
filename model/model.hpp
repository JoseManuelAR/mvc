#ifndef __MODEL_HPP__
#define __MODEL_HPP__

#include "office.hpp"

#include <memory>
#include <optional>
#include <string>

namespace controller {
class Controller;
};

namespace model {

class Model {
 public:
  Model(std::string name) : name{std::move(name)}, controller{} {};

  virtual int addOffice(Office::Key key, std::string name) = 0;
  virtual std::optional<Office> getOffice(Office::Key) const = 0;

  void linkToController(std::shared_ptr<controller::Controller> controller) {
    this->controller = controller;
  }

 private:
  std::string name;
  std::shared_ptr<controller::Controller> controller;
};

};  // namespace model

#endif  //__MODEL_HPP__