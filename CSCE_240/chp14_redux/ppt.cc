/* copyright 2018 */
#include "../chp14/ppt.h"  //NOLINT

namespace csce240 {
std::ostream& operator<<(std::ostream& lhs, const PPT& rhs) {
  return rhs.Extract(lhs);
}
}  // namespace csce240
