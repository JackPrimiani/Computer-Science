/*
Copyright 2018
Author: Jack Primiani
September 24th, 2018
*/

#include "comp_geo.h"
#include <cmath>

// Function takes two XY coordinates at the center & at the edge of a circle
// Returns the circumference
double GetCircumference(double Xc, double Yc, double Xe, double Ye) {
  double rad = GetDistance(Xc, Yc, Xe, Ye);
  double cir = 2*M_PI*rad;
  return cir;
}

// Function takes two XY coordinates at the lower left & upper right corner
// Returns the perimeter
double GetPerimeter(double Xll, double Yll, double Xur, double Yur) {
  double Xd = GetDistance(Xll, 0, Xur, 0);
  double Yd = GetDistance(0, Yll, 0, Yur);
  double per =  2*(Xd+Yd);
  return per;
}

// Function takes two XY coordinates at the center of & at the edge of a circle
// Returns the area
double GetVolume(double Xc, double Yc, double Xe, double Ye) {
  double rad = GetDistance(Xc, Yc, Xe, Ye);
  rad*= rad;
  double cir = M_PI*rad;
  return cir;
}

// Function takes two points
// Returns the distance squared
double GetDistanceSquared(double Xa, double Ya, double Xb, double Yb) {
  double dist = GetDistance(Xa, Ya, Xb, Yb);
  dist *= dist;
  return dist;
}

// Function takes two points
// Returns the distance between the both of them
double GetDistance(double Xa, double Ya, double Xb, double Yb) {
  double x = Xb-Xa;
  double y = Yb-Ya;
  double dist;
  x*=x;
  y*=y;
  dist = sqrt(x+y);
  return dist;
}
