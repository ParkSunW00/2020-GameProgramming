#include "NopersonException.h"
int main() {
	int pizza_slices = 12;
	int persons = 0;
	int slices_per_person = 0;

	try {
		cout << "피자 조각 수를 입력하세요: ";
		cin >> pizza_slices;
		cout << "사람 수를 입력하세요: ";
		cin >> persons;
		if (persons <= 0) {
				throw NopersonException(persons);

				slices_per_person = pizza_slices / persons;
				cout << "한 사람당 피자는 " << slices_per_person << "입니다" << endl;
		}
		catch (NopersonException e) {
			cout << "오류 : 사람이 " << e.getPersons() << "명입니다." << endl;
		}
	}
	return 0;
}