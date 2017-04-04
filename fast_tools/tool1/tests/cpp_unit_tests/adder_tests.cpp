/**
* \file adder_tests.cpp
*
* Code to perform unit test
*
*/
#include "gtest/gtest.h"
#include "helper.h"

TEST(AdderTests, divisionTest)
{
    double op1 = 10;
    double op2 = 5;
    EXPECT_DOUBLE_EQ(op1+op2,MathFuncs::MyMathFuncs::Add(op1, op2));
}
