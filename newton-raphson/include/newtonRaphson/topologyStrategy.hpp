#pragma once

#include <cassert>   
#include <math.h>
#include "types.hpp"

class CloseEnough {
  public:
    virtual bool operator()(Real x0,Real x1) = 0;  
};

class MyCloseEnouph : CloseEnough {
  public:
    MyCloseEnouph (Real eps){ assert (eps > 0); epsilon = eps;}
    bool operator()(Real x0,Real x1);
    Real epsilon; 
};

class VerySmall {
  public:
    virtual bool operator()(Real x) = 0;
};

class MyVerySmall : VerySmall {
  public:
    MyVerySmall (Real eps){ assert (eps > 0); epsilon = eps;}
    bool operator()(Real x) {return fabs(x) < epsilon;} 
    Real epsilon;
};

bool MyCloseEnouph::operator()(Real x0,Real x1) { 
	return (fabs(x1 - x0) <= epsilon* fabs(x1)); 
}
