#include <iostream>
using namespace std;

class A {
public :
	A() { cout << "持失切A" << endl; }
	~A() { cout << "社瑚切A" << endl; }
};
class B : public A {
public:
	B() { cout << "持失切B" << endl; }
	~B() { cout << "社瑚切B" << endl; }
};
class C :public B {
public:
	C() { cout << "持失切C" << endl; }
	~C() { cout << "社瑚切C" << endl; }
};
int main() {
	C c;
	return 0;
}