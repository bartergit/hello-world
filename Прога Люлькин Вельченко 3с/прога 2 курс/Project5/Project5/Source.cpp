/*Построить класс «Булев вектор» – BoolVector размерности  .
Опре-делить несколько конструкторов, в том числе конструктор копирова-ния.
Реализовать методы для выполнения поразрядных конъюнкции, дизъюнкции и отрицания векторов, а также подсчета числа единиц и нулей в векторе.
Реализовать те же действия над векторами с помощью перегруженных операций.
Перегрузить операции отношения и присва-ивания для данного класса.
Создать массив объектов. Передавать объ-екты в функцию, которая будет их изменять по формуле*/
#include <iostream> 
using namespace std;
class Bool_vector
{
	int n;
	int* array;
public:
	Bool_vector();
	Bool_vector(int n_, int * array_);
	Bool_vector(const Bool_vector & copy);
	~Bool_vector();
	void show();
	int NumberOfUnity();
	int NumberOfZeros();
	Bool_vector operator&(Bool_vector ob);
	Bool_vector operator|(Bool_vector ob);
	Bool_vector operator-();
	Bool_vector & operator=(const Bool_vector ob);
	Bool_vector modify(Bool_vector ob);
};

using namespace std;

//Конструктор без параметров 
Bool_vector::Bool_vector()
{
	n = 0;
	array = NULL;
}

// конструктор с параметрами 
Bool_vector::Bool_vector(int n_, int* array_)
{
	n = n_;
	array = new int[n];
	for (int i = 0; i < n; i++)
	{
		if (array_[i]) {
			array[i] = 1;
		}
		else array[i] = 0;
	}
}

//конструктор копирования 
Bool_vector::Bool_vector(const Bool_vector & copy)
{
	n = copy.n;
	array = new int[n + 1];
	if (!array) {
		cout << "Error";
	}
	for (int i = 0; i <= n; i++)
		array[i] = copy.array[i];
}

//деструктор 
Bool_vector::~Bool_vector()
{
	delete[] array;
}

//Вывод вектора 
void Bool_vector::show()
{
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << array[i] << "\t";
	}
	cout << endl;
	cout << "------------------------------------------------------" << endl;
	cout << endl;
}

//Возвращает количество единиц 
int Bool_vector::NumberOfUnity()
{
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (array[i]) k++;
	}
	return k;
}

int Bool_vector::NumberOfZeros()
{
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (!(array[i])) k++;
	}
	return k;
}

//Перегрузка оператора & 
Bool_vector Bool_vector::operator&(Bool_vector ob)
{

	if (this->n != ob.n) {
		cout << "Error of dimension" << endl;
		return Bool_vector();
	}
	int* newarr = new int[n];
	for (int i = 0; i < n; i++) {
		if (this->array[i] && ob.array[i]) newarr[i] = 1;
		else newarr[i] = 0;
	}
	Bool_vector result(n, newarr);
	return result;
}

Bool_vector Bool_vector::operator|(Bool_vector ob)
{
	if (this->n != ob.n) {
		cout << "Error of dimension" << endl;
		return Bool_vector();
	}
	int* newarr = new int[n];
	for (int i = 0; i < n; i++) {
		if (this->array[i] || ob.array[i]) newarr[i] = 1;
		else newarr[i] = 0;
	}
	Bool_vector result(n, newarr);
	return result;
}


Bool_vector Bool_vector::operator-()
{
	int* newarr = new int[n];
	for (int i = 0; i < n; i++) {
		if (this->array[i]) newarr[i] = 0;
		else newarr[i] = 1;
	}
	Bool_vector result(n, newarr);
	return result;
}

//Перегрузка оператора присваивания 
Bool_vector & Bool_vector::operator=(const Bool_vector ob)
{
	if (this == &ob)
	{
		return *this;
	}
	for (int i = 0; i < n; i++) {
		this->array[i] = ob.array[i];
	}
	return *this;
}

Bool_vector Bool_vector::modify(Bool_vector ob)
{
	return (*this)&(-ob);
}

void main()
{
	setlocale(0, "rus");
	const int n = 5;
	int array1[n] = { 1 ,2,0,-1,54 };
	int array2[n] = { 0,4,0,0,2 };
	Bool_vector obj1(n, array1);
	Bool_vector obj2(n, array2);
	obj1.show();
	obj2.show();
	cout  << "Количество единиц в 1 обьекте : " << obj1.NumberOfUnity() << endl;
	cout << "Количество нулей в 1 обьекте: " << obj1.NumberOfZeros() << endl;
	cout << "Перегруженое И "; (obj1&obj2).show();
	cout << "Перегруженое ИЛИ "; (obj1 | obj2).show();
	cout << "Перегруженое Отрицание "; (-obj2).show();
	cout << "Функция модифицирует по формуле: " << endl;
	(obj1.modify(obj2)).show();
	system("pause");
};