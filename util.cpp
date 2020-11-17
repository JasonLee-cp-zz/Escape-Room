#include "util.h"


void refresh(){
printf("\033c"); //clear screen
}

void gotoxy(int x, int y){
printf("%c[%d;%df",0x1B,y,x); //Read (x,y) coordinate and adjust the current position to the given position 
}

