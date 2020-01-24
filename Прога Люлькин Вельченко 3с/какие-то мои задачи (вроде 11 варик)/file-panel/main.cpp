#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <list>
#include "file.h"
using std::list;
using std::vector;
using std::string;
using std::cout;

int main(){
    system("chcp 65001");
    cout << "Поддерживает русский! \n";
	bool state = true;
	try {
        vector<File> filesVector = getInfo();
        while (state) {
            string stringChoice;
            cout << "Type '1' for 1) files in alphabetical order \n";
            cout << "Type '2' for 2) files with size more then...\n";
            cout << "Type '3' for 3) files with number of references more then...\n";
            cout << "Type '4' for get out of here \n";
            std::cin >> stringChoice;
            int choice = atoi(stringChoice.c_str());
            switch (choice) {
                case 1:
                    function1(filesVector);
                    break;
                case 2:
                    function2(filesVector);
                    break;
                case 3:
                    function3(filesVector);
                    break;
                case 4:
                    state = false;
                    break;
                default:
                    cout << " Hard to understand. Check out your gramma and try again.\n";
                    break;
            }
        }
    }
    catch(int error){
        cout << "Errorname " << error << " Cannot link with this file\n";
    }
}


