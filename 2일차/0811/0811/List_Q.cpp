#include <iostream>
#include <list>
using namespace std;

int main() {
	bool done = false;
	char command;
	int value;
	list<int>commanList;

	while (!done) {
		cout << "명령어를 입력하세요 [ I) insert P) print L) length E) erase Q) quit ] : ";
		cin >> command;
		switch (command) {
		case 'I':
		case 'i':
			if (cin >> value)
				commanList.push_back(value);
			else
				done = true;
		case 'P':
		case 'p':
			for (const auto& elem : commanList) {
				cout << elem << ' ';
			}
			cout << endl;
			break;
		case 'L':
		case 'l':
			cout << "Number of Elements : " << commanList.size() << endl;
			break;
		case 'E':
		case 'e':
			commanList.clear();
			break;
		case 'Q':
		case 'q':
			done = true;
			break;
		}
	}
	return 0;
}