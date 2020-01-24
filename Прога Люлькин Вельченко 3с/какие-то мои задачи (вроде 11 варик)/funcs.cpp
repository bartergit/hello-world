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
#include "funcs.h"  //????


vector <File> getInfo(){
	vector <File> returnVector;
	std::ifstream fin("E:\\fileinfo.txt");
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
	}
	fin.close();
	return returnVector;
}

void function1(vector <File> filesVector){
	std::sort(filesVector.begin(), filesVector.end());
	for (int i = 0; i < filesVector.size(); i++){
		filesVector[i].show();
	}
}

void function2(){
	cout << "Type size value:\n";
	string stringChoice;
	std::cin >> stringChoice;
	int choice = atoi(stringChoice.c_str());
	cout <<"More then " << choice <<":\n";
}

void function3(){
	cout << "Type the number of references:\n";
	string stringChoice;
	std::cin >> stringChoice;
	int choice = atoi(stringChoice.c_str());
	cout <<"More then " << choice <<":\n";
}