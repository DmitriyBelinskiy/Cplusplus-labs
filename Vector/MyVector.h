#pragma once
#include <iostream>

class MyVector
{
public:
	//������������
	MyVector();
	//��������� ������ ������
	MyVector(const MyVector&);
	//��������� �������
	MyVector(const int&);
	~MyVector();

	//���������� ������� � ����� �������
	void push_back(const int&);
	//�������� �� ����� ������� � ������� ��� �� �������
	int pop_back();
	//��������� ������� �� �������
	int get_element(const int&);
	//������� ��� �������� � �������
	void print() const;

	//��������� � �������� ������� �����
	void copy_in(const MyVector&);
	//��������� ��������� ��������
	bool element_check(const int&) const;
	//��������� ������ �������
	int size() const;

	//���������� ����������
	MyVector &operator=(MyVector&);
	MyVector *operator+(MyVector&);
	MyVector *operator*(const MyVector&) const;


private:
	//��������� �� ������ �������
	int *p_begin;
	//������ �������
	int v_size;

};

//+=   - ���������� ���������� �������� � ������
//-=   - ������� ���������
