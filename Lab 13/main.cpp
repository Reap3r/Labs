#include <iostream>
using namespace std;
const int size=8;
int desk[size][size];
int line, column;

void del();
void print();

void make()
{
	for (int i =line; i < size; i++)
	{
		for (int j = column; j <size; j++)
		{
			if (desk[i][j] == 0)
			{
				int x = i;
				int y = j;
				line = x;
				desk[i][j] = -(line + 1);
				for (int a = 0; a < size; a++)
				{
					if (desk[x][a] == 0)
					{
						desk[x][a] = line + 1;
					}
				}
				for (int b = 0; b < size; b++)
				{
					if (desk[b][y] == 0)
					{
						desk[b][y] = line + 1;
					}
				}
				while (x != 7 && y != 7)
				{
					if (desk[x + 1][y + 1] == 0)
					{
						desk[x + 1][y + 1] = line + 1;
					}
					x++;
					y++;
				}
				x = i;
				y = j;
				while (x != 0 && y != 0)
				{
					if (desk[x - 1][y - 1] == 0)
					{
						desk[x - 1][y - 1] = line + 1;
					}
					x--;
					y--;
				}
				x = i;
				y = j; 
				while (x != 0 && y != 7)
				{
					if (desk[x - 1][y + 1] == 0)
					{
						desk[x - 1][y + 1] = line + 1;
					}
					x--;
					y++;
				}
				x = i;
				y = j; 
				while (x != 7 && y != 0)
				{
					if (desk[x + 1][y - 1] == 0)
					{
						desk[x + 1][y - 1] = line + 1;
					}
					x++;
					y--;
				}
				j = 7;
				column = 0;
				if (line == 7)
				{
					for (int i = 0; i < size; i++)
					{
						for (int j = 0; j < size; j++)
						{
							if (desk[i][j] > 0)
							{
								desk[i][j] = 0;
							}
							if (desk[i][j] < 0)
							{
								desk[i][j] = 1;
							}
						}
					}
					cout << "Result:" << endl;
					print();
					exit(0);
				}
			}
			else
			{
				if (j == 7 && desk[i][j] != 0)
				{
					del();
				}
			}
		}
		
	}
}

void del()
{
	for (int j = 0; j < size;j++)
	{
		if (desk[line][j] == -(line + 1))
		{
			column = j;
			j = 7;
		}
	}
	desk[line][column] = 0;
	int x = line;
	int y = column;
	for (int a = 0; a < size; a++)
	{
		if (desk[x][a] == line + 1)
		{
			desk[x][a] = 0;
		}
	}
	for (int b = 0; b < size; b++)
	{
		if (desk[b][y] == line + 1)
		{
			desk[b][y] = 0;
		}
	}
	while (x != 7 && y != 7)
	{
		if (desk[x + 1][y + 1] == line + 1)
		{
			desk[x + 1][y + 1] = 0;
		}
		x++;
		y++;
	}
	x = line;
	y = column;
	while (x != 0 && y != 0)
	{
		if (desk[x - 1][y - 1] == line + 1)
		{
			desk[x - 1][y - 1] = 0;
		}
		x--;
		y--;
	}
	x = line;
	y = column;
	while (x != 0 && y != 7)
	{
		if (desk[x - 1][y + 1] == line + 1)
		{
			desk[x - 1][y + 1] = 0;
		}
		x--;
		y++;
	}
	x = line;
	y = column;
	while (x != 7 && y != 0)
	{
		if (desk[x + 1][y - 1] == line + 1)
		{
			desk[x + 1][y - 1] = 0;
		}
		x++;
		y--;
	}
	for (int j = column + 1; j < size; j++)
	{
		if (desk[line][j] == 0)
		{
			column = j;
			make();
		}
	}
	line--;
	del();
}

void print()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if(desk[i][j] == 0){
				cout << 'n' << " ";
			}else{
				cout << 'Q' << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			desk[i][j] = 0;
		}
	}
	line = 0;
	column = 0;
	cout << "Q - Queen cell" << endl;
	cout << "n - Emty cell" << endl << endl;
	cout << "Clear desk:" << endl;
	print();
	make();
	return 0;
}
