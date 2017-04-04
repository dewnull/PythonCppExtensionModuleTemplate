#!/usr/bin/env bash
cd ../fast_tools/tool1/tests/cpp_unit_tests/

# Delete previously builts
make clean

# Build the tests using Makefile
make

# Run the tests and export to xml
./RunUnitTests --gtest_output="xml:./UnitTests.xml"

# Run gcovr
#/usr/local/bin/gcovr --branches --xml -r ../../  --exclude='.*/tests/.*' -o gcovr.xml
#/usr/local/bin/gcovr --branches -r ../../ --html --html-details  --exclude='.*/tests/.*' -o gcovr-report.html
