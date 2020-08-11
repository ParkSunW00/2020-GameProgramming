#include <fstream>
#include <string>
#define DataMgr DataManager::instance()
using namespace std;

class DataManager
{
private:
	string name = "�÷��̾�";
	int level = 37;
	int exp = 100000;
public:
	DataManager() {

	}
	static DataManager* instance() {
		static DataManager inst;
		return &inst;
	}
	int getLevel() {
		return level;
	}
	int getExp() {
		return exp;
	}
};

