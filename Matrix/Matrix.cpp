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
//Освобождаем память
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
		cout << "Error: different size";
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
	Matrix result(row, col);
	if (row != right.row || col != right.col) { //Проверяем размеры матриц
		cout << "Error: different size";
		exit(1);
	}
	else
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				result.matrix[i][j] = matrix[i][j] + right.matrix[i][j];
	return result;
}


/*
Matrix Matrix::operator*(const Matrix &rhs) const
{
	Matrix result(_rows, rhs._cols); // Результирующая матрица будет иметь столько же
									 // строк, сколько и левая матрица, и столько же
									 // столбцов, сколько правая

									 // Умножение матриц возможно, только если
									 // количество столбцов левой матрицы и
									 // количество строк правой совпадают
	if (_cols == rhs._rows)
	{
		// Идём по строкам левой матрицы
		for (unsigned i = 0; i < _rows; ++i)
			// Идём по столбцам правой матрицы
			for (unsigned j = 0; j < rhs._cols; ++j)
				// Идём по столбцам левой (и по строка правой) матрицы
				for (unsigned k = 0; k < _cols; ++k)
					// Формируем очередной элемент результирующей матрицы
					result._matrix[i][j] += _matrix[i][k] * rhs._matrix[k][j];
	}
	// Если количество столбцов левой и количество
	// строк правой матрицы не совпадают, то
	// результатом выполнения операции будет
	// число 0
	else
		result.resize();

	// Возвращаем результат умножения
	return result;
}
*/


stringstream Form_input(const int&, const int&);//Функция для генерации случайных чисел

int main()
{
	int rows(3), columns(4);
	Matrix A(rows, columns), B(rows, columns), C(rows, columns), D(10,10); //Инициализируем матрицы
	A.input_Matrix(Form_input(rows,columns)); //Заполняем матрицу A случайными значениями
	A.Print_Matrix(); //выводим матрицу А
	cout << endl;
	srand(time(NULL));
	B.input_Matrix(Form_input(rows, columns));//Заполняем матрицу B случайными значениями
	B.Print_Matrix(); //выводим матрицу B
	C = A;// В матрицу С копируем А
	cout << endl;
	C.Print_Matrix(); //выводим матрицу С
	C = A + B;//Складываем матрицы и результат записываем в С
	cout << endl;
	C.Print_Matrix(); //выводим матрицу С

	
	
	return 0;
}

//Функция для заполнения любой матрицы случайными цифрами
stringstream Form_input(const int& rows, const int& columns) {
	stringstream input;
	for (int i = 0; i < rows*columns; i++)
		input << rand() % 99 << " ";
	return input;
}