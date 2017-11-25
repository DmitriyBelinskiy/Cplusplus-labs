/* Создаем шаблон класса для Матрицы и перегружаем операторы ввода, вывода, а также: +,-,*,= */
#include "stdafx.h"
#include "MatrixT.h"
using namespace std;


int main()
{
	const int rows(3), columns(3);
	//Матрица int
	Matrix <int> A(rows, columns);
	int array1[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int array1[1] = { 1 };
	A.Set(array1);
	cout << A << endl;

	//Матрица double
	Matrix <double> B(rows, columns);
	double array2[12] = { 1.44,2.56,3.89,4.32,5.88,6.222,7.55,8.55,9.22 };
	B.Set(array2);
	cout << B << endl;

	//Матрица string
	Matrix <string> C(2, 2);
	string array3[4] = { "one", "two", "three", "four" };
	C.Set(array3);
	cout << C << endl;

	//Пример сложения матриц
	Matrix <int> D = *(A + A);
	cout << D << endl;

	//Заполняем матрицу случайными значениями
	Matrix <int> E(rows, columns);
	Form_input(rows, columns) >> E;

	//Пример умножения матриц
	Matrix <int> F = *(A*E);
	cout << F << endl;

	//Находим минимальные элементы в каждой строке в каждой из матриц
	A.find_Min();
	cout << endl;

	B.find_Min();
	cout << endl;

	C.find_Min();
	cout << endl;


	return 0;
}

