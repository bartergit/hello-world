#pragma once
#include<stdexcept>
using namespace std;

class ExeptoinAge : public exception
{
public:
	ExeptoinAge(char const* const Message);
	~ExeptoinAge();
};
