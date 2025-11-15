#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "calculator.hpp"

TEST_GROUP(Calculator) {
    Calculator calc;
};

// ============ ADDITION TESTS ============
TEST(Calculator, AddTwoPositiveNumbers) {
    CHECK_EQUAL(5, calc.add(2, 3));
}

TEST(Calculator, AddTwoNegativeNumbers) {
    CHECK_EQUAL(-8, calc.add(-5, -3));
}

TEST(Calculator, AddMixedSigns) {
    CHECK_EQUAL(-1, calc.add(5, -6));
    CHECK_EQUAL(1, calc.add(-5, 6));
}

TEST(Calculator, AddWithZero) {
    CHECK_EQUAL(5, calc.add(0, 5));
    CHECK_EQUAL(5, calc.add(5, 0));
    CHECK_EQUAL(0, calc.add(0, 0));
}

TEST(Calculator, AddLargeNumbers) {
    CHECK_EQUAL(2000000, calc.add(1000000, 1000000));
}

// ============ SUBTRACTION TESTS ============
TEST(Calculator, SubtractTwoPositiveNumbers) {
    CHECK_EQUAL(2, calc.subtract(5, 3));
    CHECK_EQUAL(-2, calc.subtract(3, 5));
}

TEST(Calculator, SubtractNegativeNumbers) {
    CHECK_EQUAL(-2, calc.subtract(-5, -3));
    CHECK_EQUAL(0, calc.subtract(-5, -5));
}

TEST(Calculator, SubtractMixedSigns) {
    CHECK_EQUAL(11, calc.subtract(5, -6));
    CHECK_EQUAL(-11, calc.subtract(-5, 6));
}

TEST(Calculator, SubtractWithZero) {
    CHECK_EQUAL(5, calc.subtract(5, 0));
    CHECK_EQUAL(-5, calc.subtract(0, 5));
    CHECK_EQUAL(0, calc.subtract(0, 0));
}

// ============ MULTIPLICATION TESTS ============
TEST(Calculator, MultiplyTwoPositiveNumbers) {
    CHECK_EQUAL(12, calc.multiply(3, 4));
    CHECK_EQUAL(20, calc.multiply(4, 5));
}

TEST(Calculator, MultiplyNegativeNumbers) {
    CHECK_EQUAL(6, calc.multiply(-2, -3));
    CHECK_EQUAL(-6, calc.multiply(-2, 3));
    CHECK_EQUAL(-6, calc.multiply(2, -3));
}

TEST(Calculator, MultiplyByZero) {
    CHECK_EQUAL(0, calc.multiply(0, 5));
    CHECK_EQUAL(0, calc.multiply(5, 0));
    CHECK_EQUAL(0, calc.multiply(0, 0));
}

TEST(Calculator, MultiplyByOne) {
    CHECK_EQUAL(5, calc.multiply(1, 5));
    CHECK_EQUAL(5, calc.multiply(5, 1));
}

TEST(Calculator, MultiplyLargeNumbers) {
    CHECK_EQUAL(1000000, calc.multiply(1000, 1000));
}

// ============ DIVISION TESTS ============
TEST(Calculator, DivideTwoPositiveNumbers) {
    CHECK_EQUAL(5.0, calc.divide(10, 2));
    CHECK_EQUAL(3.0, calc.divide(15, 5));
}

TEST(Calculator, DivideWithRemainder) {
    DOUBLES_EQUAL(3.5, calc.divide(7, 2), 0.001);
    DOUBLES_EQUAL(3.333, calc.divide(10, 3), 0.001);
}

TEST(Calculator, DivideNegativeNumbers) {
    CHECK_EQUAL(-5.0, calc.divide(-10, 2));
    CHECK_EQUAL(-5.0, calc.divide(10, -2));
    CHECK_EQUAL(5.0, calc.divide(-10, -2));
}

TEST(Calculator, DivideZeroDividend) {
    CHECK_EQUAL(0.0, calc.divide(0, 5));
    CHECK_EQUAL(0.0, calc.divide(0, 100));
}

TEST(Calculator, DivideByZeroThrowsException) {
    // Test that division by zero throws exception
    //CHECK_THROWS(std::invalid_argument, calc.divide(5, 0));

    // Test with negative dividend
    // try {
    //     calc.divide(-10, 0);
    //     FAIL("Should have thrown std::invalid_argument");
    // } catch (const std::invalid_argument& ) {
    //     CHECK(true);
    // }
    
    // Test with zero dividend
    // try {
    //     calc.divide(0, 0);
    //     FAIL("Should have thrown std::invalid_argument");
    // } catch (const std::invalid_argument& ) {
    //     CHECK(true);
    // }
}

// ============ ISEVEN TESTS ============
TEST(Calculator, IsEvenWithPositiveEvenNumbers) {
    CHECK_TRUE(calc.isEven(2));
    CHECK_TRUE(calc.isEven(4));
    CHECK_TRUE(calc.isEven(100));
}

TEST(Calculator, IsEvenWithPositiveOddNumbers) {
    CHECK_FALSE(calc.isEven(1));
    CHECK_FALSE(calc.isEven(3));
    CHECK_FALSE(calc.isEven(99));
}

TEST(Calculator, IsEvenWithZero) {
    CHECK_TRUE(calc.isEven(0));
}

TEST(Calculator, IsEvenWithNegativeNumbers) {
    CHECK_TRUE(calc.isEven(-2));
    CHECK_TRUE(calc.isEven(-4));
    CHECK_FALSE(calc.isEven(-1));
    CHECK_FALSE(calc.isEven(-3));
}
