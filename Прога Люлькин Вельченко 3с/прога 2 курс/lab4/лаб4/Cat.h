#pragma once
class Cat
{
	int age;
	char* name;
public:
	Cat();
	Cat(int, char*);
	Cat(const Cat&);
	~Cat();
	char* toString();
	int compare(Cat);
	Cat& operator=(Cat&);
};

