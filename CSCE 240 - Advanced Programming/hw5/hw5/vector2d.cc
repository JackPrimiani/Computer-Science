/*
copyright 2018
Author: Jack Primiani
November 12th, 2018
*/

#include "vector2d.h" //NOLINT

const Vector2d Vector2d::operator+(const Vector2d& rhs) const {
  Vector2d Vadd(x_ + rhs.x_, y_ + rhs.y_);
  return Vadd;
}
const Vector2d Vector2d::operator-(const Vector2d& rhs) const {
  Vector2d Vsub(x_ - rhs.x_, y_ - rhs.y_);
  return Vsub;
}
const Vector2d Vector2d::operator-() const {
  Vector2d Vrev(x_ * -1, y_ * -1);
  return Vrev;
}
const Vector2d Vector2d::operator*(double scalar) const {
  Vector2d Vscale(x_ * scalar, y_ * scalar);
  return Vscale;
}
bool Vector2d::operator==(const Vector2d& rhs) const {
  bool equ;
  if (x_ == rhs.x_ && y_ == rhs.y_) {
    equ = true;
  } else {
    equ = false;
  }
  return equ;
}
bool Vector2d::operator!=(const Vector2d& rhs) const {
  bool equ;
  if (x_ == rhs.x_ && y_ == rhs.y_) {
    equ = true;
  } else {
    equ = false;
  }
  return !(equ);
}
ostream& Vector2d::Extract(ostream& out) const {
  out << "(" << x_ << ", " << y_ << ")";
  return out;
}
istream& Vector2d::Insert(istream& in) {
  in >> x_ >> y_;
  return in;
}
Vector2d operator*(double lhs, Vector2d rhs) {
  Vector2d Vscale(rhs.x() * lhs, rhs.y() * lhs);
  return Vscale;
}

ostream& operator<<(ostream& lhs, const Vector2d rhs) {
  return rhs.Extract(lhs);
}

istream& operator>>(istream& lhs, Vector2d& rhs) {
  return rhs.Insert(lhs);
}

bool CompareMagnitude::operator()(Vector2d lhs, Vector2d rhs) {
  bool ret;
  double x = 0-lhs.x();
  double y = 0-lhs.y();
  double dist1, dist2;
  x*=x;
  y*=y;
  dist1 = sqrt(x+y);
  x = 0-rhs.x();
  y = 0-rhs.y();
  x*=x;
  y*=y;
  dist2 = sqrt(x+y);
  return (dist1 < dist2);
}
bool CompareDirection::operator()(Vector2d lhs, Vector2d rhs) {
  double val1, val2;
  if (lhs.y() == 0 && lhs.x() == 0) {
    val1 = atan2(lhs.y(), lhs.x());
    val1 += M_PI;
  } else if (lhs.y() == 0 && lhs.x() != 0) {
    if (lhs.x() < 0) {
      val1 = M_PI;
    }
    if (lhs.x() > 0) {
      val1 = 0;
    }
  } else if (lhs.y() != 0 && lhs.x() == 0) {
    if (lhs.y() < 0) {
      val1 = (3*M_PI)/2;
    }
    if (lhs.y() > 0) {
      val1 = M_PI/2;
    }
  } else if (lhs.y() == 0 && lhs.x() == 0) {
      return false;
  }
  if (lhs.y() == 0 && lhs.x() == 0) {
    val2 = atan2(rhs.y(), rhs.x());
    val2+= M_PI;
  } else if (rhs.y() == 0 && rhs.x() != 0) {
    if (rhs.x() < 0) {
      val2 = M_PI;
    }
    if (rhs.x() > 0) {
      val2 = 0;
    }
  } else if (rhs.y() != 0 && rhs.x() == 0) {
    if (rhs.y() < 0) {
      val2 = (3*M_PI)/2;
    }
    if (rhs.y() > 0) {
      val2 = M_PI/2;
    }
  } else if (rhs.y() == 0 && rhs.x() == 0) {
      return true;
  }
  val1 = (val1 * 180)/M_PI;
  val2 = (val2 * 180)/M_PI;
  return val1 < val2;
}
