using namespace std;

template<class T> class MyClass
{
public:
	MyClass() {}
	~MyClass() {}
	int computer_move(int grid[6][7], int player,int row,int user);


};

template<class T>
int MyClass<T>::computer_move(int grid[6][7], int player,int row,int user)
{
	int x;
		//แนวตั้ง
		if(grid[row][user] == 1 && grid[row][user] == grid[row+1][user] && grid[row+1][user] == grid[row+2][user])
		{
			return x = user;
		}
		//แนวนอน
		else if(grid[row][user] == 1 && grid[row][user] == grid[row][user+1] && grid[row][user+1] == grid[row][user+2])
		{
			if(grid[row][user+3] == 0)
			{
				return x = user+3;
			}
			else if(grid[row][user-1] == 0)
			{
				return x = user-1;
			}
			else
			{
				return x = rand()% 7+1;
			}
		}

		else if(grid[row][user] == 1 && grid[row][user] == grid[row][user-1] && grid[row][user-1] == grid[row][user-2])
		{
			if(grid[row][user-3] == 0)
			{
				return x = user-3;
			}
			else if(grid[row][user+1] == 0)
			{
				return x = user+1;
			}
			else
			{
				return x = rand()% 7+1;
			}
		}
		else if(grid[row][user] == 1 && grid[row][user] == grid[row][user+1] && grid[row][user+1] == grid[row][user-1])
		{
			if(grid[row][user+2] == 0)
			{
				return x = user+2;
			}
			else if(grid[row][user-2] == 0)
			{
				return x = user-2;
			}
			else
			{
				return x = rand()% 7+1;
			}
		}
		//แนวทะแยงขวาไล่ลง
		else if(grid[row][user] == 1 && grid[row][user] == grid[row+1][user-1] && grid[row+1][user-1] == grid[row+2][user-2])
		{
			if(grid[row-1][user+1] == 0 && grid[row][user+1] != 0)
			{
				return x = user+1;
			}
			else if(grid[row+3][user-3] == 0 && grid[row+4][user-3] != 0)
			{
				return x = user-3;
			}
			else
			{
				return x = rand()% 7+1;
			}
		}

		//ทะแยงขวาไล่ขึ้น
		else if(grid[row][user] == 1 && grid[row][user] == grid[row-1][user+1] && grid[row-1][user+1] == grid[row-2][user+2])
		{
			if(grid[row+1][user-1] == 0 && grid[row][user-1] != 0)
			{
				return x = user-1;
			}
			else if(grid[row-3][user+3] == 0 && grid[row-4][user+3] != 0)
			{
				return x = user+3;
			}
			else
			{
				return x = rand()% 7+1;
			}
		}
		//ทะแยงขวาข้าง
		else if(grid[row][user] == 1 && grid[row][user] == grid[row-1][user+1] && grid[row-1][user+1] == grid[row+1][user-1])
		{
			if(grid[row-2][user+2] == 0 && grid[row-1][user+2] != 0)
			{
				return x = user+2;
			}
			else if(grid[row+2][user-2] == 0 && grid[row+4][user-2] != 0)
			{
				return x = user-2;
			}
			else
			{
				return x = rand()% 7+1;
			}
		}
		//แนวทะแยงซ้ายไล่ลง
		else if(grid[row][user] == 1 && grid[row][user] == grid[row+1][user+1] && grid[row+1][user+1] == grid[row+2][user+2])
		{
			if(grid[row-1][user-1] == 0 && grid[row][user-1] != 0)
			{
				return x = user-1;
			}
			else if(grid[row+3][user+3] == 0 && grid[row+4][user+3] != 0)
			{
				return x = user+3;
			}
			else
			{
				return x = rand()% 7+1;
			}
		}

		//ทะแยงซ้ายไล่ขึ้น
		else if(grid[row][user] == 1 && grid[row][user] == grid[row-1][user-1] && grid[row-1][user-1] == grid[row-2][user-2])
		{
			if(grid[row+1][user+1] == 0 && grid[row][user+1] != 0)
			{
				return x = user+1;
			}
			else if(grid[row-3][user-3] == 0 && grid[row-4][user-3] != 0)
			{
				return x = user-3;
			}
			else
			{
				return x = rand()% 7+1;
			}
		}
		//ทะแยงซ้ายข้าง
		else if(grid[row][user] == 1 && grid[row][user] == grid[row-1][user-1] && grid[row-1][user-1] == grid[row+1][user+1])
		{
			if(grid[row-2][user-2] == 0 && grid[row-1][user-2] != 0)
			{
				return x = user+2;
			}
			else if(grid[row+2][user+2] == 0 && grid[row+4][user+2] != 0)
			{
				return x = user+2;
			}
			else
			{
				return x = rand()% 7+1;
			}
		}
		else
		{
			return x = rand()% 7+1;
		}
}
