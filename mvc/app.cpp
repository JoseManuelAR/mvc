#include "app.hpp"
#include "controller/controller.hpp"
#include "view/view.hpp"

App::App(std::shared_ptr<view::View> mainView,
         std::shared_ptr<model::Model> model)
    : mainView{mainView}, model{model} {}

void App::addController(std::shared_ptr<controller::Controller> controller) {
  controller->subscribe(mainView);
  controller->linkToModel(model);
}

void App::run() {
  std::cout << "running app" << std::endl;
  mainView->load();
}