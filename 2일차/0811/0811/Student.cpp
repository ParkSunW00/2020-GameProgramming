#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>>
using namespace std;

bool getStu(ifstream& stuFile, int& stuID, int& exam1, int& exam2, int& finalExam) {
	stuFile >> stuID >> exam1 >> exam2 >> finalExam;
	if (!stuFile) {
		return false;
	}
	else {
		return true;
	}
}

void calcGrade(int exam1, int exam2, int finalExam, int& avg, char& grade) {
	avg = (exam1 + exam2 + finalExam) / 3;
	if (avg >= 90) {
		grade = 'A';
	}
	else if (avg >= 80) {
		grade = 'B';
	}
	else if (avg >= 70) {
		grade = 'C';
	}
	else if (avg >= 60) {
		grade = 'D';
	}
	else {
		grade = 'F';
	}
}
void writeStu(ofstream& gradesFile, int stuID, int avg, char grade) {
	gradesFile.fill('0');
	gradesFile << setw(4) << stuID;
	gradesFile.fill(' ');
	gradesFile << setw(3) << avg;
	gradesFile << ' ' << grade << endl;
}
int main() {
	ifstream stuFile;
	cout << "vmfhrmfoa tlwkr " << endl;
	stuFile.open("ch7STUFL.DAT");
	if (!stuFile) {
		cerr << "���Ͽ��¿���" << endl;
		exit(100);
	}
	ofstream gradesFile;
	gradesFile.open("ch7STUFL.DAT");
	if (!gradesFile) {
		cerr << "���Ͽ��¿���" << endl;
		exit(102);
	}
	int stuID, exam1, exam2, finalExam, avg;
	char grade;

	while (getStu(stuFile, stuID, exam1, exam2, finalExam)) {
		calcGrade(exam1, exam2, finalExam, avg, grade);
		writeStu(gradesFile, stuID, avg, grade);
	}
	stuFile.close();
	gradesFile.close();
	cout << "���α׷� ����" << endl;

	return 0;
}
