#ifndef __RESTLISTENER_HPP__
#define __RESTLISTENER_HPP__

#include "event/event.hpp"

#include <nghttp2/asio_http2_server.h>

using namespace nghttp2::asio_http2;
using namespace nghttp2::asio_http2::server;

namespace view {
namespace rest {

struct RequestHandler {
  std::string pattern;
  std::function<void(const request &, const response &)> callback;
};

class RestListener {
 public:
  RestListener(std::string address, std::string port);

  void listen();
  void addHandler(RequestHandler handler) { handlers.emplace_back(handler); }

 private:
  std::string address;
  std::string port;
  http2 server;
  std::vector<RequestHandler> handlers;
};

};  // namespace rest
};  // namespace view

#endif  //__RESTLISTENER_HPP__