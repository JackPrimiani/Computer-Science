/*
Copyright 2018
Author: Jack Primiani
September 24th, 2018
*/

#ifndef _HW2_COMP_GEO_H_
#define _HW2_COMP_GEO_H_

// Function takes two XY coordinates at the center & at the edge of a circle
// Returns the circumference
double GetCircumference(double, double, double, double);

// Function takes two XY coordinates at the lower left & upper right corner
// Returns the perimeter
double GetPerimeter(double, double, double, double);

// Function takes two XY coordinates at the center & at the edge of a circle
// Returns the area
double GetVolume(double, double, double, double);

// Function takes two points
// Returns the distance squared
double GetDistanceSquared(double, double, double, double);

// Function takes two points
// Returns the distance between the both of them
double GetDistance(double, double, double, double);

#endif
