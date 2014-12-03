#include <iostream>
#include "Header.h"
using namespace std;

void init(int grid[6][7]);
void display(int grid[6][7]);
void turn(int grid[6][7], int player);
void checkwhowin(int grid[6][7]);
int checkwin; // 1 = X | 2 = O
int x;
int user=0;
int row;

MyClass<int> myclass;

void main()
{
	int grid[6][7];
	init(grid);
	int player = 1;
	for (int i = 1; i<=100; i++)
	{
		display(grid);
		turn(grid, player);
		if (player == 1)
		{
			player = 2;
		}
		else
		{
			player = 1;
		}
		checkwhowin(grid);
	}

}



void init(int grid[6][7])
{
	for (int i = 1; i<=6; i++)
	{
		for (int j = 1; j<=7; j++)
		{
			grid[i][j] = 0;
		}
	}
}

void display(int grid[6][7])
{
	int win;
	cout << "1+2+3+4+5+6+7+" << endl;
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			if (grid[i][j] == 0)
			{
				cout << ' ';
			}
			if (grid[i][j] == 1)
			{
				cout << 'X';
			}
			if (grid[i][j] == 2)
			{
				cout << 'O';
			}
			if (j <= 7)
			{
				cout << '|';
			}
		}
		cout << endl;
		if (i <= 6)
		{
			cout << "-+-+-+-+-+-+-+" << endl;
		}
	}
	
	if (checkwin == 1)
	{
		cout << " X is winner" << endl;
		system("pause");
		exit(1);
	}
	if (checkwin == 2)
	{
		cout << " O is winner" << endl;
		system("pause");
		exit(1);
	}
}

void turn(int grid[6][7], int player)
{
	
	if (player == 1)
	{
		cout << "Player X turn : ";
		cin >> x;
		user = x;
	}
	if (player == 2)
	{
		x = myclass.computer_move(grid,player,row,user);
		
	}
	
	
	if (x<=7 && x>0)
	{
		if (grid[6][x] == 0)
		{
			grid[6][x] = player;
			row = 6;
		}
		else if (grid[5][x] == 0)
		{
			grid[5][x] = player;
			row = 5;
		}
		else if (grid[4][x] == 0)
		{
			grid[4][x] = player;
			row = 4;
		}
		else if (grid[3][x] == 0)
		{
			grid[3][x] = player;
			row = 3;
		}
		else if (grid[2][x] == 0)
		{
			grid[2][x] = player;
			row = 2;
		}
		else if (grid[1][x] == 0)
		{
			grid[1][x] = player;
			row = 1;
		}
		else if (grid[0][x] == 0)
		{
			grid[0][x] = player;
			row = 0;
		}
		else
		{
			cout << "Pick an empty cell! - MISS A GO!";
		}
	}
	else
	{
		cout << "That's not in the grid - MISS A GO!";
	}
}
	
