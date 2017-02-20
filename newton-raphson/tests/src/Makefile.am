ACLOCAL_AMFLAGS = -I m4
bin_PROGRAMS = mainRunner

mainRunner_SOURCES = mainRunner.cpp testDerivative.cpp testNewtonRaphson.cpp 

include_HEADERS = incl.hpp testDerivative.hpp testNewtonRaphson.hpp \
						../include/mainNR.hpp 
						../include/newton-raphson.hpp
						../include/topologyStrategy.hpp
						../include/types.hpp
						../include/derivative.hpp 

AM_CXXFLAGS = -I. -I../include -std=c++1y -lcppunit

