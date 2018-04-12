#ifndef __EVENTDATA_HPP__
#define __EVENTDATA_HPP__

#include <memory>
#include <string>

namespace controller {
class Controller;
};
namespace event {

class EventData {
 public:
  virtual void accept(std::shared_ptr<controller::Controller> controller) = 0;
};

class EventDataGetOffice
    : public std::enable_shared_from_this<EventDataGetOffice>,
      public EventData {
 public:
  explicit EventDataGetOffice(std::string id) : id{id} {};

  const std::string& getId() const { return id; }

  virtual void accept(
      std::shared_ptr<controller::Controller> controller) override;

 private:
  std::string id;
};

class EventDataGetOffices
    : public std::enable_shared_from_this<EventDataGetOffices>,
      public EventData {
 public:
  explicit EventDataGetOffices(){};

  virtual void accept(
      std::shared_ptr<controller::Controller> controller) override;

 private:
};

};      // namespace event
#endif  //__EVENTDATA_HPP__