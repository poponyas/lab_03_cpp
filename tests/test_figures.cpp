#include <gtest/gtest.h>
#include "Trapeze.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "FiguresArray.h"
#include <sstream>

// Тесты для Trapeze
TEST(TrapezeTest, DefaultConstructor)
{
    Trapeze t;
    EXPECT_DOUBLE_EQ(t.area(), 1.5); // (2+1)*1/2 = 1.5
}

TEST(TrapezeTest, GetCenter)
{
    Trapeze t(1, 2, 4, 2, 3);
    auto center = t.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 1.0);
    EXPECT_DOUBLE_EQ(center.second, 2.0);
}

TEST(TrapezeTest, DoubleConversion)
{
    Trapeze t(0, 0, 4, 2, 3);
    double area = static_cast<double>(t);
    EXPECT_DOUBLE_EQ(area, 9.0);
}

TEST(TrapezeTest, EqualityOperator)
{
    Trapeze t1(0, 0, 4, 2, 3);
    Trapeze t2(0, 0, 4, 2, 3);
    Trapeze t3(1, 1, 5, 3, 4);

    EXPECT_TRUE(t1 == t2);
    EXPECT_FALSE(t1 == t3);
}

TEST(TrapezeTest, StreamInput)
{
    Trapeze t;
    std::stringstream ss("1 2 3 4 5");
    ss >> t;

    // Проверяем что данные правильно считались
    auto center = t.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 1.0);
    EXPECT_DOUBLE_EQ(center.second, 2.0);
    EXPECT_DOUBLE_EQ(t.area(), 17.5); // (3+4)*5/2 = 17.5
}

// Тесты для Rhombus
TEST(RhombusTest, DefaultConstructor)
{
    Rhombus r;
    EXPECT_DOUBLE_EQ(r.area(), 1.0); // (2*1)/2 = 1
}

TEST(RhombusTest, AreaCalculation)
{
    Rhombus r(0, 0, 6, 4);
    EXPECT_DOUBLE_EQ(r.area(), 12.0); // (6*4)/2 = 12
}

TEST(RhombusTest, GetCenter)
{
    Rhombus r(3, 4, 6, 4);
    auto center = r.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 3.0);
    EXPECT_DOUBLE_EQ(center.second, 4.0);
}

TEST(RhombusTest, DoubleConversion)
{
    Rhombus r(0, 0, 6, 4);
    double area = static_cast<double>(r);
    EXPECT_DOUBLE_EQ(area, 12.0);
}

TEST(RhombusTest, EqualityOperator)
{
    Rhombus r1(0, 0, 6, 4);
    Rhombus r2(0, 0, 6, 4);
    Rhombus r3(1, 1, 8, 5);

    EXPECT_TRUE(r1 == r2);
    EXPECT_FALSE(r1 == r3);
}

// Тесты для Pentagon
TEST(PentagonTest, DefaultConstructor)
{
    Pentagon p;
    EXPECT_NEAR(p.area(), 1.72048, 0.0001); // Площадь пятиугольника со стороной 1
}

TEST(PentagonTest, AreaCalculation)
{
    Pentagon p(0, 0, 5);
    EXPECT_NEAR(p.area(), 43.0119, 0.0001); // Площадь пятиугольника со стороной 5
}

TEST(PentagonTest, GetCenter)
{
    Pentagon p(2, 3, 5);
    auto center = p.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 3.0);
}

TEST(PentagonTest, DoubleConversion)
{
    Pentagon p(0, 0, 5);
    double area = static_cast<double>(p);
    EXPECT_NEAR(area, 43.0119, 0.0001);
}

TEST(PentagonTest, EqualityOperator)
{
    Pentagon p1(0, 0, 5);
    Pentagon p2(0, 0, 5);
    Pentagon p3(1, 1, 6);

    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

// Тесты для FiguresArray
TEST(FiguresArrayTest, DefaultConstructor)
{
    FiguresArray arr;
    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_DOUBLE_EQ(arr.totalArea(), 0.0);
}

TEST(FiguresArrayTest, AddFigures)
{
    FiguresArray arr;

    Trapeze *t = new Trapeze(0, 0, 4, 2, 3);
    Rhombus *r = new Rhombus(0, 0, 6, 4);

    arr.addFigure(t);
    arr.addFigure(r);

    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_DOUBLE_EQ(arr.totalArea(), 21.0); // 9 + 12
}

TEST(FiguresArrayTest, RemoveFigure)
{
    FiguresArray arr;

    Trapeze *t = new Trapeze(0, 0, 4, 2, 3);
    Rhombus *r = new Rhombus(0, 0, 6, 4);

    arr.addFigure(t);
    arr.addFigure(r);

    arr.removeFigure(0); // Удаляем трапецию

    EXPECT_EQ(arr.getSize(), 1);
    EXPECT_DOUBLE_EQ(arr.totalArea(), 12.0); // Остался только ромб
}

TEST(FiguresArrayTest, CopyConstructor)
{
    FiguresArray arr1;
    arr1.addFigure(new Trapeze(0, 0, 4, 2, 3));

    FiguresArray arr2 = arr1; // Копирование

    EXPECT_EQ(arr2.getSize(), 1);
    EXPECT_DOUBLE_EQ(arr2.totalArea(), 9.0);
}

TEST(FiguresArrayTest, MoveConstructor)
{
    FiguresArray arr1;
    arr1.addFigure(new Trapeze(0, 0, 4, 2, 3));

    FiguresArray arr2 = std::move(arr1); // Перемещение

    EXPECT_EQ(arr2.getSize(), 1);
    EXPECT_DOUBLE_EQ(arr2.totalArea(), 9.0);
    EXPECT_EQ(arr1.getSize(), 0); // Исходный массив должен быть пуст
}

// Тесты на полиморфизм
TEST(PolymorphismTest, FigurePointer)
{
    Figure *fig1 = new Trapeze(0, 0, 4, 2, 3);
    Figure *fig2 = new Rhombus(0, 0, 6, 4);

    EXPECT_DOUBLE_EQ(fig1->area(), 9.0);
    EXPECT_DOUBLE_EQ(fig2->area(), 12.0);

    delete fig1;
    delete fig2;
}

TEST(PolymorphismTest, DoubleConversionThroughBasePointer)
{
    Figure *fig = new Trapeze(0, 0, 4, 2, 3);
    double area = static_cast<double>(*fig);
    EXPECT_DOUBLE_EQ(area, 9.0);
    delete fig;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}