GTEST_DIR=/opt/gtest
CXX = g++
CXXFLAGS = -std=c++11 -L$(GTEST_DIR)/lib -lgtest -lgtest_main -pthread -ldl -fprofile-arcs -ftest-coverage\
 -fPIC -O0

INCS = -I../../libs/include \
       -I../../include \
       -I$(GTEST_DIR)/include
OBJS = ../../libs/CommonLibs/src/somesourcefile.o \
       ../../src/MathFuncsLib.o \
       adder_tests.o


RunUnitTests: $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCS) -Wl,-rpath=$(GTEST_DIR)/lib -o RunUnitTests  main.cpp $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

.PHONY : clean
clean :
	rm -f RunUnitTests $(OBJS) AllUnitTests.xml
