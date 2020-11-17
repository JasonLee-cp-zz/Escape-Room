#include "game.h"
#include "util.h"


int getch(void){ //getch function to constantly accept keyboard input for game control
struct termios oldt,newt;
 int ch;
 struct termios buf;
 struct termios save;
 tcgetattr(0,&save);
 buf = save;
 buf.c_lflag &= ~(ICANON|ECHO);
 buf.c_cc[VMIN]=1;
 buf.c_cc[VTIME]=0;
 tcsetattr(0,TCSAFLUSH, &buf);
 ch = getchar();
 tcsetattr(0,TCSAFLUSH, &save);
return ch;
}

void saveData(){ // Save score data to a file from hashmap
 if(first_open==true) return; //If open for the first time, don't save it
 fout.open(fileName.c_str());
for (auto i:mp) fout<<i.second <<" "<<i.first <<"\n"; //Copy data from map to the file
exit(1);
}


int keyControl(){
 int cur = getch(); //accept keyboard input
 
 //When different inputs are given, return UP/RIGHT/LEFT/DOWN/SHOOT/BOMB/SUBMIT according to their respective values defined in game.h
 if(cur=='w' || cur=='W') return UP; 
 else if(cur== 'd' || cur =='D') return RIGHT;
 else if(cur== 'a' || cur=='A') return LEFT;
 else if(cur== 's' || cur=='S') return DOWN;
 else if(cur== 'p' || cur == 'P') return SHOOT;
 else if(cur== 'o' || cur == 'O') return BOMB;
 else if(cur== ' ') return SUBMIT;
}


void titleDraw() { //Main Title draw
	cout << "\n\n\n\n";
	printf("\x1b[31m"); printf("\x1b[42m"); 
	cout << "		#######    #####   ####      #      ####    #####\n";
	cout << "		#         #       #         # #     #   #   #    \n";
	cout << "		#######    ####   #        #####    ####    #####\n";
	cout << "		#              #  #       #     #   #       #    \n";
	cout << "		#######   #####    ####  #       #  #       #####\n";
	printf("\x1b[0m");
}


int menuDraw() {
	int x = 35; //x coordinate for Game Options in the main menu
	int y = 12; //y coordinate for Game Options in the main menu
	printf("\x1b[31m"); 
	gotoxy(x - 2, y); // move -2 in x coordinate to print out "> " which takes two spaces
	cout << "> Game Start";
	gotoxy(x, y + 1); //+1 y
	cout << "About Game";
	gotoxy(x, y + 2); //+2 y
	cout << "EXIT\n\n";
	printf("\x1b[0m");
	
	
	while (true) { // Enable user to select the option by controlling (w,a,s,d) direction keys
		int cur = keyControl();
		switch (cur) {
		case UP: {
			if (y >= 13) { //When the cursor is not at the top, just move upward by one
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";
			}
			else if (y == 12) { //When the cursor position is at the top, go to the bottom
				gotoxy(x - 2, y); cout << " ";
				y += 2;
				gotoxy(x - 2, y); cout << ">";
			}

			break;
		}
		case DOWN: { //Same procedure with UP
			if (y <= 13) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			else if (y == 14) {
				gotoxy(x - 2, y); cout << " ";
				y -= 2;
				gotoxy(x - 2, y); cout << ">";
			}
			break;
		}
		case SUBMIT: { //When enter SPACE KEY, submit
			return y - 12;
			break;
		}
		}
	}
}
