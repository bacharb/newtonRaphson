#include "incl.hpp"
#include "testDerivative.hpp"

void TestDerivative::test_general(void){
   auto f1 =  [&](Real x) {return sin(x);};
   auto &f2 = g;
   Afunction f3; 
   TwoPointDerivative df; 
   
   Real x0 {TestDerivative::x0};
   assert(fabs(cos (x0) - df(f1,x0)) < TestDerivative::h);
   assert(fabs(cos(x0) - df(f1, x0)) < TestDerivative::h);
   assert(fabs(cos (x0) - df(f2,x0)) < TestDerivative::h);
   assert(fabs(cos (x0) - df(f3,x0)) < TestDerivative::h);
   assert(fabs(exp (x0) - df(exp,x0)) < TestDerivative::h);
   
   auto h1 =  [&](Real x) {return -sin(x);};
   auto h2 =  [&](Real x) {return pow(x,-1);};
   
   assert(fabs(h1(x0) - df(cos,x0)) < TestDerivative::h);
   assert(fabs(h2(x0) - df(log,x0)) < TestDerivative::h);

   auto g =  [&](Real x) {return sin(x*x + x -2) + x*x;};
   auto gp =  [&](Real x) {return (2*x +1)* cos(x*x + x -2 ) + 2*x;};
   
   assert(fabs(gp(x0) - df(g,x0)) < TestDerivative::h);
}

void TestDerivative::test_stability(void){
   // The behaviour near a singular point.  
   TwoPointDerivative df(0.0001);
   auto h =  [&](Real x) {return pow(x,-1);};
   Real x0 {0.1}; // Smaller than this value and the test fails !! 
   assert(fabs(h(x0) - df(log,x0)) < TestDerivative::h);
}

