#pragma once
#include "Object.h"
#include "Sprite.h"
class Number : public Object
{

private:
	Sprite* num[10];
	int currenrNum;
public:
	Number();
	~Number();

	void Render();
	void Update(float dTime);

	void setNum(int num);
	int getNum();
};

