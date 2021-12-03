#include<iostream>
#include<string>
#include<time.h>
#include <stdlib.h>
#include<conio.h>
#include<windows.h>


using namespace std;

char board[3][3] = { { '_','_','_' } ,
{ '_','_','_' } ,
{ '_','_','_' } };
void Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void showBoard()
{
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			if (board[i][j] == 'X')
				Color(4);
			else if (board[i][j] == 'O')
				Color(1);
			else
				Color(7);
			cout << board[i][j] <<" " ;
		}
		cout << endl;

	}
	Color(7);
}

bool win()
{
	for (int i = 0; i<3; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '_')
			return (true);
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '_')
			return (true);
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '_')
		return(true);

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '_')
		return(true);

	return(false);
}
int main()
{
	clock_t t1, t2;
	t1 = clock();
	int c;
	cout << "1 - single player " << endl;
	cout << "2 - multiplayer " << endl;
	cin >> c;
	showBoard();
	if (c == 2)
		for (int i = 0; i<9; i++) {
			while (true) {
				int row, col;
				cout << "player 1 : " << endl;
				cout << "enter row : " << endl;
				cin >> row;
				cout << "enter col : " << endl;
				cin >> col;
				if (row < 0 || row >2 || col<0 || col >2)
				{
					cout << "enter a number between 0-2" << endl;
					continue;
				}
				else if (board[row][col] != '_')
				{
					cout << "cell not empty !" << endl;
					continue;
				}
				else
				{
					board[row][col] = 'X';
					showBoard();
					if (win() == true)
					{
						cout << "Player 1 wins!" << endl;
						t2 = clock();
						float diff((float)t2 - (float)t1);
						diff /= 1000;
						cout << "time : " << diff << endl;
						system("pause");
						exit(0);
					}
					break;
				}
			}
			while (true)
			{
				int row, col;
				cout << "player 2 : " << endl;
				cout << "enter row : " << endl;
				cin >> row;
				cout << "enter col : " << endl;
				cin >> col;
				if (row < 0 || row >2 || col<0 || col >2)
				{
					cout << "enter a number between 0-2" << endl;
					continue;
				}
				else if (board[row][col] != '_')
				{
					cout << "cell not empty !" << endl;
					continue;
				}
				else
				{
					board[row][col] = 'O';
					showBoard();
					if (win() == true)
					{
						cout << "Player 2 wins!" << endl;
						t2 = clock();
						float diff((float)t2 - (float)t1);
						diff /= 1000;
						cout << "time : " << diff << endl;
						system("pause");
						exit(0);
					}
					break;
				}


			}

		}
	else if (c == 1)
		for (int i = 0; i<9; i++) {
			while (true) {
				int row, col;
				cout << "player 1 : " << endl;
				cout << "enter row : " << endl;
				cin >> row;
				cout << "enter col : " << endl;
				cin >> col;
				if (row < 0 || row >2 || col<0 || col >2)
				{
					cout << "enter a number between 0-2" << endl;
					continue;
				}
				else if (board[row][col] != '_')
				{
					cout << "cell not empty !" << endl;
					continue;
				}
				else
				{
					board[row][col] = 'X';
					showBoard();
					if (win() == true)
					{
						cout << "Player 1 wins!" << endl;
						t2 = clock();
						float diff((float)t2 - (float)t1);
						diff /= 1000;
						cout << "time : " << diff << endl;
						system("pause");
						exit(0);
					}
					break;
				}
			}
			while (true)
			{
				
				int row, col;
				srand(time(0));
				row = rand() % 3;
				col = rand() % 3;
				if (board[row][col] != '_')
					continue;
				else
				{
					cout << "Computer : " << endl;
					board[row][col] = 'O';
					showBoard();
					if (win() == true)
					{
						cout << "Computer wins!" << endl;
						t2 = clock();
						float diff((float)t2 - (float)t1);
						diff /= 1000;
						cout << "time : " << diff << endl;
						system("pause");
						exit(0);
					}
					break;
				}


			}

		}

	cout << "Draw!" << endl;
	t2 = clock();
	float diff((float)t2 - (float)t1);
	diff /= 1000;
	cout << "time : " << diff << endl;
	system("pause");
	return (0);
}
