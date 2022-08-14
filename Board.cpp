#include<iostream>
#include<vector>
#include<time.h>
#include<iomanip>
#include<iterator>
#include"Board.h"
using std::vector;
using std::cout;
using std::endl;
using std::rand;
using std::time;
using std::srand;
using std::setw;
void Board::retable()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Board::table[i][j] = 0;
		}
	}
}
void Board::create()
{
	Board::score = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Board::table[i][j] = 0;
		}
	}
}
int Board::count(int n)
{
	int num=0;
	while (n > 0)
	{
		num++;
		n /= 10;
	}
	return num;
}
void Board::output()
{
	cout << "|-----|-----|-----|-----|" << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout <<"| ";
			if (table[i][j] != 0)
			{
				int num = Board::count(table[i][j]);
				cout << table[i][j];
				for (int k = 0; k < 4 - num; k++) cout << " ";
			}
			else
				for (int k = 0; k < 4; k++) cout << " ";
		}
		cout <<'|'<< endl;
		cout << "|-----|-----|-----|-----|" << endl;
	}
}
void Board::set_first()
{
	int empty = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Board::table[i][j] == 0)
			{
				empty++;
			}
		}
	}
	srand(time(NULL));
	int temp = rand() % empty+1;
	bool flag = false;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Board::table[i][j] == 0)
			{
				temp--;
				if (temp == 0)
				{
					flag = true;
					table[i][j] = 2;
					break;
				}
			}
		}
		if (flag) break;
	}
}
void Board::set_table()
{
	int empty = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Board::table[i][j] == 0)
			{
				empty++;
			}
		}
	}
	if (!empty) return;
	srand(time(NULL));
	int temp = rand() % empty+1;
	bool flag=false;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Board::table[i][j] == 0)
			{
				temp--;
				if (temp == 0)
				{
					flag = true;
					if (rand() % 5 == 1)
						table[i][j] = 4;
					else table[i][j] = 2;
					break;
				}
			}
		}
		if (flag) break;
	}
}
void Board::combine()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Board::table[i][j] == Board::table[i][j + 1] && table[i][j] != 0)
			{
				score += (table[i][j] * 2);
				table[i][j] *= 2;
				int temp = j+1;
				while (temp < 3)
				{
					Board::table[i][temp] = Board::table[i][temp+1];
					temp++;
				}
				Board::table[i][temp] = 0;
			}
		}
	}
}
void Board::move_left()
{
	for (int i = 0; i < 4; i++)
	{
		int mark = 0,j=0;
		/*while (j <4)
		{
			if (Board::table[i][j] == 0)
			{
				mark = j;
				j++;
				while (Board::table[i][j] == 0 && j < 4)
					j++;
				if (j >= 4) break;
				Board::table[i][mark] = Board::table[i][j];
				Board::table[i][j] = 0;
			}
			else
				j++;
		}*/
		for (int j = 0; j < 4; j++)
		{
			if (Board::table[i][j] != 0)
			{
				for (int mark = 0; mark < j; mark++)
				{
					if (Board::table[i][mark] == 0 )
					{
						Board::table[i][mark] = Board::table[i][j];
						Board::table[i][j] = 0;
						break;
					}
				}
			}
		}
	}
	Board::combine();
}
void Board::rtransl()
{
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			int temp = Board::table[i][j];
			Board::table[i][j] = Board::table[i][3 - j];
			Board::table[i][3 - j] = temp;
		}
	}
}
void Board::utransl()
{
	for (int i = 1; i < 4; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int temp =Board::table[i][j];
			Board::table[i][j] = Board::table[j][i];
			Board::table[j][i] = temp;
		}
	}
}
void Board::dtransu()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int temp = Board::table[i][j];
			Board::table[i][j] = Board::table[i][3 - j];
			Board::table[i][3 - j] = temp;
		}
	}
}
void Board::move_right()
{
	Board::rtransl();
	Board::move_left();
	Board::rtransl();
}
void Board::move_up()
{
	Board::utransl();
	Board::move_left();
	Board::utransl();
}
void Board::move_down()
{
	Board::utransl();
	Board::rtransl();
	Board::move_left();
	Board::rtransl();
	Board::utransl(); 
}
bool Board::isfull()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Board::table[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}
bool Board::valid()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Board::table[i][j] == Board::table[i][j + 1])
			{
				return true;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Board::table[i][j] == Board::table[i+1][j])
			{
				return true;
			}
		}
	}
	return false;
}
bool Board::validt()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Board::table[i][j] == Board::table[i][j + 1])
			{
				return true;
			}
		}
	}
	return false;
}