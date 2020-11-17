#include "main.h"
#include <iostream>
using namespace std;

//MAIN FUNCTION
int main() {
	system("clear");
	while (true) {
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) { //0 -> game start
			gamePlay();
		}
		else if (menuCode == 1) { //1 -> game info
			gameInfo();
		}
		else { //2 -> exit
			saveData();
			printf("\033c");
			return 0;
		}
		printf("\033c");
	}
	return 0;
}
