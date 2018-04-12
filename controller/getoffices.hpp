#ifndef __GETOFFICES_HPP__
#define __GETOFFICES_HPP__

#include "controller.hpp"

#include <boost/di.hpp>

namespace di = boost::di;

namespace controller {

auto GetOfficesName = [] {};

class GetOffices : public Controller {
 public:
  BOOST_DI_INJECT(GetOffices, (named = GetOfficesName) std::string name);

  virtual void subscribe(const std::shared_ptr<view::View>& view) override;

  virtual void visit(
      std::shared_ptr<event::EventDataGetOffices> eventData) override {
    std::cout << "receiving event getoffices" << std::endl;
  }

 private:
};

};  // namespace controller

#endif  //__GETOFFICES_HPP__