#ifndef __GETOFFICE_HPP__
#define __GETOFFICE_HPP__

#include "controller.hpp"

#include <boost/di.hpp>

namespace di = boost::di;

namespace controller {

auto GetOfficeName = [] {};

class GetOffice : public Controller {
 public:
  BOOST_DI_INJECT(GetOffice, (named = GetOfficeName) std::string name);

  virtual void subscribe(const std::shared_ptr<view::View>& view) override;

  virtual void visit(
      std::shared_ptr<event::EventDataGetOffice> eventData) override {
    std::cout << "receiving event getoffices with id: " << eventData->getId()
              << std::endl;
  }

 private:
};

};  // namespace controller

#endif  //__GETOFFICE_HPP__