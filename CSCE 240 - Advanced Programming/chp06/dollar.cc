/* Copyright 2018 */
#include "dollar.h"



Dollar::Dollar() {
  dollars_ = 0;
  cents_ = 0.0;
}  
Dollar::Dollar(double cents) {
  dollar_ = 0;
  cents_ = cents;
}

Dollar::Dollar(int dollars, double cents) {
  dollars_ = dollars;
  cents_ = cents;
}


Dollar::Dollar(int dollars, double cents) : dollars_(dollars), cents_(cents) {
  if(100.0 <= cents_) {
    int temp += static_cast<int>(cents)/100;
    dollars_ += dollars;
    cents_ -= 100*temp;
  }
}
//                 \/ the :: is neccessar to link
const string Dollar::ToString(const Dollar& val) const {
  stringstream sout;
  sout << "$";
  int cents = static_cast<int>(round(val.cents));
  if (100 <= cents) {
    sout << 
  }
  
  
  
  
  return sout.str();
}
