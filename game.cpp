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
