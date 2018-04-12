#ifndef __APP_HPP__
#define __APP_HPP__

#include <memory>
#include <vector>

namespace view {
class View;
};

namespace model {
class Model;
};

namespace controller {
class Controller;
};

class App {
 public:
  explicit App(std::shared_ptr<view::View> mainView,
               std::shared_ptr<model::Model> model);

  void run();

  void addController(std::shared_ptr<controller::Controller> controller);

 private:
  std::shared_ptr<view::View> mainView;
  std::shared_ptr<model::Model> model;
};

#endif  //__APP_HPP__