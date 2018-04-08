#ifndef __MODEL_HPP__
#define __MODEL_HPP__

#include "office.hpp"

#include <optional>
#include <string>

namespace model {

class Model {
 public:
  virtual int addOffice(Office::Key key, std::string name) = 0;
  virtual std::optional<Office> getOffice(Office::Key) const = 0;
};

};  // namespace model

#endif  //__MODEL_HPP__