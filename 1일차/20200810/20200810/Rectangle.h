#pragma once
#include "Shape.h"
class Rectangle :
	public Shape
{
private:
	ind width, height;
public:
	void setWidth(int w) { width = w; }
	void setHeight(int h) { height = h; }
	void draw() {
		cout << "Rectangle Draw" << endl;
	}
};

