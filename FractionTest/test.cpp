#include "pch.h"
#include "D:/УЧЕБА/ppois_lab1/Fraction/Fraction.h"
#include "D:/УЧЕБА/ppois_lab1/Fraction/Fraction.cpp"
#include <gtest/gtest.h>


// Тестовый класс
class FractionTest : public ::testing::Test {
protected:
    Fraction f1, f2;

    void SetUp() override {
        f1 = Fraction(1, 2); // 1/2
        f2 = Fraction(3, 4); // 3/4
    }
};

// Тесты конструктора
TEST_F(FractionTest, Constructor_Valid) {
    EXPECT_NO_THROW(Fraction(1, 2));
    EXPECT_NO_THROW(Fraction(-1, -2));
    EXPECT_NO_THROW(Fraction(1, -2));
}

TEST_F(FractionTest, Constructor_Invalid) {
    EXPECT_THROW(Fraction(1, 0), std::invalid_argument);
}

// Тесты геттеров
TEST_F(FractionTest, GetNumerator) {
    EXPECT_EQ(f1.getNumerator(), 1);
    EXPECT_EQ(f2.getNumerator(), 3);
}

TEST_F(FractionTest, GetDenominator) {
    EXPECT_EQ(f1.getDenominator(), 2);
    EXPECT_EQ(f2.getDenominator(), 4);
}

TEST_F(FractionTest, GetWholePart) {
    EXPECT_EQ(f1.getWholePart(), 0);
    EXPECT_EQ(Fraction(5, 2).getWholePart(), 2);
}

// Тесты арифметических операций
TEST_F(FractionTest, Addition) {
    Fraction result = f1 + f2; // 1/2 + 3/4 = 5/4
    EXPECT_EQ(result.getNumerator(), 5);
    EXPECT_EQ(result.getDenominator(), 4);
}

TEST_F(FractionTest, Subtraction) {
    Fraction result = f1 - f2; // 1/2 - 3/4 = -1/4
    EXPECT_EQ(result.getNumerator(), -1);
    EXPECT_EQ(result.getDenominator(), 4);
}

TEST_F(FractionTest, Multiplication) {
    Fraction result = f1 * f2; // 1/2 * 3/4 = 3/8
    EXPECT_EQ(result.getNumerator(), 3);
    EXPECT_EQ(result.getDenominator(), 8);
}

TEST_F(FractionTest, Division) {
    Fraction result = f1 / f2; // 1/2 / 3/4 = 2/3
    EXPECT_EQ(result.getNumerator(), 2);
    EXPECT_EQ(result.getDenominator(), 3);
}

TEST_F(FractionTest, DivisionByZero) {
    EXPECT_THROW(f1 / Fraction(0, 1), std::invalid_argument);
}

// Тесты инкремента и декремента
TEST_F(FractionTest, Increment) {
    EXPECT_EQ((++f1).getNumerator(), 3); // 1/2 + 1 = 3/2
}

TEST_F(FractionTest, Decrement) {
    EXPECT_EQ((--f2).getNumerator(), 1); // 3/4 - 1 = 1/4
}

// Тесты сравнения
TEST_F(FractionTest, Comparison) {
    EXPECT_TRUE(f1 < f2);
    EXPECT_TRUE(f2 > f1);
    EXPECT_TRUE(f1 <= f1);
    EXPECT_TRUE(f1 >= f1);
}

// Тесты конверсии в double
TEST_F(FractionTest, ConversionToDouble) {
    EXPECT_DOUBLE_EQ(static_cast<double>(f1), 0.5);
    EXPECT_DOUBLE_EQ(static_cast<double>(f2), 0.75);
}

// Тесты вывода
TEST_F(FractionTest, Output) {
    std::ostringstream os;
    os << f1;
    EXPECT_EQ(os.str(), "1/2");
}

// Основная функция для запуска тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}}