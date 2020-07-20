CXX = g++
CXXFLAGS = -Wall -g

complexity_test: complexity_test.o
	$(CXX) $(CXXFLAGS) -o complexity_test complexity_test.o