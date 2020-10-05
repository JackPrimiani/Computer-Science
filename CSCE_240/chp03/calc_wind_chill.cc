/* calc_wind_chill Copyright 2018
 *
 * Wind chill is defined as
 * w = 33 - [(10(v)^0.5 - v + 10.5)(33 - t)]/23.1
 * Where v is wind speed in m/sec,
 * t is temp in Celsius, s.t. t <= 10.0.
 *
 * Write a function with id GetWindChill. It should accept two double
 * parameters vel and temp and return a double value representing the wind
 * chill. When temp is greater than 10.0, return temp.
 */
#include <cmath>
// using sqrt
using std::cout;
using std::endl;


double GetWindChill(double vel, double temp) {
  double w = 33 - ((10*(vel)^0.5 -vel + 10.5)
             * (33 - temp));
  w/= 23.1;

  return w;
}   

int main(int argc, char* argv[]){


  return 0;
}
