#ifndef __REST_HPP__
#define __REST_HPP__

#include "restlistener.hpp"
#include "view/view.hpp"

#include <boost/di.hpp>

namespace di = boost::di;

namespace view {
namespace rest {

auto ViewName = [] {};
auto ListenerAddress = [] {};
auto ListenerPort = [] {};

class Rest : public view::View {
 public:
  BOOST_DI_INJECT(Rest, (named = ViewName) std::string name,
                  (named = ListenerAddress) std::string address,
                  (named = ListenerPort) std::string port);
  virtual void load() override;

 private:
  RestListener listener;

  void getOffices(const request &, const response &, event::Event);
  void getOffice(const request &, const response &, event::Event);
};

};  // namespace rest
};  // namespace view

#endif  //__REST_HPP__