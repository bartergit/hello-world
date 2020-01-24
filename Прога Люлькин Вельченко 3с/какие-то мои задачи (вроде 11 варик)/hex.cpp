#include <iostream>
//#include <map>
//using std::pair;
//using std::map;
using std::cout;

class Hex {
private:
	//map <int,char> dict;
	unsigned int decimal;
	char* array;
public:
	char* getHex() {
		return this->array;
	}
	unsigned int dec() {
		return this->decimal;
	}
	Hex(unsigned int x) {
		//dict.insert(pair<int, char>(10, 'a'));
		this->decimal = x;
		this->array = convert(x);
	}
	char* convert(unsigned int x) {
		//char* array = new char[14]{ "Hello, world!" };
		int remainder;
		short size = 0;
		while (true) {
			x /= 16;
			size++;
			if (x == 0) break;
		}
		x = this->decimal;
		this->array = new char[size+1];
		for (short i = size - 1; i >= 0; i--) {
			remainder = x % 16;
			x /= 16;
			if (remainder < 10)
				array[i] = '0' + remainder;
			else
				array[i] = 55 + remainder;
		}
		array[size] = '\0';
		return array;
	}
	Hex operator+(Hex anotherHex){
		return Hex(this->dec()+anotherHex.dec());
	}
	Hex operator-(Hex anotherHex) {
		return Hex(this->dec() - anotherHex.dec());
	}
	Hex operator*(Hex anotherHex) {
		return Hex(this->dec() * anotherHex.dec());
	}
	Hex operator/(Hex anotherHex) {
		return Hex(this->dec() / anotherHex.dec());
	}
	bool operator==(Hex anotherHex) {
		return this->dec() == anotherHex.dec();
	}
	bool operator!=(Hex anotherHex) {
		return !(*this == anotherHex);
	}
	bool operator<(Hex anotherHex) {
		return (this->dec() < anotherHex.dec());
	}
	bool operator>(Hex anotherHex) {
		return !(*this < anotherHex);
	}
};

int main()
{
	Hex h140(140);
	cout << "140 is " << h140.getHex() << "\n";
	Hex h200(200);
	cout << "200 is " << h200.getHex() << "\n";
	cout << "200 - 140 is " << (h200 - h140).getHex() << "\n";
	cout << "200 + 140 is " << (h200 + h140).getHex() << "\n";
	cout << "200 * 140 is " << (h200 * h140).getHex() << "\n";
	cout << "200 / 140 is " << (h200 / h140).getHex() << "\n";
    cout << "200 < 140 is "	<< (h200 < h140) << "\n";
    cout << "200 > 140 is "	<< (h200 > h140) << "\n";
    cout << "200 == 200 is " << (h200 == h200) << "\n";
    cout << "200 == 140 is " << (h200 == h140) << "\n";
    cout << "200 != 140 is " << (h200 != h140) << "\n";
}