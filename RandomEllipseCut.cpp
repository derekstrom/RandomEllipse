/*********************************************************************************/ 
/* File:   RandomEllipseCut.cpp                                                  */
/* Author: Derek Strom                                                           */
/* Date:   9/30/2015                                                             */
/* Type:   C++ File                                                              */
/* Desc:   Generate a uniform distribution of (x,y) values inside an ellipse.    */
/*********************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>

using namespace std;

// The ellipse is centered at the origin (0,0).
// The Equation of an ellipse in cartesian coordinates is: (x/a)^2 + (y/b)^2 = 1.

int main() {

  double a = 2.0;   //semi-major axis
  double b = 3.0;   //semi-minor axis
  double rand_x;         //x coordinate
  double rand_y;         //y coordinate
  
  const int npoints = 20E6 * 64 / (6 * M_PI); //Number of points

  //Warm up the engine
  std::random_device rd; 
  std::default_random_engine e(rd()); //Obtain a seed from an object of type random_device
  std::uniform_real_distribution<> dx(0, 1); //A uniform distribution of real values between 0 and 1
  std::uniform_real_distribution<> dy(0, 1); //A uniform distribution of real values between 0 and 1
  std::uniform_real_distribution<> dsignx(0, 1); //A uniform distribution of real values between 0 and 1
  std::uniform_real_distribution<> dsigny(0, 1); //A uniform distribution of real values between 0 and 1

  //Loop over npoints, generate random x, y, sign x, sign y
  for(int i=0; i<npoints; ++i){

    int signx;
    int signy;

    (dsignx(e) < 0.5) ? signx = 1.0 : signx = -1.0;
    (dsigny(e) < 0.5) ? signy = 1.0 : signy = -1.0;
    double rand_x = signx * dx(e) * 4.0; //Generate a random x value between -4 and 4
    double rand_y = signy * dy(e) * 4.0; //Generate a random y value between -4 and 4


    //Test that point (x,y) satisfies the equation (x/a)^2 + (y/b)^2 <= 1 and print the values if successful.
    if ( (((rand_x / a) * (rand_x / a)) + ((rand_y / b) * (rand_y / b))) <= 1 ){
    
      //Print x and y
      cout << std::fixed;
      cout << setw(8) << right << setprecision(4) << rand_x << "\t" << setw(8) << right << setprecision(4) << rand_y << endl;
	
      }
  }
  
  return 0;
}

//The End.
