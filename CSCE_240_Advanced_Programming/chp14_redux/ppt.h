/* copyright 2018 */
#ifndef _LECT_CHP14_PPT_H_  //NOLINT  
#define _LECT_CHP14_PPT_H_  //NOLINT

#include <iostream>

namespace csce240 {

class PPT {
 public:
  virtual ~PPT() { }
  virtual void Push(int) = 0;
  virtual int Pop() = 0;
  virtual int Top() const = 0;
  virtual bool Empty() const = 0;

  virtual std::ostream& Extract(std::ostream&) const = 0;
};

std::ostream& operator<<(std::ostream&, const PPT&);

}  // namespace csce240
#endif  //NOLINT
