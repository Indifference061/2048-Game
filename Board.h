#pragma once
#ifndef GUARD_Board_h
#define GUARD_Board_h
#include<random>
#include<ctime>
#include<time.h>
#include<iostream>
#include<string>
#include<memory>
#include<vector>
const int Size = 4;
class Board {
public:
	Board() { create(); }
	~Board() {  }
	int get_score() { return score; }
	void output();
	void retable();
	void set_table();
	void set_first();
	void move_left();
	void move_right();
	void move_up();
	void move_down();
	void combine();
	void rtransl();
	void utransl();
	void dtransu();
	bool isfull();
	bool valid();
	bool validt();
	int count(int);
private:
	int score;
	int table[4][4] = { {0},{0},{0},{0} };
	void create();
	void uncreate();
};
#endif // !GUARD_Board_h


