#include "restlistener.hpp"

#include <iostream>
#include <thread>

namespace view {
namespace rest {

RestListener::RestListener(std::string address, std::string port)
    : address{std::move(address)}, port{std::move(port)} {};

void RestListener::listen() {
  std::cout << "[" << std::this_thread::get_id() << "] listening at " << address
            << ":" << port << std::endl;

  for (auto h : handlers) {
    server.handle(h.pattern, h.callback);
  }
  boost::system::error_code ec;
  if (server.listen_and_serve(ec, address, port)) {
    std::cerr << "error: " << ec.message() << std::endl;
  }
};

}  // namespace rest
}  // namespace view