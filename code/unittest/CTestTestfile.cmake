# CMake generated Testfile for 
# Source directory: /workspaces/CPP-F25/code/unittest
# Build directory: /workspaces/CPP-F25/code/unittest
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(CalculatorTests "/workspaces/CPP-F25/code/unittest/calculator_tests")
set_tests_properties(CalculatorTests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/CPP-F25/code/unittest/CMakeLists.txt;29;add_test;/workspaces/CPP-F25/code/unittest/CMakeLists.txt;0;")
subdirs("_deps/cpputest-build")
