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


string userInfo() { //Accept user Info
	gotoxy(30, 10);
	string user;
	printf("\x1b[32m");
	cout << "Enter Username: ";
	printf("\x1b[0m");
	getline(cin, user);
	return user;
}

void itemGen(vector<string>& board) { //Iten Random Generator
	int cnt = 30; //30 Items Total
	int ranX;
	int ranY;

	while (cnt > 0) {
		//Accept random ranX, ranY variables
		int ranX = 1 + (rand() % (8));
		int ranY = 1 + (rand() % (61));
		
		//Allocate item avoiding #(wall),!(item),A(Ammo),B(Bomb) and *(player),@(destination)
		if (board[ranX][ranY] == '#' || board[ranX][ranY] == '!' || board[ranX][ranY] == 'A' || board[ranX][ranY] == 'B') continue;
		if ((ranX == 1 && ranY == 1) || (ranX == 8 && ranY == 60)) continue;
		board[ranX][ranY] = '!';
		cnt--;
	}
}


void HPColor(vector<string>& board, int HP, int x, int y) { //Each wall has three HPs, you need to hit with ammo for three times or only once with bomb 
	if (HP == 2) { //When  HP is full, change color
		gotoxy(y, x);
		//setColor(yellow, yellow);
		printf("\x1b[33m");printf("\x1b[43m");
		cout << board[x-1][y-1];
		printf("\x1b[0m");
	}
	if (HP == 1) { //When HP has one HP, change color
		gotoxy(y, x);
		printf("\x1b[32m");printf("\x1b[42m");
		cout << board[x-1][y-1];
		printf("\x1b[0m");
	}
}


void loadData(){ // When open the game, load the score data from the file
 string input_name;
 int input_score;
 fin.open(fileName.c_str());

 if(fin.fail()) { //When the file doesn't exist, make one
   ofstream outfile(fileName);
   first_open=false; //Make first_open variable to false so that we don't create another file later on when unnecessary
 }
 else{
   if(first_play==true){ //If the user plays for the first time, load data and insert to hashmap
	while(fin>>input_name>>input_score){
		mp.insert(pair<int,string>(input_score,input_name));
	}
	first_open=false; //Make first_open, first_play to false since we just opened and played so that we wouldn't over-do later on
	first_play=false;
    }
  }
}


void scoreBoard() { //When finish the game, view scoreboard
	refresh();
	printf("\x1b[32m");
	gotoxy(33, 8);
	cout << "  Score Board\n";
	gotoxy(32, 9);
	cout << "------------------\n\n";
	printf("\x1b[0m");
	int i = 1;
	for (auto itr : mp) { //Print out from the hashmap
		gotoxy(35, 9 + i++);
		cout << "[" << itr.second << "]  " << itr.first << '\n';
	}
	sleep(3);
}


void gamePlay() {
	loadData(); 
	refresh();
	 //Initialize x,y coordinates
	int xCor = 2;
	int yCor = 2;
	//Ammo and Bomb initialized to 0
	int Ammo = 0;
	int Bomb = 0;
	string userName = userInfo(); //Get username
	refresh();
	//Path and Score initialized to 0
	int path = 0;
	int score = 0;
	//Draw map
	vector<string>board{                                         //H
	"################################################################################",
	"#*               #             B     #     A   ##    ##   A       #            #",
	"#   ##  #############  ####################    ##    ##    ### ####  #   ####  #",
	"#   ##A #           #A #                A #    ##B         ###    #  #   #A    #",
	"#   ##  #######A   #######     ############    #####     #####    # B#   #######",
	"#             #    #B#                         #         ##       ####         #",
	"#       #######    ######################## ## ################   #A          A#",
	"###           ######      #               # ##    #B         A#   #######    ###",
	"#A#        B  #A          #   A      ###  # ##                #              #@#",
	"################################################################################"
	};
	
	itemGen(board); //item random generator
	boardHeight = board.size();
	boardWidth = board[0].length();
	
	//Assign HP as 3 to every wall
	vector<vector<int>>boardHP(boardHeight,vector<int>(boardWidth,0)); //boardHP
	for (int i = 0; i < boardHeight; i++) {
		for (int j = 0; j < boardWidth; j++) {
			if (board[i][j] == '#') boardHP[i][j] = 3;
		}
	}
	
	//Set the starting point/ destination
	board[1][1] = '*';
	board[boardHeight - 2][boardWidth - 2] = '@';
	//current cursor position
	int r = 2;
	int c = 2;
	
	//Color player,destination,wall,items,ammo,bomb
	for (int i = 0; i < boardHeight; i++) {
		for (int j = 0; j < boardWidth; j++) {
			if (board[i][j] == '#') {
				
				printf("\x1b[31m"); printf("\x1b[41m");
				cout << board[i][j];
				printf("\x1b[0m");
			}
			else if (board[i][j] == '*') {
				printf("\x1b[35m");
				cout << board[i][j];
				
			}
			else if (board[i][j] == '@') {
				printf("\x1b[32m");
				cout << board[i][j];
				
			}
			else if (board[i][j] == 'A') {
				printf("\x1b[36m");
				cout << board[i][j];
				printf("\x1b[0m");
			}
			else if (board[i][j] == 'B') {
				printf("\x1b[36m");
				cout << board[i][j];
				printf("\x1b[0m");
			}
			else if (board[i][j] == '!') {
				printf("\x1b[33m");
				cout << board[i][j];
				printf("\x1b[0m");
			}
			else {
				cout << board[i][j];
			}
		}
		cout << "\n";
	}
	
	//Draw control boards, Ammo/Bomb status
	gotoxy(30, 15);
	printf("\x1b[32m");
	cout << "score: ";
	printf("\x1b[0m");
	cout << 0; //7
	gotoxy(50, 15);
	 printf("\x1b[32m");
	cout << "Ammo: ";
	cout << 0;
	gotoxy(50, 16);
	 printf("\x1b[32m");
	cout << "Bomb: ";
	cout << 0;
	gotoxy(30, 16);
	 printf("\x1b[32m");
	cout << "path: ";
	 printf("\x1b[0m");
	cout << 0; //6
	gotoxy(30, 17);
	 printf("\x1b[32m");
	cout << "(x,y): ";
	 printf("\x1b[0m");
	cout << 1 << "," << 1;
	gotoxy(30, 18);
	 printf("\x1b[32m");
	cout << "direction: ";
	 printf("\x1b[0m");
	cout << "RIGHT";
	 printf("\x1b[0m");



}

