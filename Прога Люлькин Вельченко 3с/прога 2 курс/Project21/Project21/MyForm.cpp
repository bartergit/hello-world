#include "MyForm.h"                    //            The header file of the form

/*
8.	Преобразовать одномерный массив таким образом, чтобы сначала располагались все положительные элементы,
а потом – все отрицательные.
*/
using namespace System;
using namespace System::Windows::Forms;
using namespace UI_Project;            //            The name of the namespace in MyForm.h
[STAThreadAttribute]                   //            Run this program in STA mode
int main() {
	MyForm fm;                     //            The form to be created and shown
	fm.ShowDialog();             //            Show the form
	return 0;
}