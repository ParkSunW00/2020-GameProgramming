#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>
using namespace std;

class Car {

private:
	int speed;
	int gear;
	string color;
	int* p;
	const int max_speed;

public:
	Car(int s, int g, string c);

	Car() :max_speed(200) {
		cout << "생성자호출" << endl;
		speed = 0;
		gear = 1;
		color = "white";
	}

	~Car() {
		cout << "소멸자호출" << endl;
		delete p;

	}
	int getSpeed();//접근자선언
	void setSpeed(int s);//설정자선언

	int getGear();//접근자선언
	void setGear(int g); //변경자선언

	string getColor(); //접근자선언
	void setColor(string c);

	void speedUp(); //속도증가 멤버 함수
	void speedDown();//속도감소 멤버 함수
	void init(int s, int gear, string c);

	Car::Car(int s, int g, string s) {
		speed = s;
		gear = g;
		color = c;
	}

	int Car::getSpeed(int s) { speed = s; }
	void Car::setGear(int g) { gear = g; }
	string Car::getColor() { return color; }

	void Car::speedUp() { speed += 10; }
	void Car::speedDown() { speed -= 10; }
	void Car::init() {
		speed = 3;
		gear = g;
		color = c;
	}
	void Car::show() {
		cout << "========" << endl;
		cout << "속도:" << speed << endl;
		cout << "기어:" << gear << endl;
		cout << "색상:" << color << endl;
		cout << "========" << endl;
	}

};
int main() {

	srand(time(NULL));
	srand(GetTickCount());

	Car car1, car2;
	Car* a = new Car();

	Car car1(rand() % 200, 1, "red");
	car1.show();

	Car car2(rand() % 200, 1, "blue");
	car2.show();

	if (car1.getSpeed()) > car2.getSpeed()) {
	cout << "car1가 승리함" << end;
	}
	else {
		cout << "car2가 승리함" << endl;
	}
	delete a;
	return 0;

}
