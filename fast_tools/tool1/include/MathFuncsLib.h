#pragma once
/**
* \file MyMathFuncs.h
*
* Helper class used for fast calculations.
*
* \author Author Lastname1 - author1@domain.com
* \author Author Lastname2 - author2@domain.com
* \copyright (c) 2016 Company LLC. All rights reserved.
*
*/
#ifndef __fast_tools_helper_h__
#define __fast_tools_helper_h__

#include <string>
// MathFuncsLib.h

namespace MathFuncs
{
    class MyMathFuncs
    {
    public:
        // Returns a + b
        static double Add(double a, double b);

        // Returns a - b
        static double Subtract(double a, double b);

        // Returns a * b
        static double Multiply(double a, double b);

        // Returns a / b
        static double Divide(double a, double b);
    };
}

#endif // __fast_tools_helper_h__
