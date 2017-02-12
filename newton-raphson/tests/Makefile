CXX = g++
INCLUDES  = -I. -I../include/
LINKFLAGS = -lcppunit
CXXFLAGS  = -std=c++1y -g  -Wall $(INCLUDES) ${LINKFLAGS} 

OBJS = testDerivative.o testNewtonRaphson.o  mainRunner.cpp

runAllTests: ${OBJS}
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ 

testDerivative.o : testDerivative.hpp testDerivative.cpp 
	$(CXX) -std=c++1y -g  -Wall $(INCLUDES)  testDerivative.cpp -c

testNewtonRaphson.o : testNewtonRaphson.hpp testNewtonRaphson.cpp 
	$(CXX) -std=c++1y -g  -Wall $(INCLUDES)  testNewtonRaphson.cpp -c


clean:
	@rm -fr runAllTests* *.o 

