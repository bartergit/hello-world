#include "MyForm.h"                    //            The header file of the form
using namespace UI_Project;            //            The name of the namespace in MyForm.h
[STAThreadAttribute]                   //            Run this program in STA mode
int main() {
	MyForm fm;                     //            The form to be created and shown
	fm.ShowDialog();             //            Show the form
	return 0;
}