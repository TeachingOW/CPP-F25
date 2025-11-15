# Unit Testing with CMake and CppUTest - Calculator Example

This directory contains a complete example of C++ unit testing using **CMake** and **CppUTest** framework.

## Files

- **calculator.hpp** - Header file with Calculator class
- **calculator.cpp** - Implementation of Calculator methods
- **test_calculator.cpp** - CppUTest unit tests (25+ test cases)
- **CMakeLists.txt** - CMake build configuration with CppUTest integration

## Building and Running Tests

### First-time setup and build:
```bash
# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
cmake --build .
```

### Running tests:
```bash
# From the build directory, run all tests
ctest --output-on-failure

# Or run the test executable directly
./calculator_tests
```

### Verbose test output:
```bash
./calculator_tests -v
```

### Clean build:
```bash
cd ..
rm -rf build
```

## Calculator Class

The `Calculator` class provides basic arithmetic operations:

| Method | Parameters | Returns | Description |
|--------|-----------|---------|-------------|
| `add()` | `int a, int b` | `int` | Returns sum of two integers |
| `subtract()` | `int a, int b` | `int` | Returns difference of two integers |
| `multiply()` | `int a, int b` | `int` | Returns product of two integers |
| `divide()` | `int a, int b` | `double` | Returns quotient; throws on division by zero |
| `isEven()` | `int n` | `bool` | Returns true if number is even |

## Test Coverage (25+ Tests)

### Addition Tests (5 tests)
- Adding two positive numbers
- Adding two negative numbers
- Adding mixed signs
- Adding with zero
- Adding large numbers

### Subtraction Tests (4 tests)
- Subtracting positive numbers
- Subtracting negative numbers
- Subtracting mixed signs
- Subtracting with zero

### Multiplication Tests (5 tests)
- Multiplying positive numbers
- Multiplying negative numbers
- Multiplying by zero
- Multiplying by one
- Multiplying large numbers

### Division Tests (5 tests)
- Dividing positive numbers
- Division with remainder (floating-point)
- Dividing negative numbers
- Zero as dividend
- Division by zero exception handling

### IsEven Tests (4 tests)
- Even positive numbers
- Odd positive numbers
- Zero
- Negative numbers (even and odd)

## CppUTest Features Used

### Test Macros
- `TEST_GROUP()` - Groups related tests together
- `TEST()` - Defines individual test case
- `CHECK_EQUAL()` - Assert equality
- `CHECK_TRUE/FALSE()` - Assert boolean values
- `DOUBLES_EQUAL()` - Assert floating-point equality with tolerance
- `CHECK_THROWS()` - Verify exception throwing

### Test Organization
- Grouped by functionality (Addition, Subtraction, etc.)
- Clear naming convention: `TestGroup_Behavior`
- Comprehensive edge case coverage

## Building with CppUTest

The CMakeLists.txt automatically:
- Downloads CppUTest from GitHub release
- Builds CppUTest as a dependency
- Links calculator library with test framework
- Registers tests with ctest

## Example Test Output

```
Running Calculator Unit Tests
OK (25 tests)
```

Each test runs independently and reports pass/fail status.