void checkwhowin(int grid[6][7]){
	for (int i = 6; i >= 1; i--)
	{
		// Checking 'X'
		// Check ( - ) of X
		if (grid[i][1] == 1 && grid[i][2] == 1 && grid[i][3] == 1 && grid[i][4] == 1 || 
			grid[i][2] == 1 && grid[i][3] == 1 && grid[i][4] == 1 && grid[i][5] == 1 || 
			grid[i][3] == 1 && grid[i][4] == 1 && grid[i][5] == 1 && grid[i][6] == 1 || 
			grid[i][4] == 1 && grid[i][5] == 1 && grid[i][6] == 1 && grid[i][7] == 1 )
		{
			checkwin = 1;
		}

		// Check ( | ) of X
		if (grid[i][1] == 1 && grid[i - 1][1] == 1 && grid[i - 2][1] == 1 && grid[i - 3][1] == 1 || grid[i - 1][1] == 1 && grid[i - 2][1] == 1 && grid[i - 3][1] == 1 && grid[i - 4][1] == 1 || grid[i - 2][1] == 1 && grid[i - 3][2] == 1 && grid[i - 4][2] == 1 && grid[i - 5][1] == 1 ||
			grid[i][2] == 1 && grid[i - 1][2] == 1 && grid[i - 2][2] == 1 && grid[i - 3][2] == 1 || grid[i - 1][2] == 1 && grid[i - 2][2] == 1 && grid[i - 3][2] == 1 && grid[i - 4][2] == 1 || grid[i - 2][2] == 1 && grid[i - 3][2] == 1 && grid[i - 4][2] == 1 && grid[i - 5][2] == 1 ||
			grid[i][3] == 1 && grid[i - 1][3] == 1 && grid[i - 2][3] == 1 && grid[i - 3][3] == 1 || grid[i - 1][3] == 1 && grid[i - 2][3] == 1 && grid[i - 3][3] == 1 && grid[i - 4][3] == 1 || grid[i - 2][3] == 1 && grid[i - 3][3] == 1 && grid[i - 4][3] == 1 && grid[i - 5][3] == 1 ||
			grid[i][4] == 1 && grid[i - 1][4] == 1 && grid[i - 2][4] == 1 && grid[i - 3][4] == 1 || grid[i - 1][4] == 1 && grid[i - 2][4] == 1 && grid[i - 3][4] == 1 && grid[i - 4][4] == 1 || grid[i - 2][4] == 1 && grid[i - 3][4] == 1 && grid[i - 4][4] == 1 && grid[i - 5][4] == 1 ||
			grid[i][5] == 1 && grid[i - 1][5] == 1 && grid[i - 2][5] == 1 && grid[i - 3][5] == 1 || grid[i - 1][5] == 1 && grid[i - 2][5] == 1 && grid[i - 3][5] == 1 && grid[i - 4][5] == 1 || grid[i - 2][5] == 1 && grid[i - 3][5] == 1 && grid[i - 4][5] == 1 && grid[i - 5][5] == 1 ||
			grid[i][6] == 1 && grid[i - 1][6] == 1 && grid[i - 2][6] == 1 && grid[i - 3][6] == 1 || grid[i - 1][6] == 1 && grid[i - 2][6] == 1 && grid[i - 3][6] == 1 && grid[i - 4][6] == 1 || grid[i - 2][6] == 1 && grid[i - 3][6] == 1 && grid[i - 4][6] == 1 && grid[i - 5][6] == 1 ||
			grid[i][7] == 1 && grid[i - 1][7] == 1 && grid[i - 2][7] == 1 && grid[i - 3][7] == 1 || grid[i - 1][7] == 1 && grid[i - 2][7] == 1 && grid[i - 3][7] == 1 && grid[i - 4][7] == 1 || grid[i - 2][7] == 1 && grid[i - 3][7] == 1 && grid[i - 4][7] == 1 && grid[i - 5][7] == 1)
		{
			checkwin = 1;
		}
		// Check ( / ) of X
		if (grid[4][1] == 1 && grid[3][2] == 1 && grid[2][3] == 1 && grid[1][4] == 1 ||
			grid[5][1] == 1 && grid[4][2] == 1 && grid[3][3] == 1 && grid[2][4] == 1 ||
			grid[4][2] == 1 && grid[3][3] == 1 && grid[2][4] == 1 && grid[1][5] == 1 ||
			grid[6][1] == 1 && grid[5][2] == 1 && grid[4][3] == 1 && grid[3][4] == 1 ||
			grid[5][2] == 1 && grid[4][3] == 1 && grid[3][4] == 1 && grid[2][5] == 1 ||
			grid[4][3] == 1 && grid[3][4] == 1 && grid[2][5] == 1 && grid[1][6] == 1 ||
			grid[6][2] == 1 && grid[5][3] == 1 && grid[4][4] == 1 && grid[3][5] == 1 ||
			grid[5][3] == 1 && grid[4][4] == 1 && grid[3][5] == 1 && grid[2][6] == 1 ||
			grid[4][4] == 1 && grid[3][5] == 1 && grid[2][6] == 1 && grid[1][7] == 1 ||
			grid[6][3] == 1 && grid[5][4] == 1 && grid[4][5] == 1 && grid[3][6] == 1 ||
			grid[5][4] == 1 && grid[4][5] == 1 && grid[3][6] == 1 && grid[2][7] == 1 ||
			grid[6][4] == 1 && grid[5][5] == 1 && grid[4][6] == 1 && grid[3][7] == 1 )
			{
				checkwin = 1;
			}
		
		// Check ( \ ) of X
		if (grid[6][4] == 1 && grid[5][3] == 1 && grid[4][2] == 1 && grid[3][1] == 1 ||
			grid[6][5] == 1 && grid[5][4] == 1 && grid[4][3] == 1 && grid[3][2] == 1 ||
			grid[5][4] == 1 && grid[3][3] == 1 && grid[3][2] == 1 && grid[2][1] == 1 ||
			grid[6][6] == 1 && grid[5][5] == 1 && grid[4][4] == 1 && grid[3][3] == 1 ||
			grid[5][5] == 1 && grid[4][4] == 1 && grid[3][3] == 1 && grid[2][2] == 1 ||
			grid[4][4] == 1 && grid[3][3] == 1 && grid[2][2] == 1 && grid[1][1] == 1 ||
			grid[6][7] == 1 && grid[5][6] == 1 && grid[4][5] == 1 && grid[3][4] == 1 ||
			grid[5][6] == 1 && grid[4][5] == 1 && grid[3][4] == 1 && grid[2][3] == 1 ||
			grid[4][5] == 1 && grid[3][4] == 1 && grid[2][3] == 1 && grid[1][2] == 1 ||
			grid[5][7] == 1 && grid[4][6] == 1 && grid[3][5] == 1 && grid[2][4] == 1 ||
			grid[4][6] == 1 && grid[3][5] == 1 && grid[2][4] == 1 && grid[1][3] == 1 ||
			grid[4][7] == 1 && grid[3][6] == 1 && grid[2][5] == 1 && grid[1][4] == 1 )
		{
			checkwin = 1;
		}

		// Checking 'O'
		// Checking 'O'
		// Check ( - ) of O
		if (grid[i][1] == 2 && grid[i][2] == 2 && grid[i][3] == 2 && grid[i][4] == 2 ||
			grid[i][2] == 2 && grid[i][3] == 2 && grid[i][4] == 2 && grid[i][5] == 2 ||
			grid[i][3] == 2 && grid[i][4] == 2 && grid[i][5] == 2 && grid[i][6] == 2 ||
			grid[i][4] == 2 && grid[i][5] == 2 && grid[i][6] == 2 && grid[i][7] == 2 )
		{
			checkwin = 2;
		}

		// Check ( | ) of O
		if (grid[i][1] == 2 && grid[i - 1][1] == 2 && grid[i - 2][1] == 2 && grid[i - 3][1] == 2 || grid[i - 1][1] == 2 && grid[i - 2][1] == 2 && grid[i - 3][1] == 2 && grid[i - 4][1] == 2 || grid[i - 2][1] == 2 && grid[i - 3][2] == 2 && grid[i - 4][2] == 2 && grid[i - 5][1] == 2 ||
			grid[i][2] == 2 && grid[i - 1][2] == 2 && grid[i - 2][2] == 2 && grid[i - 3][2] == 2 || grid[i - 1][2] == 2 && grid[i - 2][2] == 2 && grid[i - 3][2] == 2 && grid[i - 4][2] == 2 || grid[i - 2][2] == 2 && grid[i - 3][2] == 2 && grid[i - 4][2] == 2 && grid[i - 5][2] == 2 ||
			grid[i][3] == 2 && grid[i - 1][3] == 2 && grid[i - 2][3] == 2 && grid[i - 3][3] == 2 || grid[i - 1][3] == 2 && grid[i - 2][3] == 2 && grid[i - 3][3] == 2 && grid[i - 4][3] == 2 || grid[i - 2][3] == 2 && grid[i - 3][3] == 2 && grid[i - 4][3] == 2 && grid[i - 5][3] == 2 ||
			grid[i][4] == 2 && grid[i - 1][4] == 2 && grid[i - 2][4] == 2 && grid[i - 3][4] == 2 || grid[i - 1][4] == 2 && grid[i - 2][4] == 2 && grid[i - 3][4] == 2 && grid[i - 4][4] == 2 || grid[i - 2][4] == 2 && grid[i - 3][4] == 2 && grid[i - 4][4] == 2 && grid[i - 5][4] == 2 ||
			grid[i][5] == 2 && grid[i - 1][5] == 2 && grid[i - 2][5] == 2 && grid[i - 3][5] == 2 || grid[i - 1][5] == 2 && grid[i - 2][5] == 2 && grid[i - 3][5] == 2 && grid[i - 4][5] == 2 || grid[i - 2][5] == 2 && grid[i - 3][5] == 2 && grid[i - 4][5] == 2 && grid[i - 5][5] == 2 ||
			grid[i][6] == 2 && grid[i - 1][6] == 2 && grid[i - 2][6] == 2 && grid[i - 3][6] == 2 || grid[i - 1][6] == 2 && grid[i - 2][6] == 2 && grid[i - 3][6] == 2 && grid[i - 4][6] == 2 || grid[i - 2][6] == 2 && grid[i - 3][6] == 2 && grid[i - 4][6] == 2 && grid[i - 5][6] == 2 ||
			grid[i][7] == 2 && grid[i - 1][7] == 2 && grid[i - 2][7] == 2 && grid[i - 3][7] == 2 || grid[i - 1][7] == 2 && grid[i - 2][7] == 2 && grid[i - 3][7] == 2 && grid[i - 4][7] == 2 || grid[i - 2][7] == 2 && grid[i - 3][7] == 2 && grid[i - 4][7] == 2 && grid[i - 5][7] == 2 )
		{
			checkwin = 2;
		}
		// Check ( / ) of O
		if (grid[4][1] == 2 && grid[3][2] == 2 && grid[2][3] == 2 && grid[1][4] == 2 ||
			grid[5][1] == 2 && grid[4][2] == 2 && grid[3][3] == 2 && grid[2][4] == 2 ||
			grid[4][2] == 2 && grid[3][3] == 2 && grid[2][4] == 2 && grid[1][5] == 2 ||
			grid[6][1] == 2 && grid[5][2] == 2 && grid[4][3] == 2 && grid[3][4] == 2 ||
			grid[5][2] == 2 && grid[4][3] == 2 && grid[3][4] == 2 && grid[2][5] == 2 ||
			grid[4][3] == 2 && grid[3][4] == 2 && grid[2][5] == 2 && grid[1][6] == 2 ||
			grid[6][2] == 2 && grid[5][3] == 2 && grid[4][4] == 2 && grid[3][5] == 2 ||
			grid[5][3] == 2 && grid[4][4] == 2 && grid[3][5] == 2 && grid[2][6] == 2 ||
			grid[4][4] == 2 && grid[3][5] == 2 && grid[2][6] == 2 && grid[1][7] == 2 ||
			grid[6][3] == 2 && grid[5][4] == 2 && grid[4][5] == 2 && grid[3][6] == 2 ||
			grid[5][4] == 2 && grid[4][5] == 2 && grid[3][6] == 2 && grid[2][7] == 2 ||
			grid[6][4] == 2 && grid[5][5] == 2 && grid[4][6] == 2 && grid[3][7] == 2)
		{
			checkwin = 2;
		}

			// Check ( \ ) of O
		if (grid[6][4] == 2 && grid[5][3] == 2 && grid[4][2] == 2 && grid[3][1] == 2 ||
			grid[6][5] == 2 && grid[5][4] == 2 && grid[4][3] == 2 && grid[3][2] == 2 ||
			grid[5][4] == 2 && grid[3][3] == 2 && grid[3][2] == 2 && grid[2][1] == 2 ||
			grid[6][6] == 2 && grid[5][5] == 2 && grid[4][4] == 2 && grid[3][3] == 2 ||
			grid[5][5] == 2 && grid[4][4] == 2 && grid[3][3] == 2 && grid[2][2] == 2 ||
			grid[4][4] == 2 && grid[3][3] == 2 && grid[2][2] == 2 && grid[1][1] == 2 ||
			grid[6][7] == 2 && grid[5][6] == 2 && grid[4][5] == 2 && grid[3][4] == 2 ||
			grid[5][6] == 2 && grid[4][5] == 2 && grid[3][4] == 2 && grid[2][3] == 2 ||
			grid[4][5] == 2 && grid[3][4] == 2 && grid[2][3] == 2 && grid[1][2] == 2 ||
			grid[5][7] == 2 && grid[4][6] == 2 && grid[3][5] == 2 && grid[2][4] == 2 ||
			grid[4][6] == 2 && grid[3][5] == 2 && grid[2][4] == 2 && grid[1][3] == 2 ||
			grid[4][7] == 2 && grid[3][6] == 2 && grid[2][5] == 2 && grid[1][4] == 2 )
		{
			checkwin = 2;
		}
	}
}



void exit(){
}
