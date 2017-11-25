#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
using namespace std;


//������� ����� ��� ������
template <class T>
class Matrix {
public:
	Matrix(int, int); //����������� � �����������
	~Matrix(); //����������� ������

			   //����������� ���������
	Matrix* operator+(const Matrix &) const; //��������
	Matrix &operator=(const Matrix &); //������������
	Matrix* operator*(const Matrix &) const;//���������

	//��������� ������ "<>", ����� �� ������� �����������. ����� ����� ��������� ���������� ���������� ������ ������.
	friend istream &operator>><>(istream &, Matrix &); 
	friend ostream &operator<<<>(ostream &, const Matrix &); //��������� ������ "<>", ����� �� ������� �����������

	//������� ������ ��� ���������� ������� �� ������������ ������� � ����� �� �� �����
	void Set(T[]);
	void Print();

	void find_Min();

private:
	int col, row;
	T **matrix;
};

//������� ��� ��������� ��������� ����� ��� ������� ������� ������� (�� ������ ������)
stringstream Form_input(const int&, const int&);

//�������� ������ ��� ������� ���������� �������
template <class T>
Matrix<T>::Matrix(int r, int c) : row(r), col(c) {
	matrix = new T*[row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new T[col];
	}
}


//TODO ����������� ������
template <class T>
Matrix<T>::~Matrix() {
	if (col > 0) {
		for (int i = 0; i < row; i++)
			delete[]matrix[i];
		delete[]matrix;
	}
}


//����������� �������� +
template <class T>
Matrix<T>* Matrix<T>::operator+(const Matrix<T> &right) const {
	if (row != right.row || col != right.col) { //��������� ������� ������
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

//����������� �������� =
template <class T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &A) = default;

//����������� �������� *
template <class T>
Matrix<T>* Matrix<T>::operator*(const Matrix<T> &right) const {
	Matrix *result = new Matrix<T>(row, right.col);
	int i, j, k;
	if (col == right.row) {
		//��������� �������������� ������� ������
		for (i = 0; i < row; i++)
			for (j = 0; j < right.col; j++)
				result->matrix[i][j] = 0;
		// ��������� � ���������. ��� �� ������� ����� �������
		for (i = 0; i < row; i++)
			// ��� �� �������� ������ ������� 
			for (j = 0; j < right.col; j++)
				// ��� �� �������� ����� (� �� ������ ������) �������
				for (k = 0; k < col; k++)
					// ��������� ��������� ������� �������������� �������
					result->matrix[i][j] += this->matrix[i][k] * right.matrix[k][j];
		return result;
	}
	else {
		cout << "Matrix dimensions don't allow multiplication!";
		exit(1);
	}
}

//���������� ��������� �����
template <class T>
istream &operator>>(istream &input, Matrix<T> &A) {
	for (int i = 0; i < A.row; i++)
		for (int j = 0; j < A.col; j++)
			input >> A.matrix[i][j];
	return input;
}

//���������� ��������� ������
template <class T>
ostream &operator<<(ostream& output, const Matrix<T> &A) {
	for (int i = 0; i < A.row; i++) {
		for (int j = 0; j < A.col; j++)
			output << setw(6) << A.matrix[i][j]; //�������� 6 ����� ��� �����
		output << std::endl;
	}
	return output;
}

//����� ��������� ����������� ������ � ������� ������� 
template <class T>
void Matrix<T>::Set(T in[]) {
	int k;
	for (int i = 0, k = 0; i < this->row; i++)
		for (int j = 0; j < this->col; j++) {
			this->matrix[i][j] = in[k];
			k++;
		}
}
//����� ������� ������� �� �����
template <class T>
void Matrix<T>::Print() {
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++)
			cout << setw(8) << this->matrix[i][j]; //�������� 8 ������ ��� �����
		cout << endl;
	}
}

//��������� ������ ����������� �������� � ������ ������
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


//������� ��� ��������� ��������� ����� ��� ������� ������� �������
stringstream Form_input(const int& rows, const int& columns) {
	stringstream input;
	for (int i = 0; i < rows*columns; i++)
		input << rand() % 20 << " ";
	return input;
}
