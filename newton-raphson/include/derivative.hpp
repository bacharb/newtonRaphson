#pragma once

#include <iostream>
#include <iomanip> 
#include <math.h>
#include <cassert>   
#include <functional>
#include <types.hpp>

class Derivative {
	public:
		virtual Real operator ()(const std::function<Real(Real)> &f, Real x ) = 0 ; 
		virtual ~Derivative () {}
};


class TwoPointDerivative : public Derivative {
	public:
		TwoPointDerivative (Real h=0.00001): h(h) {}
      Real operator ()(const std::function<Real(Real)> &f, Real x ) {return  (f(x+h) - f(x-h)) * pow(2*h,-1);}
		Real  h;  
};
