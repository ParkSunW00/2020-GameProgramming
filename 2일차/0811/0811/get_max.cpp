#include <iostream>
#include <string>
using namespace std;
template<typename T> //typename or class 가능
T get_max(T x, T y) {
	if (x > y)
		return x;
	else
		return y;
}

template <typename T1, typename T2>
void ShowData(T1 t1, T2 t2) {
	cout << t1 << " + " << t2 << endl;
}
int main() {
	 /*int x, y;
	float x1, y1;

	cin >> x >> y;
	cout << "정수 중 가장 큰 수:" << get_max<int>(x, y) << endl;
	cin >> x1 >> y1;
	cout << "실수 중 가장 큰 수:" << get_max<float>(x1, y1) << endl; */

	char c;
	int a;
	float b;

	cin >> a >> b >> c;
	ShowData<int,float>(a, b);
	ShowData<float,char>(b, c);
	ShowData<int,char>(a, c);

	return 0;
}