#include <iostream>
#include <string>
#include "NopersonException.h"
using namespace std;

int main() {
	int pizza_slices = 0;
	int persons = -1;
	int slices_per_person = 0;

	try {
		cout << "���� ���� ���� �Է��ϼ���: ";
		cin >> pizza_slices;
		cout << "��� ���� �Է��ϼ���: ";
		cin >> persons;

		if (pizza_slices == 0)
			throw persons;
		slices_per_person = pizza_slices / persons;
		cout << "�� ����� ���ڴ� " << slices_per_person << "�� �Դϴ�" << endl;
	}

	/* if (pizza_slices > 0)
		slices_per_person = pizza_slices / persons; //����1 */

	catch (int e) { //persons�� type == e�� type
		cout << "����� " << e << "�� �Դϴ�." << endl;
	}
	return 0;

}