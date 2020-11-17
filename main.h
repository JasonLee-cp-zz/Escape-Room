//#pragma once

//Libraries needed for the project
#ifndef __MAIN_H__
#define __MAIN_H__
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <termio.h>
#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

//util functions
void gotoxy(int, int); 
void refresh();


//game functions
void titleDraw();
int menuDraw();
void gameInfo();
void gamePlay();
int getch(void);
string userInfo();
void saveData();
void loadData();
void scoreBoard();
void itemGen(vector<string>& board);
#endif
