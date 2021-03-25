/* Copyright 2018 */
#include "dollar.h"

const Dollar Dollar::ToDollar(double val) {
  int dollars = static_cast<int>(val);
  double cents = 100.0*(val - dollars);

  return Dollar(dollars, cents);
}

Dollar::Dollar(double cents) {
  dollars_ = 0;
  cents_ = cents;
}

Dollar::Dollar(int dollars, double cents) 
    : dollars_(dollars), cents_(cents) {
  if (100.0 <= cents_) { 
    int temp = static_cast<int>(cents)/100;
    dollars_ += temp;
    cents_ -= 100*temp;
  }
}

const Dollar Dollar::Add(const Dollar& rhs) const {
  Dollar sum;
  sum.dollars_ = dollars_ + rhs.dollars_;
  sum.cents_ = cents_ + rhs.cents_;
  
  if (sum.cents_ >= 100.0) {
    sum.cents_ -= 100.00;
    ++sum.dollars_;
  }

  return sum;
}

const Dollar Dollar::operator+(const Dollar& rhs) const {
  return Add(rhs);
}

const Dollar Dollar::operator+(double rhs) const {
  Dollar d = Dollar::ToDollar(rhs);
  Dollar sum = Add(d);
  return sum;
}

const string Dollar::ToString() const {
  stringstream sout;

  sout << "$";
 
  int cents = static_cast<int>(round(cents_));
  if (100 <= cents) {
    sout << (dollars_ + 1);
    cents -= 100;
  } else
    sout << dollars_;

  sout << '.';

  if (10 > cents)
    sout << 0;
  sout << cents;

  return sout.str();
}

ostream& Dollar::Extract(ostream& out) const {
  int cents = static_cast<int>(round(cents_));

  out << '$';
  if (cents == 100) {
    out << (dollars_ + 1);
    cents = 0;
  } else
    out << dollars_;
  out << '.';

  if (10 > cents)
    out << 0;

  out << cents;

  return out;
}

istream& Dollar::Insert(istream& in) {
  double val;
  in >> val;

  dollars_ = static_cast<int>(val);
  cents_ = 100.0*(val - dollars_);

  return in;
}

ostream& operator<<(ostream& out, const Dollar& rhs) {
  return rhs.Extract(out);
}

istream& operator>>(istream& in, Dollar& rhs) {
  return rhs.Insert(in);
}

const Dollar operator+(double lhs, const Dollar& rhs) {
  return rhs + lhs;
}

bool CompDollars::operator()(const Dollar& lhs, const Dollar& rhs) const {
  if (lhs.dollars() < rhs.dollars())
    return true;
  else if (lhs.dollars() == rhs.dollars())
    return lhs.cents() < rhs.cents();
  else
    return false;
}

