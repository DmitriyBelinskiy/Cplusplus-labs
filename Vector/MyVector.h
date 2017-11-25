#pragma once
#include <iostream>

class MyVector
{
public:
	//Конструкторы
	MyVector();
	//принимаем другой вектор
	MyVector(const MyVector&);
	//принимаем элемент
	MyVector(const int&);
	~MyVector();

	//Записываем элемент в конец вектора
	void push_back(const int&);
	//забираем из конца элемент и удаляем его из вектора
	int pop_back();
	//извлекаем элемент по индексу
	int get_element(const int&);
	//выводим все элементы в консоль
	void print() const;

	//добавляем к текущему вектору новый
	void copy_in(const MyVector&);
	//проверяем вхождение элемента
	bool element_check(const int&) const;
	//вычисляем размер вектора
	int size() const;

	//перегрузка операторов
	MyVector &operator=(MyVector&);
	MyVector *operator+(MyVector&);
	MyVector *operator*(const MyVector&);


private:
	//указатель на начало вектора
	int *p_begin;
	//размер вектора
	int v_size;

};

//+=   - добавление последнего элемента в массив
//-=   - удаляем последний
