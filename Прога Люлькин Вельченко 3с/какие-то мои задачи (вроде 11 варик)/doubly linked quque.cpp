//Реализовать шаблон двусторонней очереди на основе двусвязного списка.
//Перегрузить операции ввода/вывода. Продемонстрировать не менее двух
//инстанцирований шаблона с разными аргументами и вызов всех методов.
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
    void push_back(T x);
    void push_front(T x);
    T getTail();
    T getHead();
    bool isEmpty();
    int getSize();
    T pop_front();
    T pop_back();
};

template <typename T>
List<T>::List(string str):Head(NULL),Tail(NULL),str(str),size(0){
    std::ifstream fin(str);
    double temp;
    if (fin.is_open()){
        while(!fin.eof()){
            fin >> temp;
            this->push_back(temp);
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
void List<T>::push_back(T x){
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
void List<T>::push_front(T x){
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
    return !size;
}

template <typename T>
int List<T>::getSize(){
    return size;
}

template <typename T>
T List<T>::pop_front() {
    try {
        if (isEmpty())
            throw 1;
        if (getSize() == 1){
            T temp = Tail->x;
            Tail = NULL;
            Head = NULL;
            size --;
            return temp;
        }
        else {
            T temp = Head->x;
            Head = Head->Next;
            Head->Prev = NULL;
            size--;
            return temp;
        }
    }
    catch (...) {
        cout << "Cannot be popped\n";
        return (T) (0);
    }
}

template <typename T>
T List<T>::pop_back() {
    try {
        if (isEmpty())
            throw 1;
        if (getSize() == 1){
            T temp = Tail->x;
            Tail = NULL;
            Head = NULL;
            size --;
            return temp;
        }
        else{
            T temp = Tail->x;
            Tail = Tail->Prev;
            Tail->Next = NULL;
            size--;
            return temp;
        }
    }
    catch (...) {
        cout << "Cannot be popped\n";
        return (T)0;
    }
}


template <typename T>
void List<T>::show(){
    Node<T> *temp2 = Head;
    while (temp2 != NULL) {
        cout << temp2->x << " ";
        temp2 = temp2->Next;
    }
    cout << "\n";
}

int main () {
    List<double> list("C:\\text.txt"); //"C:\\text.txt"
    list.show();
    List<int> list3;
    list3.push_back(2);
    list3.push_back(11);
    list3.push_front(5);
    list3.push_back(19);
    list3.pop_back();
    list3.pop_front();
    list3.show();
    List<char> list4;
    list4.push_back('A');
    list4.push_front('b');
    list4.push_front('j');
    cout << list4.pop_back();
    cout << list4.pop_front();
    cout << list4.pop_back();
    list4.show();
}


//
// Created by Lenovo on 13.12.2019.
//

