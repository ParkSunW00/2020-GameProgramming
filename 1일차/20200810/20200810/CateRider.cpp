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
		cout << "������ȣ��" << endl;
		speed = 0;
		gear = 1;
		color = "white";
	}

	~Car() {
		cout << "�Ҹ���ȣ��" << endl;
		delete p;

	}
	int getSpeed();//�����ڼ���
	void setSpeed(int s);//�����ڼ���

	int getGear();//�����ڼ���
	void setGear(int g); //�����ڼ���

	string getColor(); //�����ڼ���
	void setColor(string c);

	void speedUp(); //�ӵ����� ��� �Լ�
	void speedDown();//�ӵ����� ��� �Լ�
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
		cout << "�ӵ�:" << speed << endl;
		cout << "���:" << gear << endl;
		cout << "����:" << color << endl;
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
	cout << "car1�� �¸���" << end;
	}
	else {
		cout << "car2�� �¸���" << endl;
	}
	delete a;
	return 0;

}
