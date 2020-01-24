#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <vector>
using std::vector;
using std::string;
using std::cout;
#include "file.h"

//for date

void Date::checkValid(){
	if (!(month <= 12 && month >=1)) month = 1;
	if (!(day <= 31 && day >=1)) day = 1;
	if (year < 0) year = 2000;
}
Date::Date(int month,int day,int year):
	month(month),
	day(day),
	year(year){
	checkValid();
}
Date::Date(){
	month = 1;
	day = 1;
	year = 2000;
}
void Date::show(std::ostream& out){
	out << " "<< month << "." << day << "." << year <<" ";
}

//for file

File::File(string name, int size, unsigned int references, Date date):
	name(name),
	size(size),
	references(references),
	date(date){
}
File::File(){
	name = "noname";
	size = 0;
	references = 0;
	date = Date();
}
//SET functions
void File::set(string name, int size, unsigned int references, Date date){
	this->name = name;
	this->size = size;
	this->references = references;
	this->date = date;
}
void File::setName(string name){
	this->name = name;
}
void File::setSize(int size){
	this->size = size;
}
void File::setRef( unsigned int references){
	this->references = references;
}
void File::setDate(Date date){
	this->date = date;
}
//GET functions
string File::getName(){
	return name;
}
int File::getSize(){
	return size;
}
unsigned int File::getRef(){
	return references;
}
Date File::getDate(){
	return date;
}
//
void File::show() {
    std::ofstream fout("..\\log.txt", std::ofstream::app);
    try {
        if (fout.is_open()) {
            fout << name << "   " << size << "MB     " << references << "REF   ";
            date.show(fout);
            fout << "\n.........\n";
        } else
            throw 1;
    }
    catch(int err){
        cout << "some err\n";
    }
}
//
bool File::operator < (const File& oneClass) const{
    return (name < oneClass.name);
}
//func
vector <File> getInfo(){
	vector <File> returnVector;
	std::ifstream fin("C:\\_git\\working-stuff\\c++\\file-panel\\fileinfo.txt");
    if (fin.is_open()){
        cout << "Info recieved succesfully!\n";
        vector <string> line(6);
        short i = 0;
        while (getline(fin, line[i])){
            if (i == 5){
                i = 0;
                Date date(atoi(line[3].c_str()),atoi(line[4].c_str()),atoi(line[5].c_str()));
                returnVector.push_back(File(line[0],atoi(line[1].c_str()),atoi(line[2].c_str()),date));
            }
            else
                i++;
        }
        fin.close();
    }
    else
        throw 404;
	return returnVector;
}

void function1(vector <File> filesVector){
	std::sort(filesVector.begin(), filesVector.end());
	for (int i = 0; i < filesVector.size(); i++){
		filesVector[i].show();
	}
}

void function2(vector <File> filesVector){
	cout << "Type size value:\n";
	string stringChoice;
	std::cin >> stringChoice;
	int choice = atoi(stringChoice.c_str());
	cout <<"More then " << choice <<":\n";
	for (int i = 0; i < filesVector.size(); i++){
		if (filesVector[i].getSize()> choice)
			filesVector[i].show();
	}
}

void function3(vector <File> filesVector){
	cout << "Type the number of references:\n";
	string stringChoice;
	std::cin >> stringChoice;
	int choice = atoi(stringChoice.c_str());
	//cout <<"More then " << choice <<":\n";
	for (int i = 0; i < filesVector.size(); i++){
		if (filesVector[i].getRef() > choice)
			filesVector[i].show();
	}
}