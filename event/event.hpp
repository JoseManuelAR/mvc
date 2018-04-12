#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include <cstdint>

namespace event {

enum class Event : std::uint32_t { getOffices = 0, getOffice = 1 };

};  // namespace event

#endif  //__EVENT_HPP__