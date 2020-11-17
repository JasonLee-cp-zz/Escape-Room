//#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include "main.h"
using namespace std;

//Directions to integer values
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define SHOOT 5
#define BOMB 6


//Initialize all the variables, functions, and STLs
int boardHeight;
int boardWidth;
bool first_play = true;
bool first_open = true;
const string fileName = "score.txt";
ifstream fin;
ofstream fout;
multimap<int, string,greater<int>>mp;
int directionStatus = RIGHT;
bool weaponStatus = false;
int xCor = 1;
int yCor = 1;
int Ammo = 0;
int Bomb = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void titleDraw();
int menuDraw();
int keyControl();
void gameInfo();
void gamePlay();
void saveData();
void loadData();
int getch(void);
string userInfo();
void scoreBoard();
void itemGen(vector<string>& board);
void HPColor(vector<string>& board, int HP, int x, int y);


#endif
