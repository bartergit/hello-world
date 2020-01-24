#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
using std::string;
using std::cout;

template <typename T>
struct Node{
    T x;
    Node *Next, *Prev;
};

template <typename T>
class List{
    int size;
    Node<T> *Head, *Tail;
    string str;
public:
    List():size(0),Head(NULL),Tail(NULL),str(""){};
    List(string str);
    ~List();
    void show();
    void specialShow();
    void push(T x);
    void pop(T x);
    T getTail();
    T getHead();
    bool isEmpty();
    int getSize();
    T& operator[](int n);
    void erase(int n);
    void insert(int n, T value);
};

template <typename T>
List<T>::List(string str):Head(NULL),Tail(NULL),str(str),size(0){
    std::ifstream fin(str);
    double temp;
    if (fin.is_open()){
        while(!fin.eof()){
            fin >> temp;
            this->push(temp);
        }
    }
    fin.close();
}

template <typename T>
List<T>::~List(){
    std::ofstream fout;
    if (str!=""){
        fout.open(str);
    }
    bool flag = false;
    while (Head){
        if (fout.is_open()){
            if (flag)
                fout << "\n";
            else
                flag = true;
            fout << Head->x;
        }
        Tail = Head->Next;
        delete Head;
        Head = Tail;
    }
    fout.close();
}

template <typename T>
void List<T>::push(T x){
    size++;
    Node<T> *temp = new Node<T>;
    temp->Next = NULL;
    temp->x = x;
    if (Head != NULL){
        temp->Prev = Tail;
        Tail->Next = temp;
        Tail = temp;
    }
    else{
        temp->Prev = NULL;
        Head = Tail = temp;
    }
}

template <typename T>
void List<T>::pop(T x){
    size++;
    Node<T> *temp = new Node<T>;
    temp->Prev = NULL;
    temp->x = x;
    if (Tail != NULL){
        temp->Next = Head;
        Head->Prev = temp;
        Head = temp;
    }
    else{
        temp->Next = NULL;
        Tail = Head = temp;
    }
}

template <typename T>
T List<T>::getTail(){
    return Tail->x;
}

template <typename T>
T List<T>::getHead(){
    return Head->x;
}

template <typename T>
bool List<T>::isEmpty() {
    return size;
}

template <typename T>
T& List<T>::operator[](int n){
    Node<T> *temp = Head;
//    assert ((n < size && n >= 0) || (-n < size + 1 && n < 0));
    try{
        if (!((n < size && n >= 0) || (-n < size + 1 && n < 0))) {
            throw 3;
        }
        if (n < 0){
            temp = Tail;
            for (int i = 1; i < abs(n); i++) {
                temp = temp->Prev;
            }
        }
        else {
            temp = Head;
            for (int i = 0; i < n; i++) {
                temp = temp->Next;
            }
        }
    }
    catch(...) {
        cout << "Out of range!!\n";
    }
    return temp->x;
}

template <typename T>
int List<T>::getSize(){
    return size;
}

template <typename T>
void List<T>::erase(int n){
    Node<T> *temp;
//    assert ((n < size && n >= 0) || (-n < size + 1 && n < 0));
    try {
        if (!((n < size && n >= 0) || (-n < size + 1 && n < 0))) {
            throw 3;
        }
        if (n < 0) {
            temp = Tail;
            for (int i = 1; i < abs(n); i++) {
                temp = temp->Prev;
            }
        } else {
            temp = Head;
            for (int i = 0; i < n; i++) {
                temp = temp->Next;
            }
        }
        if (temp == Head) {  // head tail
            Head = temp->Next;
            Head->Prev = NULL;
        } else if (temp == Tail) {
            Tail = temp->Prev;
            Tail->Next = NULL;
        } else {
            temp->Prev->Next = temp->Next;
            temp->Next->Prev = temp->Prev;
        }
        size--;
    }
    catch(...){
        cout <<"Cannot be erased\n";
    }
}


template <typename T>
void List<T>::insert(int n, T value){
    Node<T> *temp;
    Node<T> *temp2;
//    assert ((n < size && n >= 0) || (-n < size + 1 && n < 0));
    try{
        if (!((n < size && n >= 0) || (-n < size + 1 && n < 0))) {
            throw 3;
        }
        temp = Head;
        for (int i = 0; i < n; i++) {
            temp = temp->Next;
        }
        Node<T> *newNode = new Node<T>;
        newNode->x = value;
        temp2 = temp->Prev;
        temp->Prev = newNode;
        temp2->Next = newNode;
        newNode->Next = temp;
        newNode->Prev = temp2;
        size++;
    }
    catch(int err){
        cout << "Error. Nothing inserted\n";
    }
}

template <typename T>
void List<T>::show(){
    std::ofstream fout("..\\log2.txt", std::ofstream::app);
    Node<T> *temp2 = Head;
    while (temp2 != NULL) {
        fout << temp2->x << " ";
        temp2 = temp2->Next;
    }
    fout << "\n";
}

template <typename T>
void List<T>::specialShow(){
    Node<int>* temp=Head;
    Node<int>* temp2=Tail;
    int i = size;
    while (i){
        cout << temp->x << " ";
        i--;
        if (!i) break;
        i--;
        cout << temp2->x << " ";
        temp = temp->Next;
        temp2 = temp2->Prev;
    }
    cout << "\n";
}

int main () {
    List<double> list("C:\\text.txt"); //"C:\\text.txt"
    list.show();
    List<double> list2;
    bool flag = true;
    for (int i = 0; i < list.getSize();) {
        if (flag) {
            flag = false;
            list2.push(list[i]);
            i++;
        } else {
            flag = true;
            list2.push(list[-i]);
        }
    }
    list2.push(list[0]);
    list2.show();
    //list[15];
    List<int> list3;
    list3.push(2);
    list3.push(11);
    list3.push(15);
    list3.show();
	List<char> list4;
	list4.push('A');
	list4.push('b');
	list4.push('j');
    list4.show();
	list4.erase(10);
}
