#include <iostream>
#include <string>
#include "NopersonException.h"
using namespace std;

int main() {
	int pizza_slices = 0;
	int persons = -1;
	int slices_per_person = 0;

	try {
		cout << "피자 조각 수를 입력하세요: ";
		cin >> pizza_slices;
		cout << "사람 수를 입력하세요: ";
		cin >> persons;

		if (pizza_slices == 0)
			throw persons;
		slices_per_person = pizza_slices / persons;
		cout << "한 사람당 피자는 " << slices_per_person << "개 입니다" << endl;
	}

	/* if (pizza_slices > 0)
		slices_per_person = pizza_slices / persons; //예외1 */

	catch (int e) { //persons의 type == e의 type
		cout << "사람이 " << e << "명 입니다." << endl;
	}
	return 0;

}