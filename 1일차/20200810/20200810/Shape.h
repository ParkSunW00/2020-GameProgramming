#pragma once
class Shape
{
protected:
	int x, y;
public:
	void setOrigin(int x, int y) {
		this->x = x;
		this->y = y;
	}

	virtual void scale() { //가상함수
		cout << "Shape Draw" << endl;
	}
	virtual void scale() = 0; //순수가상함수

};

