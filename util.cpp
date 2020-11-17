#include "util.h"


void refresh(){
//system("clear");
//write(1,"\033[1;1H\033[2J",10);
printf("\033c");
}

void gotoxy(int x, int y){
printf("%c[%d;%df",0x1B,y,x);
}

