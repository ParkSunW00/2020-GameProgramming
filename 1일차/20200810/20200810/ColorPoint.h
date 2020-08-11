#pragma once
#include "point.h"
class ColorPoint :public point
{
private:
	string color;
public:
	void setColor(string color) {
		this->color = color;
	}
	void showColorPoint() {
		cout << color << endl;
		showPoint();
	}
};

