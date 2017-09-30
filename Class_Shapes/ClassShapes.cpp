/* Создание виртуальной функции для вычисления площади фигур на примере создания классов с 
наследованиями: Shape, Triangle, Circle, Rectangle, Square. */

#include "stdafx.h"
#include <iostream>
using namespace std;
//число Пи
const double PI = 3.14159265;

//Класс Shape + виртуальная функция
class Shape {
public:
	virtual double Calculate_Area() const = 0;
};

//Класс Triangle наследуется от класса Shape
class Triangle : public Shape {
private:
	double base, hight;
public:
	Triangle(double, double);
	double Calculate_Area() const; //const
};
//Конструктор по умолчанию
Triangle::Triangle(double b, double h) :base(b), hight(h) {}
//Использование виртуальной функции для вычисления площади
double Triangle::Calculate_Area() const {
	return 0.5*base*hight;
}
//Класс Circle наследуется от класса Shape
class Circle : public Shape {
private:
	double radius;
public:
	Circle(double);
	double Calculate_Area() const;
};

//Конструктор по умолчанию
Circle::Circle(double r) : radius(r) {}

//Использование виртуальной функции для вычисления площади
double Circle::Calculate_Area() const {
	return PI*radius*radius;
}

//Класс Rectangle наследуется от класса Shape
class Rectangle : public Shape {
protected:
	double side_a, side_b;
public:
	Rectangle(double, double);
	double Calculate_Area() const;
};

//Конструктор по умолчанию
Rectangle::Rectangle(double a, double b) : side_a(a), side_b(b) {}

//Использование виртуальной функции для вычисления площади
double Rectangle::Calculate_Area() const {
	return side_a*side_b;
}

//Класс Square наследуется от класса Rectangle
class Square : public Rectangle {
public:
	Square(double);
	double Calculate_Area() const;
};

//Коснтруктор класса квадрата вызывает конструктор класса прямоугольника
Square::Square(double a) : Rectangle(a,a) {
}

//Использование виртуальной функции для вычисления площади
double Square::Calculate_Area() const {
	return side_a*side_b;
}

int main()
{
	Shape *S;
	Circle c(5);
	Triangle t(3, 8);
	Rectangle r(2, 4);
	Square sq(3);
	S = &c;
	cout << S->Calculate_Area() << endl; //площадь круга

	S = &t;
	cout << S->Calculate_Area() << endl; //площадь треугольника

	S = &r;
	cout << S->Calculate_Area() << endl; //площадь прямоугольника

	S = &sq;
	cout << S->Calculate_Area() << endl; //площадь прямоугольника

	return 0;
}

