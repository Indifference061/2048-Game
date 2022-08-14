#define _CRT_SECURE_NO_WARNINGS
#include"Board.h"
#include"Game2048.h"
#include<ctime>
#include<iostream>
#include<ios>
#include<string>
#include<vector>
#include<fstream>
using std::ofstream;
using std::cout;
using std::endl;
using std::time;
using std::ctime;
using std::difftime;
using std::istream;
using std::string;
using std::cin;
void Game2048::input(istream& in)
{
	cout << "(¡ü:u) (¡ý:d) (¡û:l) (¡ú:r) (quit:q): ";
	in >> Game2048::op;
	while (Game2048::op != 'q' &&Game2048::op != 'u'&& Game2048::op != 'd'&&Game2048::op != 'l' && Game2048::op != 'r')
	{
		in.clear();
		cout << "(¡ü:u) (¡ý:d) (¡û:l) (¡ú:r) (quit:q): ";
		in >> Game2048::op;
	}
}
int Game2048::fget_score()
{
	return Game2048::board.get_score();
}
void Game2048::operate()
{
	if (Game2048::op == 'r')
		Game2048::board.move_right();
	else if (Game2048::op == 'l')
		Game2048::board.move_left();
	else if (Game2048::op == 'u')
		Game2048::board.move_up();
	else if (Game2048::op == 'd')
		Game2048::board.move_down();
}
void Game2048::ffset_table()
{
	Game2048::board.set_first();
}
void Game2048::fset_table()
{
	Game2048::board.set_table();
}
void Game2048::print()
{
	Game2048::board.output();
	cout << "Your score: " << Game2048::fget_score()<<endl;
}
bool Game2048::final(char t)
{
	if (t == 'u')
	{
		Game2048::board.utransl();
		if (!Game2048::board.validt())
		{
			Game2048::board.utransl();
			return false;
		}
		Game2048::board.utransl();
	}
	else if (t == 'd')
	{
		Game2048::board.utransl();
		Game2048::board.rtransl();
		if (!Game2048::board.validt())
		{
			Game2048::board.rtransl();
			Game2048::board.utransl();
			return false;
		}
		Game2048::board.rtransl();
		Game2048::board.utransl();
	}
	else {
		if (!Game2048::board.validt()) return false;
	}
	return true;
}
void Game2048::Game_start()
{
	Game2048::board.retable(); 
	time_t it = time(NULL);
	string starttime(ctime(&it));
	Game2048::starttime = ctime(&it);
	Game2048::starttime[24] = '\0';
	ofstream out("Game2048.csv", ofstream::app);
	cout << "Welcome to the game of 2048!" << endl;
	Game2048::ffset_table();
	Game2048::ffset_table();
	print();
	while ((!Game2048::board.isfull())|| (Game2048::board.isfull() && (Game2048::board.valid())))
	{
		Game2048::input(cin);
		if (Game2048::op == 'q'|| (Game2048::board.isfull() && (!Game2048::final(op))))
			break;
		Game2048::operate();
		Game2048::fset_table();
		Game2048::print();
	}
	cout << "Game Over"<<endl;
	time_t later = time(NULL);
	out << Game2048::starttime << ',' <<difftime(later, it) <<','<<Game2048::board.get_score() << endl;
}