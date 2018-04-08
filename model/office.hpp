#ifndef __OFFICE_HPP__
#define __OFFICE_HPP__

#include <string>
#include <vector>

namespace model {

class Office {
 public:
  using Key = int;

  Office() = delete;
  Office(Key key, std::string name) : key(key), name(name){};

  bool operator==(const Key& key) const { return this->key == key; }

 private:
  Key key;
  std::string name;
};

};  // namespace model

#endif  //__OFFICE_HPP__