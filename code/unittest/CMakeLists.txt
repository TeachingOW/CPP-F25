cmake_minimum_required(VERSION 3.10)
project(CalculatorTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include CppUTest
include(FetchContent)
FetchContent_Declare(
    cpputest
    URL https://github.com/cpputest/cpputest/releases/download/v4.0/cpputest-4.0.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP ON
)
FetchContent_MakeAvailable(cpputest)

# Add the calculator library
add_library(calculator calculator.cpp)
target_include_directories(calculator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Enable testing
enable_testing()

# Add the test executable
add_executable(calculator_tests test_calculator.cpp)
target_include_directories(calculator_tests PRIVATE ${cpputest_SOURCE_DIR}/include)
target_link_libraries(calculator_tests PRIVATE calculator CppUTest)

# Register the test
add_test(NAME CalculatorTests COMMAND calculator_tests)
