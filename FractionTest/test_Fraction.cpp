#include "pch.h"
#include "D:/УЧЕБА/ppois_lab1/Fraction/Fraction.h"
#include "D:/УЧЕБА/ppois_lab1/Fraction/Fraction.cpp"
#include <gtest/gtest.h>


// Тесты для класса Fraction
TEST(FractionTest, DefaultConstructor) {
    Fraction f;
    EXPECT_EQ(f.getNumerator(), 0);
    EXPECT_EQ(f.getDenominator(), 1);
}

TEST(FractionTest, ParameterizedConstructor) {
    Fraction f(3, 4);
    EXPECT_EQ(f.getNumerator(), 3);
    EXPECT_EQ(f.getDenominator(), 4);
}

TEST(FractionTest, DenominatorZeroThrows) {
    EXPECT_THROW(Fraction f(1, 0), std::invalid_argument);
}

TEST(FractionTest, ReduceFraction) {
    Fraction f(4, 8);
    EXPECT_EQ(f.getNumerator(), 1);
    EXPECT_EQ(f.getDenominator(), 2);
}

TEST(FractionTest, GetWholePart) {
    Fraction f(7, 2);
    EXPECT_EQ(f.getWholePart(), 3);
}

TEST(FractionTest, Addition) {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction result = f1 + f2;
    EXPECT_EQ(result.getNumerator(), 5);
    EXPECT_EQ(result.getDenominator(), 6);
}

TEST(FractionTest, Subtraction) {
    Fraction f1(3, 4);
    Fraction f2(1, 4);
    Fraction result = f1 - f2;
    EXPECT_EQ(result.getNumerator(), 2);
    EXPECT_EQ(result.getDenominator(), 4);
}

TEST(FractionTest, Multiplication) {
    Fraction f1(2, 3);
    Fraction f2(3, 4);
    Fraction result = f1 * f2;
    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 2);
}

TEST(FractionTest, Division) {
    Fraction f1(3, 4);
    Fraction f2(2, 3);
    Fraction result = f1 / f2;
    EXPECT_EQ(result.getNumerator(), 9);
    EXPECT_EQ(result.getDenominator(), 8);
}

TEST(FractionTest, DivisionByZeroThrows) {
    Fraction f1(1, 2);
    Fraction f2(0, 1);
    EXPECT_THROW(f1 / f2, std::invalid_argument);
}

TEST(FractionTest, Increment) {
    Fraction f(1, 2);
    EXPECT_EQ(++f, Fraction(3, 2));
}

TEST(FractionTest, Decrement) {
    Fraction f(3, 2);
    EXPECT_EQ(--f, Fraction(1, 2));
}

TEST(FractionTest, Comparison) {
    Fraction f1(1, 2);
    Fraction f2(2, 3);
    EXPECT_TRUE(f1 < f2);
    EXPECT_TRUE(f2 > f1);
    EXPECT_TRUE(f1 <= f1);
    EXPECT_TRUE(f1 >= f1);
}

TEST(FractionTest, ConversionToDouble) {
    Fraction f(3, 4);
    EXPECT_DOUBLE_EQ(static_cast<double>(f), 0.75);
}

// Проверка вывода
TEST(FractionTest, OutputStream) {
    Fraction f(3, 4);
    std::ostringstream oss;
    oss << f;
    EXPECT_EQ(oss.str(), "3/4");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}