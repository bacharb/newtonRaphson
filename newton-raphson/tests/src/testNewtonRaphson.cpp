#include "incl.hpp"
#include "testNewtonRaphson.hpp"
#include "topologyStrategy.hpp"

void TestNewtonRaphson::test_racineDe2(void) {
	// the classical root extraction of 2.
	auto f = [](Real x) {return x*x - 2;};

	MyCloseEnouph   ce {0.001};
	MyVerySmall     vs {0.001};
	Real            x0 {1.5};


	TwoPointDerivative df;

	auto result = newtonRaphson(f, x0, df, vs, ce);
	assert (ce(sqrt(2), result));		
}

void TestNewtonRaphson::test_polynomialFun(void) {
	// exp(0) = 1 => 0 is a root of  f (x) = exp(x)-1
	auto f = [](Real x) {return exp(x) - 1;};

	MyCloseEnouph   ce {0.001};
	MyVerySmall     vs {0.001};
	Real            x0 {1.5};

	TwoPointDerivative df; 

	 newtonRaphson(f, x0, df, vs, ce);
//	std::cout << "\n \n vs = " << vs(result) << endl;
//	std::cout << "\n \n ce = " << ce(result,0) << endl;
//	assert (ce(0, result));		
}

void TestNewtonRaphson::test_trigonometrcFun(void) {
	MyCloseEnouph   ce {0.001};
	MyVerySmall     vs {0.001};
	Real            x0 {0.5};

	TwoPointDerivative df; 

	auto result = newtonRaphson( [](Real x) {return sin(x);},   x0, df, vs, ce);
	assert (ce(0, result));	

	result = newtonRaphson( [](Real x) {return cos(x);},   x0, df, vs, ce);
	assert (ce(pi/2, result));	

	result = newtonRaphson( [](Real x) {return tan(x);},  x0 , df, vs, ce);
	assert (ce(0, result));	

	
	x0 = 3.5;
	// By changing x0 we get another root.
	result = newtonRaphson( [](Real x) {return tan(x);},  x0 , df, vs, ce);
	assert (ce(pi, result));	
}

