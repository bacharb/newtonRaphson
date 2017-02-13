#pragma once
#include "types.hpp"

// DF: is a function object implementing the algorithm of derivation.
//		 In this way we can accommodate varieties of derivation schema. 
// VS (Very Small): a function object used to decide on the smallness concept.
// CE (CloseEnough): is a function object class implementing the relative difference 
// 						between two values.

template <typename DF = Derivative, typename VS, typename CE>
auto newtonRaphson (Function f, Real x0, 
		DF df, VS isVerySmall, CE isCloseEnough, Natural max =100) {

	for (auto i=0; i < max; i++) {
		auto y0 = f(x0);
		auto dy0 = df(f, x0);

		// f'(x0) = 0 ==> we are in a stationary point and improvement will be expected.
		// In this case, just return the best guess we collected so far: x0.
		// There are many ways to decide whether a floating number is very small to consider as 0.
		if (isVerySmall(dy0)) break;

		// This is the core work.   
		auto x1=x0-y0/dy0;
		
		// A measure of relative difference between x0 and x1 is needed.
		// There are a variety of such measures.  Most of them do not work when the reference 
		// value is null.  It's way we need the 'isVerySmall" function. 
		if (isCloseEnough(x0, x1)) {
			x0 = x1; 
			break;
		}   
		x0=x1;
	}
	return x0;
}
