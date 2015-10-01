/*********************************************************************************/ 
/* File:   RandomEllipseTheta.cpp                                                */
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
// x and y may be written as a function of angle theta as follows:
// 
// x = a * cos(theta)
// y = b * sin(theta)
//
// where theta extends from 0 to 2*Pi from the positive x-axis.


int main() {

  double a = 2.0;   //semi-major axis
  double b = 3.0;   //semi-minor axis
  double x;         //x coordinate
  double y;         //y coordinate
  
  const int npoints = 20E6; //Number of points

  //Warm up the engine
  std::random_device rd; 
  std::default_random_engine e(rd()); //Obtain a seed from an object of type random_device
  std::uniform_real_distribution<> d(0.0, 1.0); //A uniform distribution of real values between 0 and 1
  std::uniform_real_distribution<> d1(0.0, 1.0); //A uniform distribution of real values between 0 and 1

  //Loop over npoints, generate random theta angle and scale factor, and compute x and y
  for(int i=0; i<npoints; ++i){
    
    double rand_theta = d(e) * 2 * M_PI; //Generate a random angle theta between 0 and 2*Pi
    double rand_scale = d1(e); //Generate a random scale factor between 0 and 1

    //Compute x and y
    x = a * cos (rand_theta) * sqrt(rand_scale); 
    y = b * sin (rand_theta) * sqrt(rand_scale);

    //Test that point (x,y) satisfies the equation (x/a)^2 + (y/b)^2 <= 1 and print the values if successful.
    if ( (((x / a) * (x / a)) + ((y / b) * (y / b))) <= 1 ){
    
      //Print x and y
      cout << std::fixed;
      cout << setw(8) << right << setprecision(4) << x << "\t" << setw(8) << right << setprecision(4) << y << endl;
	
    }
  }
  
  return 0;
}

//The End.
