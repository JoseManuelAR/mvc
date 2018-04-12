#include "app.hpp"
#include "controller/getoffice.hpp"
#include "controller/getoffices.hpp"
#include "model/memory.hpp"
#include "rest/rest.hpp"

#include <boost/di.hpp>

namespace di = boost::di;

main(int argc, char **argv) {
  auto injector = di::make_injector(
      di::bind<std::string>.named(controller::GetOfficeName).to("getOffice"),
      di::bind<std::string>.named(controller::GetOfficesName).to("getOffices"),
      di::bind<std::string>.named(view::rest::ViewName).to("restView"),
      di::bind<std::string>.named(view::rest::ListenerAddress).to("127.0.0.1"),
      di::bind<std::string>.named(view::rest::ListenerPort).to("3000"),
      di::bind<model::Model>.to<model::Memory>(),
      di::bind<view::View>.to<view::rest::Rest>());

  auto getOffice = injector.create<std::shared_ptr<controller::GetOffice>>();
  auto getOffices = injector.create<std::shared_ptr<controller::GetOffices>>();
  auto app = injector.create<App>();

  app.addController(getOffice);
  app.addController(getOffices);
  app.run();
  return 0;
}