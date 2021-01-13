/* copyright 2018 */
#ifndef _LECT_CHP11_2_PPT_H_  //NOLINT  
#define _LECT_CHP11_2_PPT_H_  //NOLINT

#include <iostream>

namespace csce240 {

class PPT {
 public:
  virtual void Push(int) = 0;
  virtual int Pop() = 0;
  virtual int Top() const = 0;
  virtual bool Empty() const = 0;

};


}  // namespace csce240
#endif  //NOLINT
