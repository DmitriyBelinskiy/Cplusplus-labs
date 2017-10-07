/*   Создаем класс для Матрицы и перегружаем операторы ввода, вывода, а также: +,-,*,=   */
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <iosfwd>
using namespace std;


//Создаем класс для матриц
class Matrix {
public:
	Matrix(int, int); //Конструктор с параметрами
	//~Matrix(); //Освобождаем память

	//Перегружаем операторы
	Matrix operator+(const Matrix &) const; //Сложение
	Matrix &operator=(const Matrix &); //Присваивание
	Matrix operator*(const Matrix &) const;//Умножение

	friend istream &operator>>(istream &, Matrix &);
	friend ostream &operator<<(ostream &, const Matrix &);
	
private:
	int col, row;
	int **matrix; 
};



Matrix::Matrix(int r, int c): row(r),col(c) {
	matrix = new int*[row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new int[col];
		//Инициализируем матрицу нулями
		for (int j = 0; j < col; j++)
			matrix[i][j] = 0;
	}
}
/*
//TODO Освобождаем память
Matrix::~Matrix() {
	for (int i = 0; i < row; i++)
		delete[]matrix[i];
	delete[]matrix;
}
*/

//Перегружаем оператор +
Matrix Matrix::operator+(const Matrix &right) const {
	if (row != right.row || col != right.col) { //Проверяем размеры матриц
		cout << "Matrices dimensions doesn't allow sum!";
		exit(1);
	}
	else {
		Matrix result(row, col);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				result.matrix[i][j] = matrix[i][j] + right.matrix[i][j];
		return result;
	}	
}

//Перегружаем оператор =
Matrix &Matrix::operator=(const Matrix &A) = default;

//Перегружаем оператор *
Matrix Matrix::operator*(const Matrix &right) const {
	Matrix result(row, right.col);
	if (col == right.row) {
		// Идём по строкам левой матрицы
		for (int i = 0; i < row; i++)
			// Идём по столбцам правой матрицы
			for (int j = 0; j < right.col; j++)
				// Идём по столбцам левой (и по строка правой) матрицы
				for (int k = 0; k < col; k++)
					// Формируем очередной элемент результирующей матрицы
					result.matrix[i][j] += matrix[i][k] * right.matrix[k][j];
		return result;
	}
	else {
		cout << "Matrices dimensions doesn't allow multiplication!";
		exit(1);
	}	
}

//Перегрузка оператора ввода
istream &operator>>(istream &input, Matrix& A) {
	for (int i = 0; i < A.row; i++)
		for (int j = 0; j < A.col; j++)
			input >> A.matrix[i][j];
	return input;
}

//Перегрузка оператора вывода
ostream &operator<<(ostream& output, const Matrix &A) {
	for (int i = 0; i < A.row; i++) {
		for (int j = 0; j < A.col; j++)
			cout << setw(4) << A.matrix[i][j]; //Выделяем 4 ячейки для числа
		cout << endl;
	}
	return output;
}

stringstream Form_input(const int&, const int&);//Функция для генерации случайных чисел для матрицы нужного размера

int main()
{
	int rows(3), columns(4);
	//Инициализируем матрицы
	Matrix A(rows, columns), B(rows, columns), C(rows, columns), D(columns, rows), E(rows, rows); 

	//Заполняем матрицу A случайными значениями
	Form_input(rows, columns) >> A;
	//выводим матрицу А
	cout << "Matrix A:" << endl << A << endl; 

	//Заполняем матрицу B случайными значениями
	srand(time(NULL));
	Form_input(rows, columns) >> B;
	//выводим матрицу B
	cout << "Matrix B:" << endl << B << endl; 
	//Складываем матрицы и результат записываем в С
	C = A + B;
	//выводим матрицу C
	cout << "C = A + B" << endl << C << endl; 

	//Заполняем матрицу D через cin
	cout << "Please enter 12 numbers to fill matrix D: ";
	cin >> D;
	//Перемножаем матрицы C и D
	E = C*D; 
	//выводим матрицу E
	cout << "E = C * D" << endl << E << endl; 

	return 0;
}

//Функция для генерации случайных чисел для матрицы нужного размера
stringstream Form_input(const int& rows, const int& columns) {
	stringstream input;
	for (int i = 0; i < rows*columns; i++)
		input << rand() % 20 << " ";
	return input;
}