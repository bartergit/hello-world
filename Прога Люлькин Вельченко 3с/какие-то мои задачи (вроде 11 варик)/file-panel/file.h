#pragma once
#include <string>
#include <vector>

class Date{
private:
	int month, day, year;
	void checkValid();
public:
	Date(int month,int day,int year);
	Date();
    void show(std::ostream& out);
};
//
class File{
private:
	std::string name;
	int size;
	unsigned int references;
	Date date;
public:
	File(std::string name, int size, unsigned int references, Date date);
	File();
	//SET functions
	void set(std::string name, int size, unsigned int references, Date date);
	void setName(std::string name);
	void setSize(int size);
	void setRef( unsigned int references);
	void setDate(Date date);
	//GET functions
	std::string getName();
	int getSize();
	unsigned int getRef();
	Date getDate();
	//
	void show();
	//
	bool operator < (const File& oneClass) const;
};


std::vector <File> getInfo();
void function1(std::vector <File> filesVector);
void function2(std::vector <File> filesVector);
void function3(std::vector <File> filesVector);