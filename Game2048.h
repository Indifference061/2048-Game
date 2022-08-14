#pragma once
#ifndef Guard_Game2048_h
#define Guard_Game2048_h
#include<ctime>
#include<string>
#include"Board.h"
#include<iostream>
class Game2048 {
public:
	Game2048():op(' '),totaltime(0) {}
	void Game_start();
	void Game_over();
	void input(std::istream&);
	int fget_score();
	void operate();
	void fset_table();
	void ffset_table();
	bool final(char);
	void print();
private:
	Board board;
	char* starttime;
	double totaltime;
	char op;
};
#endif // !Guard_Game2048_h

