#include "main.h"
#include <iostream>
using namespace std;

//MAIN FUNCTION
int main() {
	system("clear"); //clear screen when started
	while (true) {
		titleDraw(); //Draw the main page
		int menuCode = menuDraw(); //menuCode returns an integer which decides the game control function (game play/game info/exit)
		if (menuCode == 0) { //0 -> game start
			gamePlay();
		}
		else if (menuCode == 1) { //1 -> game info
			gameInfo();
		}
		else { //2 -> exit
			saveData(); //Save score data to a file when exit
			printf("\033c");
			return 0;
		}
		printf("\033c");
	}
	return 0;
}
