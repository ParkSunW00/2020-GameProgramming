#include <iostream>
#include "DataManager.h"
int main() {
	cout << "플레이어 레벨: " << DataMgr->getLevel() <<'\n';
	cout << "플레이어 exp: " << DataMgr->getExp();
	return 0;
}
