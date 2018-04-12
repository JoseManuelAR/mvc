#ifndef __MEMORY_HPP__
#define __MEMORY_HPP__

#include "model.hpp"

#include <vector>

namespace model {

class Memory : public Model {
 public:
  Memory(std::string name);

  virtual int addOffice(Office::Key key, std::string name) override;
  virtual std::optional<Office> getOffice(Office::Key) const override;

 private:
  std::vector<Office> offices;
};

};  // namespace model

#endif  //__MEMORY_HPP__