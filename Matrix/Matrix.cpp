#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
using namespace std;

//template <typename T>
//Создаем класс для матриц
class Matrix {
public:
	Matrix(int, int); //Конструктор с параметрами
//	~Matrix(); //Освобождаем память
	void Print_Matrix() const; //Вывод матрицы на экран
	void input_Matrix(istream &); //Заполнение матрицы из потока

	//Перегружаем операторы
	Matrix operator+(const Matrix &); //Сложение
	const Matrix &operator=(const Matrix &); //Присваивание
	Matrix operator*(const Matrix &);//Умножение

private:
	int col, row;
	int **matrix; 
};

istream &operator>>(istream &, Matrix &);
ostream &operator<<(ostream &, const Matrix &);

Matrix::Matrix(int r, int c): row(r),col(c) {
	matrix = new int*[row];
	for (int i = 0; i < row; i++)
		matrix[i] = new int[col]; 
	//Инициализируем матрицу нулями
	for (int j = 0; j < row; j++)
		for (int k = 0; k < col; k++)
			matrix[j][k] = 0;
}
/*
//TODO Освобождаем память
Matrix::~Matrix() {
	for (int i = 0; i < row; i++)
		delete[]matrix[i];
	delete[]matrix;
}
*/
//Выводим матрицу на экран
void Matrix::Print_Matrix() const {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << setw(4) << matrix[i][j]; //Выделяем 4 ячейки для числа
		cout << endl;
	}
}
//Заполняем матрицу
void Matrix::input_Matrix(istream &input) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
				input >> matrix[i][j];
}
//Перегружаем оператор +
Matrix Matrix::operator+(const Matrix &right) {
	Matrix result(row, col);
	if (row != right.row || col != right.col) { //Проверяем размеры матриц
		cout << "Error: wrong size";
		exit(1);
	}
	else 
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				result.matrix[i][j] = matrix[i][j] + right.matrix[i][j];
	return result;
}
//Перегружаем оператор =
const Matrix &Matrix::operator=(const Matrix &A) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			matrix[i][j] = A.matrix[i][j];
	return *this;
}

//Перегружаем оператор *
Matrix Matrix::operator*(const Matrix &right) {
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
		cout << "Error: wrong size";
		exit(1);
	}
	
}

istream &operator>>(istream &input, Matrix& A) {
	A.input_Matrix(input);
	return input;
}

ostream &operator<<(ostream& output, const Matrix &A) {
	A.Print_Matrix();
	return output;
}

stringstream Form_input(const int&, const int&);//Функция для генерации случайных чисел

int main()
{
	int rows(3), columns(4);
	Matrix A(rows, columns), B(rows, columns), C(rows, columns), D(rows,columns), E(columns, rows),
		F(rows, rows); //Инициализируем матрицы
	A.input_Matrix(Form_input(rows,columns)); //Заполняем матрицу A случайными значениями
	cout << "A" << endl;
	A.Print_Matrix(); //выводим матрицу А
	cout << endl << "B" << endl;
	srand(time(NULL));
	B.input_Matrix(Form_input(rows, columns));//Заполняем матрицу B случайными значениями
	B.Print_Matrix(); //выводим матрицу B
	/*Присваивание*/
	C = A;// В матрицу С копируем А
	cout << endl << "C = A" << endl;
	C.Print_Matrix(); //выводим матрицу С
	/*Сложение*/
	C = A + B;//Складываем матрицы и результат записываем в С
	cout << endl << "A + B" << endl;
	C.Print_Matrix(); //выводим матрицу С
	/*Умножение*/
	D.input_Matrix(Form_input(rows, columns));//Заполняем матрицу D случайными значениями
	E.input_Matrix(Form_input(rows, columns));//Заполняем матрицу E случайными значениями
	F = D*E; //Перемножаем матрицы А и В
	cout << endl << "D * E" << endl;
	F.Print_Matrix(); //выводим матрицу D
	/*Ввод и вывод матриц через операторы cin и cout*/
	cout << endl << "Please, enter 12 numbers: ";
	cin >> A;
	cout << "A after cout" << endl;
	cout << A;

	return 0;
}

//Функция для заполнения любой матрицы случайными цифрами
stringstream Form_input(const int& rows, const int& columns) {
	stringstream input;
	for (int i = 0; i < rows*columns; i++)
		input << rand() % 20 << " ";
	return input;
}