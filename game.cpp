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
