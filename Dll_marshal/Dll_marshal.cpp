#include "pch.h"
#include "Dll_marshal.h"


_declspec(dllexport)
int func_summ(const int a, const int b) {
	return a + b;
}