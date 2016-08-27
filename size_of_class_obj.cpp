#include <iostream>
using namespace std;

class empty {};

class derived1: public empty{};
class derived2 : virtual public empty {};
class derived3 :public empty {
	char c;
	int b;
};
class derived4 :virtual public empty {
	int c;
	char b;
};
class Dummy
{
	char c;
};

int main()
{
	class empty obj0;
	class derived1 obj1;
	class derived2 obj2;
	class derived3 obj3;
	class derived4 obj4;
	class Dummy obj5;

	cout << "sizeof(Empty) " << sizeof(class empty) << endl << sizeof(obj0) <<endl;  // 1,1
	cout << "sizeof(Derived1) " << sizeof(derived1) << endl << sizeof(obj1) <<endl;  // 1,1
	cout << "sizeof(Derived2) " << sizeof(derived2) << endl << sizeof(obj2) << endl; // 4,4 virtual base class pointer
	cout << "sizeof(Derived3) " << sizeof(derived3) << endl << sizeof(obj3) << endl; // 8,8 size of int + char + padding
	cout << "sizeof(Derived4) " << sizeof(derived4) << endl << sizeof(obj4) << endl; // 12,12 virtual base class pointer + size of int + char + padding
	cout << "sizeof(Dummy) " << sizeof(Dummy) << endl << sizeof(obj5) << endl; // 1,1 size of char

	cin.get();

	return 0;
}
