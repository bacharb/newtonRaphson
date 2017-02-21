#include <iostream>
#include "mainNR.hpp"

bool isClose (Real x,Real y, Real epsilon=0.0001) {
	assert (epsilon > 0);
	
   //std::cout << "abs = " <<  fabs(x - y) << std::endl; 
   //std::cout << "epsilo.. = " <<  epsilon * fabs(y) << std::endl; 
	
	return fabs(x - y) <= epsilon* fabs(y);
}

int main (){ 
   auto            f =  [&](Real x) {return exp(x) - 1;};
   MyCloseEnouph   ce {0.001};
  	MyVerySmall     vs {0.01};
   Real            x0 {2};

   TwoPointDerivative df; 
   
   auto result = newtonRaphson(f,  x0,   df, vs,ce);

   std::cout << "vs = " << vs(result) << std::endl; 
   std::cout << "ce = " << ce(result,0) << std::endl; 
   std::cout << "ce = " << ce(0,result) << std::endl; 
	isClose (0,result);
   std::cout << "isClose = " << isClose (result,0) << std::endl; 
   std::cout << "isClose = " << isClose (0,result) << std::endl; 
	
	
   return 0;
}

