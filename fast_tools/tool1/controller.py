#!/usr/bin/env python3

# Copyright (c) 2016
#


"""
Python inteface/wrapper to the native code
"""

import fast_tools.tool1 as NativeModule


error = BaseException()



def run_single_calculation(data):
    """Calculates a single calculation"""

    try:
        result = NativeModule.runSingleCal(operand1=2,operand2=2,operation='+')
        return result
    except NativeModule.error as e:
       error = e
       raise Exception(str(e))
