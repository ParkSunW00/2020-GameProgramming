#pragma once
class NopersonException
{
private:
	int persons;
public:
	NopersonException(int p) { persons = p; }
	int getPersons() { return persons; }
};

