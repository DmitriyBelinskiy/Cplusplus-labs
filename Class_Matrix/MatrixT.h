#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
using namespace std;


//Создаем класс для матриц
template <class T>
class Matrix {
public:
	Matrix(int, int); //Конструктор с параметрами
	~Matrix(); //Освобождаем память

			   //Перегружаем операторы
	Matrix* operator+(const Matrix &) const; //Сложение
	Matrix &operator=(const Matrix &); //Присваивание
	Matrix* operator*(const Matrix &) const;//Умножение

	//Добавляем символ "<>", чтобы не ругался компановщик. Иначе нужно перенести реализацию перегрузки внутрь класса.
	friend istream &operator>><>(istream &, Matrix &); 
	friend ostream &operator<<<>(ostream &, const Matrix &); //Добавляем символ "<>", чтобы не ругался компановщик

	//Простые методы для заполнения матрицы из статического массива и вывод ее на экран
	void Set(T[]);
	void Print();

	void find_Min();

private:
	int col, row;
	T **matrix;
};

//Функция для генерации случайных чисел для матрицы нужного размера (на всякий случай)
stringstream Form_input(const int&, const int&);

//Выделяем память под матрицу указанного размера
template <class T>
Matrix<T>::Matrix(int r, int c) : row(r), col(c) {
	matrix = new T*[row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new T[col];
	}
}


//Освобождаем память
template <class T>
Matrix<T>::~Matrix() {
	if (col > 0) {
		for (int i = 0; i < row; i++)
			delete[]matrix[i];
		delete[]matrix;
	}
}


//Перегружаем оператор +
template <class T>
Matrix<T>* Matrix<T>::operator+(const Matrix<T> &right) const {
	if (row != right.row || col != right.col) { //Проверяем размеры матриц
		cout << "Matrix dimensions don't allow sum!";
		exit(1);
	}
	else {
		Matrix *result = new Matrix<T>(row, col);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				result->matrix[i][j] = matrix[i][j] + right.matrix[i][j];
		return result;
	}
}

//Перегружаем оператор =
template <class T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &A) = default;

//Перегружаем оператор *
template <class T>
Matrix<T>* Matrix<T>::operator*(const Matrix<T> &right) const {
	Matrix *result = new Matrix<T>(row, right.col);
	int i, j, k;
	if (col == right.row) {
		//Заполняем результирующую матрицу нулями
		for (i = 0; i < row; i++)
			for (j = 0; j < right.col; j++)
				result->matrix[i][j] = 0;
		// Переходим к умножению. Идём по строкам левой матрицы
		for (i = 0; i < row; i++)
			// Идём по столбцам правой матрицы 
			for (j = 0; j < right.col; j++)
				// Идём по столбцам левой (и по строка правой) матрицы
				for (k = 0; k < col; k++)
					// Формируем очередной элемент результирующей матрицы
					result->matrix[i][j] += this->matrix[i][k] * right.matrix[k][j];
		return result;
	}
	else {
		cout << "Matrix dimensions don't allow multiplication!";
		exit(1);
	}
}

//Перегрузка оператора ввода
template <class T>
istream &operator>>(istream &input, Matrix<T> &A) {
	for (int i = 0; i < A.row; i++)
		for (int j = 0; j < A.col; j++)
			input >> A.matrix[i][j];
	return input;
}

//Перегрузка оператора вывода
template <class T>
ostream &operator<<(ostream& output, const Matrix<T> &A) {
	for (int i = 0; i < A.row; i++) {
		for (int j = 0; j < A.col; j++)
			output << setw(6) << A.matrix[i][j]; //Выделяем 6 ячеек для числа
		output << std::endl;
	}
	return output;
}

//Метод принимает статический массив и создает матрицу 
template <class T>
void Matrix<T>::Set(T in[]) {
	int k;
	for (int i = 0, k = 0; i < this->row; i++)
		for (int j = 0; j < this->col; j++) {
			this->matrix[i][j] = in[k];
			k++;
		}
}
//Метод выводит матрицу на экран
template <class T>
void Matrix<T>::Print() {
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++)
			cout << setw(8) << this->matrix[i][j]; //Выделяем 8 ячейки для числа
		cout << endl;
	}
}

//Формируем массив минимальных значений в каждой строке
template <class T>
void Matrix<T>::find_Min() {
	int i, j;
	T *min = new T[this->row];
	for (i = 0; i < this->row; i++)
		min[i] = this->matrix[i][0];

	for (i = 0; i < this->row; i++)
		for (j = 0; j < this->col; j++)
			if (this->matrix[i][j] <= min[i])
				min[i] = this->matrix[i][j];

	for (i = 0; i < this->row; i++)
		cout << setw(5) << min[i];
	cout << endl;
}


//Функция для генерации случайных чисел для матрицы нужного размера
stringstream Form_input(const int& rows, const int& columns) {
	stringstream input;
	for (int i = 0; i < rows*columns; i++)
		input << rand() % 20 << " ";
	return input;
}
