#include "NopersonException.h"
int main() {
	int pizza_slices = 12;
	int persons = 0;
	int slices_per_person = 0;

	try {
		cout << "���� ���� ���� �Է��ϼ���: ";
		cin >> pizza_slices;
		cout << "��� ���� �Է��ϼ���: ";
		cin >> persons;
		if (persons <= 0) {
				throw NopersonException(persons);

				slices_per_person = pizza_slices / persons;
				cout << "�� ����� ���ڴ� " << slices_per_person << "�Դϴ�" << endl;
		}
		catch (NopersonException e) {
			cout << "���� : ����� " << e.getPersons() << "���Դϴ�." << endl;
		}
	}
	return 0;
}