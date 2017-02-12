SRC = main.cpp
 
INCLUDES = -Iinclude/ 
CCFLAGS = -g -std=c++1y
CCC = g++

 .SUFFIXES: .cpp
 
main:  ${SRC} dep 
	$(CCC) $(INCLUDES) $(CCFLAGS) main.cpp -o main

depend: dep
 
dep:
	makedepend  $(INCLUDES)

clean:
	rm -f main

# DO NOT DELETE
