#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void SaveFile() {
	string s;
	ofstream o("abc.txt");
	cout << "파일에 입력할 문장을 써주세요:";
	cin >> s;
	for (int i = 0; i < 3; i++) {
		o << s << endl;
	}
	o.close();
}

void ReadFile() {
	string s;
	ifstream i("abc.txt");
	if (i.is_open()) {
		while (getline(i, s)) {
			cout << s << endl;
		}
	}
	i.close();
}

int mian() {
	ReadFile();
	//SaveFile();
	return 0;
}