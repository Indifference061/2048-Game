#include<iostream>
#include<ctime>
#include<fstream>
#include<random>
#include<time.h>
#include<vector>
#include"Board.h"
#include"Game2048.h"
using std::cin;
using std::endl;
using std::cout;
using std::ofstream;
using std::ctime;
using std::difftime;
using std::time;
int main()
{
	Game2048 games;
	games.Game_start();
	return 0;
}