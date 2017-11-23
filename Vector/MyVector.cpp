#include "stdafx.h"
#include "MyVector.h"


MyVector::MyVector()
{
	v_size = 0;
}

MyVector::MyVector(const int& new_el) {
	v_size = 1;
	p_begin = new int[v_size];
	p_begin[0] = new_el;
}

MyVector::MyVector(const MyVector& in) {
	v_size = in.v_size;
	p_begin = new int[v_size];
	for (int i = 0; i < v_size; i++) {
		p_begin[i] = in.p_begin[i];
	}
}


MyVector::~MyVector()
{
	if (v_size != 0)
		delete[]p_begin;
	std::cout << "destructed" << std::endl;
}

void MyVector::push_back(const int& new_el) {
	v_size = v_size + 1;
	if (v_size-1 != 0) {		
		int *temp = p_begin;
		p_begin = new int[v_size];
		for (int i = 0; i < v_size-1; i++)
			p_begin[i] = temp[i];
		delete[]temp;
	} else {
	p_begin = new int[v_size];
	}
	p_begin[v_size-1] = new_el;
}

void MyVector::print() const {
	for (int i = 0; i < v_size; i++)
		std::cout << p_begin[i] << " ";
	std::cout << std::endl;
}

int MyVector::size() const {
	return this->v_size;
}

int MyVector::pop_back() {
	if (v_size != 0) {
		int result = p_begin[v_size - 1];
		int *temp = p_begin;
		v_size = v_size - 1;
		if (v_size == 0)			
			delete[]p_begin;
		p_begin = new int[v_size];
		for (int i = 0; i < v_size - 1; i++)
			p_begin[i] = temp[i];
		
		return result;
		
	}
	else {
		throw std::logic_error("Vector is empty");
	}

}