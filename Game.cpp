#include<iostream>
#include<string>
#include<stdlib.h>
#include<iomanip>
#include<windows.h>
using namespace std;
void chess()
{
	
	system("COLOR f0");
	cout << endl << endl << endl;
	cout << "\n\n\t\t\t\t\t\t\t\t  .::Group Members::.\n\n";
	cout << "\n\n\t\t\t\t\t\t\t\t Muhammad Ibrahim | 18F-0248\n\n\t\t\t\t\t\t\t\t walid amjad | 18F-0251\n\n\n";
	cout << "\t\t\t\t\t\t   ********                      ********      ********\n";
	cout << "\t\t\t\t\t\t  **********                    **********    **********\n";
	cout << "\t\t\t\t\t\t *****   ****                  *****   ****  *****   ****\n";
	cout << "\t\t\t\t\t\t*****                           *****         *****\n";
	cout << "\t\t\t\t\t\t*****    ****    ****  *******   *****         *****\n";
	cout << "\t\t\t\t\t\t*****    ****    ****  ***        *****         *****\n";
	cout << "\t\t\t\t\t\t*****    ************  *****       *****         *****\n";
	cout << "\t\t\t\t\t\t*****    ****    ****  ***          *****         *****\n";
	cout << "\t\t\t\t\t\t*****    ****    ****  *******       *****         *****\n";
	cout << "\t\t\t\t\t\t*****                                 *****         *****\n";
	cout << "\t\t\t\t\t\t *****   ****                   ****   *****  ****   *****\n";
	cout << "\t\t\t\t\t\t  **********                      **********   *********\n";
	cout << "\t\t\t\t\t\t   ********                        ********     "; cout << "***"; Sleep(3000); cout << "***"; Sleep(3000); cout << "*"; Sleep(3000);
	
}
class piece
{
protected:
	string Name;
	int Player;
	
public:
	friend ostream &operator <<(ostream&out, piece&p);
	friend void ChessBoard(piece *arr[8][8]);
	virtual void move(piece *arr[][8], int Current_Row, int Current_Col, int Next_Row, int Next_Col)
	{
	
	}
	piece()
	{

		Name = " ";//for testing
		Player = NULL;
	}
	piece(string n, int player_Number)
	{
		Name = n;
		Player = player_Number;
	}
	string GetPlayerName()
	{
		return Name;
	}
	int GetPlayerNumber()
	{
		return Player;
	}
};
ostream &operator <<(ostream&out, piece&p)
{
	out << p.Name;
	out << p.Player;
	return out;
}
void ChessBoard(piece *arr[8][8])
{
	cout << "\n\n";
	//Print Chess Board
	int s = 0;
	for (int i = 0; i < 8; ++i)
	{
		cout << "     " << i<<"\t\t";
	}
	cout << "\n\n";
	for (int i = 0; i < 8; ++i)
	{
		if (s < 8)
		{
			for (; s < 8; ++s)
			{
				cout << "---------------";
			}
			cout << "\n";
		}
		for (int k = 0; k < 9; ++k)
		{
			cout << "|" << setw(15);
		}
		cout << "\n";
		for (int j = 0; j < 9; j++)
		{
			cout << "|" << setw(5);
			if (j < 8)
			{

				cout << *arr[i][j] << setw(9);
			}
			if (j == 8)
			{
				cout << i;
			}
		}
		cout << "\n";
		for (int k = 0; k < 9; ++k)
		{
			cout << "|" << setw(15);
		}
		cout << "\n";
		for (int g = 0; g < 8; ++g)
		{
			cout << "---------------";
		}
		cout << "\n";
	}

}
class King :public piece
{
public:
	King(string s, int n) :piece(s, n)
	{

	}
	void move(piece *arr[][8], int Current_Row, int Current_Col, int Next_Row, int Next_Col)
	{
		//For Diagonal Move
		if (arr[Next_Row][Next_Col] == arr[Current_Row + 1][Current_Col + 1])
		{
			if (arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		else if (arr[Next_Row][Next_Col] == arr[Current_Row - 1][Current_Col - 1])
		{
			if (arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		else if (arr[Next_Row][Next_Col] == arr[Current_Row + 1][Current_Col - 1])
		{
			if (arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		else if (arr[Next_Row][Next_Col] == arr[Current_Row - 1][Current_Col + 1])
		{
			if (arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		// For Vertical Move
		else if (arr[Next_Row][Next_Col] == arr[Current_Row + 1][Current_Col])
		{
			if (arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		else if (arr[Next_Row][Next_Col] == arr[Current_Row - 1][Current_Col])
		{
			if (arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		// For Horizntal Move
		else if (arr[Next_Row][Next_Col] == arr[Current_Row][Current_Col + 1])
		{
			if (arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		else if (arr[Next_Row][Next_Col] == arr[Current_Row][Current_Col - 1])
		{
			if (arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		else
		{

			cout << "\t\t\t\t\t\tNOT Possible!\n";
		}
	}
};
class Knight :public piece
{
public:
	Knight(string s, int n) :piece(s, n)
	{

	}
	void move(piece *arr[][8], int Current_Row, int Current_Col, int Next_Row, int Next_Col)
	{
		// Two Vertical one Horizental 
		if (arr[Next_Row][Next_Col] == arr[Current_Row + 2][Current_Col + 1])
		{
			if ((arr[Next_Row][Next_Col]->GetPlayerName() == " ") || (arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber()))
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		else if (arr[Next_Row][Next_Col] == arr[Current_Row + 2][Current_Col - 1])
		{
			if ((arr[Next_Row][Next_Col]->GetPlayerName() == " ") || (arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber()))
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		else if (arr[Next_Row][Next_Col] == arr[Current_Row - 2][Current_Col + 1])
		{
			if ((arr[Next_Row][Next_Col]->GetPlayerName() == " ") || (arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber()))
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		else if (arr[Next_Row][Next_Col] == arr[Current_Row - 2][Current_Col - 1])
		{
			if ((arr[Next_Row][Next_Col]->GetPlayerName() == " ") || (arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber()))
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		// one Vertical Two Horizental Move
		else if (arr[Next_Row][Next_Col] == arr[Current_Row + 1][Current_Col + 2])
		{
			if ((arr[Next_Row][Next_Col]->GetPlayerName() == " ") || (arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber()))
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		else if (arr[Next_Row][Next_Col] == arr[Current_Row - 1][Current_Col + 2])
		{
			if ((arr[Next_Row][Next_Col]->GetPlayerName() == " ") || (arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber()))
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		else if (arr[Next_Row][Next_Col] == arr[Current_Row + 1][Current_Col - 2])
		{
			if ((arr[Next_Row][Next_Col]->GetPlayerName() == " ") || (arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber()))
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		else if (arr[Next_Row][Next_Col] == arr[Current_Row - 1][Current_Col - 2])
		{
			if ((arr[Next_Row][Next_Col]->GetPlayerName() == " ") || (arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber()))
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		else
		{
			cout << "\t\t\t\t\t\tNOT Possible!\n";
		}
	}
};
class Rook :public piece
{
public:
	Rook(string s, int n) :piece(s, n)
	{

	}
	void move(piece *arr[][8], int Current_Row, int Current_Col, int Next_Row, int Next_Col)
	{
		bool Testing = false;
		// For Right and Left Move 
		if (Current_Row == Next_Row)
		{
			for (int i = Current_Col, n = Current_Col; (i <= Next_Col || n >= Next_Col); ++i, --n)
			{
				if (arr[Next_Row][Next_Col]->GetPlayerName() == " "  || arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
				{
					Testing = true;
				}
			}
			if (Testing == true)
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		//For Down and up Move
		else if (Current_Col == Next_Col)
		{
			for (int i = Current_Row,n=Current_Row; (i <= Next_Row || n>=Next_Row) ; ++i,--n)
			{

				if (arr[Next_Row][Next_Col]->GetPlayerName() == " "  || arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
				{
					Testing = true;
				}
			}
			if (Testing == true)
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
			else
				{
					cout << "\t\t\t\t\t\tNOT Possible!\n";
		
				}
			
		}	
};
class Pawn :public piece
{
	int a;
public:
	Pawn(string s, int n) :piece(s, n)
	{
		a = 0;
	}
	void move(piece *arr[][8], int Current_Row, int Current_Col, int Next_Row, int Next_Col)
	{
							// Pawn Move For Player 1
		if (arr[Current_Row][Current_Col]->GetPlayerNumber() == 1)
		{

			if (this->a == 0)
			{
				if (arr[Next_Row][Next_Col] == arr[Current_Row + 2][Current_Col] && arr[Next_Row][Next_Col]->GetPlayerName()==" ")
				{
					arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
					arr[Current_Row][Current_Col] = NULL;
					arr[Current_Row][Current_Col] = new piece(" ", 0);
					a++;
				}
				else if (arr[Next_Row][Next_Col] == arr[Current_Row + 1][Current_Col] && arr[Next_Row][Next_Col]->GetPlayerName() == " ")
				{
					arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
					arr[Current_Row][Current_Col] = NULL;
					arr[Current_Row][Current_Col] = new piece(" ", 0);
					a++;
				}
				// For Killing Purpose
				else if (arr[Next_Row][Next_Col] == arr[Current_Row + 1][Current_Col + 1])
				{
					if (arr[Next_Row][Next_Col]->GetPlayerName() != " " && arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
					{
						arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
						arr[Current_Row][Current_Col] = NULL;
						arr[Current_Row][Current_Col] = new piece(" ", 0);
						a++;
					}
					else
					{
						cout << "\t\t\t\t\t\tNOT Possible!\n";
					}
				}
				else if (arr[Next_Row][Next_Col] == arr[Current_Row + 1][Current_Col - 1])
				{
					if (arr[Next_Row][Next_Col]->GetPlayerName() != " " && arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
					{
						arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
						arr[Current_Row][Current_Col] = NULL;
						arr[Current_Row][Current_Col] = new piece(" ", 0);
						a++;
					}
					else
					{
						cout << "\t\t\t\t\t\tNOT Possible!\n";
					}
				}
				else
				{
					cout << "\t\t\t\t\t\tNOT Possible!\n";
				}
			}
			else
			{

				if (arr[Next_Row][Next_Col] == arr[Current_Row + 1][Current_Col] && arr[Next_Row][Next_Col]->GetPlayerName() == " ")
				{
					arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
					arr[Current_Row][Current_Col] = NULL;
					arr[Current_Row][Current_Col] = new piece(" ", 0);

				}
				// For Killing one step
				else if (arr[Next_Row][Next_Col] == arr[Current_Row + 1][Current_Col + 1])
				{
					if (arr[Next_Row][Next_Col]->GetPlayerName() != " " && arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
					{
						arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
						arr[Current_Row][Current_Col] = NULL;
						arr[Current_Row][Current_Col] = new piece(" ", 0);
					}
					else
					{
						cout << "\t\t\t\t\t\tNOT Possible!\n";
					}
				}
				else if (arr[Next_Row][Next_Col] == arr[Current_Row + 1][Current_Col - 1])
				{
					if (arr[Next_Row][Next_Col]->GetPlayerName() != " " && arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
					{
						arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
						arr[Current_Row][Current_Col] = NULL;
						arr[Current_Row][Current_Col] = new piece(" ", 0);
					}
					else
					{
						cout << "\t\t\t\t\t\tNOT Possible!\n";
					}
				}
				else
				{
					cout << "\t\t\t\t\t\tNOT Possible!\n";
				}

			}
		}
							// Pawn Move For Player 2 
		if (arr[Current_Row][Current_Col]->GetPlayerNumber() == 2)
		{

			if (this->a == 0)
			{
				if (arr[Next_Row][Next_Col] == arr[Current_Row - 2][Current_Col] && arr[Next_Row][Next_Col]->GetPlayerName() == " ")
				{
					arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
					arr[Current_Row][Current_Col] = NULL;
					arr[Current_Row][Current_Col] = new piece(" ", 0);
					a++;
				}
				else if (arr[Next_Row][Next_Col] == arr[Current_Row - 1][Current_Col] && arr[Next_Row][Next_Col]->GetPlayerName() == " ")
				{
					arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
					arr[Current_Row][Current_Col] = NULL;
					arr[Current_Row][Current_Col] = new piece(" ", 0);
					a++;
				}
				// For killing purpose player 2
				else if (arr[Next_Row][Next_Col] == arr[Current_Row - 1][Current_Col + 1])
				{
					if (arr[Next_Row][Next_Col]->GetPlayerName() != " " && arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
					{
						arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
						arr[Current_Row][Current_Col] = NULL;
						arr[Current_Row][Current_Col] = new piece(" ", 0);
						a++;
					}
					else
					{
						cout << "\t\t\t\t\t\tNOT Possible!\n";
					}
				}
				else if (arr[Next_Row][Next_Col] == arr[Current_Row - 1][Current_Col - 1])
				{
					if (arr[Next_Row][Next_Col]->GetPlayerName() != " " && arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
					{
						arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
						arr[Current_Row][Current_Col] = NULL;
						arr[Current_Row][Current_Col] = new piece(" ", 0);
						a++;
					}
					else
					{
						cout << "\t\t\t\t\t\tNOT Possible!\n";
					}
				}
				else
				{
					cout << "\t\t\t\t\t\tNOT Possible!\n";
				}
			}
			 
			else
			{

				if (arr[Next_Row][Next_Col] == arr[Current_Row - 1][Current_Col] && arr[Next_Row][Next_Col]->GetPlayerName() == " ")
				{
					arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
					arr[Current_Row][Current_Col] = NULL;
					arr[Current_Row][Current_Col] = new piece(" ", 0);

				}
				// For killing purpose
				else if (arr[Next_Row][Next_Col] == arr[Current_Row - 1][Current_Col + 1])
				{
					if (arr[Next_Row][Next_Col]->GetPlayerName() != " " && arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
					{
						arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
						arr[Current_Row][Current_Col] = NULL;
						arr[Current_Row][Current_Col] = new piece(" ", 0);
						
					}
					else
					{
						cout << "\t\t\t\t\t\tNOT Possible!\n";
					}
				}
				else if (arr[Next_Row][Next_Col] == arr[Current_Row - 1][Current_Col - 1])
				{
					if (arr[Next_Row][Next_Col]->GetPlayerName() != " " && arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
					{
						arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
						arr[Current_Row][Current_Col] = NULL;
						arr[Current_Row][Current_Col] = new piece(" ", 0);
						
					}
					else
					{
						cout << "\t\t\t\t\t\tNOT Possible!\n";
					}
				}
				else
				{
					cout << "\t\t\t\t\t\tNOT Possible!\n";
				}

			}
		}

	}

};
class Bishop :public piece
{
public:
	Bishop(string s, int n) :piece(s, n)
	{

	}
	
	void move(piece *arr[][8], int Current_Row, int Current_Col, int Next_Row, int Next_Col)
	{
		bool Testing = false;
		for (int i = Current_Row, j = Current_Col; (i > Next_Row && j > Next_Col); --i, ++j)
		{

			if (arr[Current_Row - i][Current_Col + i]->GetPlayerName() == " " && arr[Current_Row - i][Current_Col + i]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
			{
				Testing = true;
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
				break;
			}
		}
		for (int i = 1, j = 1; (i <= Next_Row && j <= Next_Col); ++i)
		{
			
			if (arr[Current_Row + i][Current_Col + i]->GetPlayerName() == " " && arr[Current_Row + i][Current_Col+i]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
			{
				Testing = true;
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
				break;
			}
		}
		for (int i = Current_Row, j = Current_Col; (i > Next_Row && j > Next_Col); --i,--j)
		{

			if (arr[Current_Row - i][Current_Col - i]->GetPlayerName() == " " && arr[Current_Row - i][Current_Col - i]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
			{
				Testing = true;
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
				break;
			}
		}
		for (int i = Current_Row, j = Current_Col; (i > Next_Row && j > Next_Col); ++i, --j)
		{

			if (arr[Current_Row + i][Current_Col - i]->GetPlayerName() == " " && arr[Current_Row + i][Current_Col - i]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
			{
				Testing = true;
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
				break;
			}
		}
		
		if (Testing == true)
		{
			arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
			arr[Current_Row][Current_Col] = NULL;
			arr[Current_Row][Current_Col] = new piece(" ", 0);
		}
	}
};
class Queen :public piece
{
public:
	Queen(string s, int n) :piece(s, n)
	{

	}
	void move(piece *arr[][8], int Current_Row, int Current_Col, int Next_Row, int Next_Col)
	{
		bool Testing = false;
		// For Right and Left Move 
		if (Current_Row == Next_Row)
		{
			for (int i = Current_Col, n = Current_Col; (i <= Next_Col || n >= Next_Col); ++i, --n)
			{
				if (arr[Next_Row][Next_Col]->GetPlayerName() == " " || arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
				{
					Testing = true;
				}
			}
			if (Testing == true)
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		//For Down and up Move
		else if (Current_Col == Next_Col)
		{
			for (int i = Current_Row, n = Current_Row; (i <= Next_Row || n >= Next_Row); ++i, --n)
			{

				if (arr[Next_Row][Next_Col]->GetPlayerName() == " " || arr[Next_Row][Next_Col]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
				{
					Testing = true;
				}
			}
			if (Testing == true)
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
			else
			{
				cout << "\t\t\t\t\t\tNOT Possible!\n";
			}
		}
		else
		{
			bool Testing = false;
			for (int i = 1, j = 1; (i <= Next_Row && j <= Next_Col); ++i)
			{

				if (arr[Current_Row + i][Current_Col + i]->GetPlayerName() == " " && arr[Current_Row + i][Current_Col + i]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
				{
					Testing = true;
				}
				else
				{
					cout << "\t\t\t\t\t\tNOT Possible!\n";
					break;
				}
			}
			for (int i = Current_Row, j = Current_Col; (i > Next_Row && j > Next_Col); --i, --j)
			{

				if (arr[Current_Row - i][Current_Col - i]->GetPlayerName() == " " && arr[Current_Row - i][Current_Col - i]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
				{
					Testing = true;
				}
				else
				{
					cout << "\t\t\t\t\t\tNOT Possible!\n";
					break;
				}
			}
			for (int i = Current_Row, j = Current_Col; (i > Next_Row && j > Next_Col); ++i, --j)
			{

				if (arr[Current_Row + i][Current_Col - i]->GetPlayerName() == " " && arr[Current_Row + i][Current_Col - i]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
				{
					Testing = true;
				}
				else
				{
					cout << "\t\t\t\t\t\tNOT Possible!\n";
					break;
				}
			}
			for (int i = Current_Row, j = Current_Col; (i > Next_Row && j > Next_Col); --i, ++j)
			{

				if (arr[Current_Row - i][Current_Col + i]->GetPlayerName() == " " && arr[Current_Row - i][Current_Col + i]->GetPlayerNumber() != arr[Current_Row][Current_Col]->GetPlayerNumber())
				{
					Testing = true;
				}
				else
				{
					cout << "\t\t\t\t\t\tNOT Possible!\n";
					break;
				}
			}
			if (Testing == true)
			{
				arr[Next_Row][Next_Col] = arr[Current_Row][Current_Col];
				arr[Current_Row][Current_Col] = NULL;
				arr[Current_Row][Current_Col] = new piece(" ", 0);
			}
		}
	}
};
void Initialization(piece *arr[][8])
{
	//initialization Chess Board
	//		First Row
	arr[0][0] = new Rook("R", 1);
	arr[0][1] = new Knight("kn", 1);
	arr[0][2] = new Bishop("B", 1);
	arr[0][3] = new Queen("Q", 1);
	arr[0][4] = new King("K", 1);
	arr[0][5] = new Bishop("B", 1);
	arr[0][6] = new Knight("kn", 1);
	arr[0][7] = new Rook("R", 1);
	// Second Row
	arr[1][0] = new Pawn("P", 1);
	arr[1][1] = new Pawn("P", 1);
	arr[1][2] = new Pawn("P", 1);
	arr[1][3] = new Pawn("P", 1);
	arr[1][4] = new Pawn("P", 1);
	arr[1][5] = new Pawn("P", 1);
	arr[1][6] = new Pawn("P", 1);
	arr[1][7] = new Pawn("P", 1);
	// Second Last Row
	arr[6][0] = new Pawn("P", 2);
	arr[6][1] = new Pawn("P", 2);
	arr[6][2] = new Pawn("P", 2);
	arr[6][3] = new Pawn("P", 2);
	arr[6][4] = new Pawn("P", 2);
	arr[6][5] = new Pawn("P", 2);
	arr[6][6] = new Pawn("P", 2);
	arr[6][7] = new Pawn("P", 2);
	//		Last Row
	arr[7][0] = new Rook("R", 2);
	arr[7][1] = new Knight("kn", 2);
	arr[7][2] = new Bishop("B", 2);
	arr[7][3] = new Queen("Q", 2);
	arr[7][4] = new King("K", 2);
	arr[7][5] = new Bishop("B", 2);
	arr[7][6] = new Knight("kn", 2);
	arr[7][7] = new Rook("R", 2);
	for (int i = 2; i < 6; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			arr[i][j] = new piece();
		}
	}
}
int main()
{
	
	chess();
	system("cls");
	system("COLOR f0");
	piece *arr[8][8];
	int Current_Row;
	int Current_Col;
	int Next_Row;
	int Next_Col;
	int n;
	cout << "\t\t\t.::Game instructions::.\n\t\tImportant Symbols That is Use in Game!\n P = Pawn\n R = Rook\n Kn = knight\n K = King\n Q = Queen\n B = Bishop\n";
	cout << "\n\n\t\t\tPress 1 For Start Game\n\t\t\tPress 2 For Exit Game\n Select Option : ";
	cin >> n;
	switch (n)
	{
	case 1:
	{
			  system("cls");
			  Initialization(arr);
			  ChessBoard(arr);
			  while (true)
			  {
												 //Player 1 Turn!
				  line1:
				  cout << "\t\t\t\t\t\tPlayer 1 Turn!\n";
				  cout << "Enter Current Row : ";
				  cin >> Current_Row;
				  cout << "Enter Current Col : ";
				  cin >> Current_Col;
				  cout << "Enter Next Row : ";
				  cin >> Next_Row;
				  cout << "Enter Next Col : ";
				  cin >> Next_Col;
				system("cls");
				if (arr[Current_Row][Current_Col]->GetPlayerNumber() == 1 && Next_Col >= 0 && Next_Row < 8 && Current_Col >= 0 && Current_Row < 8)
				{
					arr[Current_Row][Current_Col]->move(arr, Current_Row, Current_Col, Next_Row, Next_Col);
					ChessBoard(arr);
				}
				else
				{
					ChessBoard(arr);
					cout << "\t\t\t\t\tWrong Input Enter Again\n";
					goto line1;
				}
					
													//Player 2 Turn!
				line2 :
				cout << "\t\t\t\t\t\tPlayer 2 Turn!\n";
				  cout << "Enter Current Row : ";
				  cin >> Current_Row;
				  cout << "Enter Current Col : ";
				  cin >> Current_Col;
				  cout << "Enter Next Row : ";
				  cin >> Next_Row;
				  cout << "Enter Next Col : ";
				  cin >> Next_Col;
				  system("cls");
				  if (arr[Current_Row][Current_Col]->GetPlayerNumber() == 2 && Next_Col >= 0 && Next_Row < 8 && Current_Col >= 0 && Current_Row < 8)
				  {
					  arr[Current_Row][Current_Col]->move(arr, Current_Row, Current_Col, Next_Row, Next_Col);
					  ChessBoard(arr);
				  }
				  else
				  {
					  ChessBoard(arr);
					  cout << "\t\t\t\t\tWrong Input Enter Again\n";
					  goto line2;
				  }
			  }

	}
	case 2:
	{
			  exit(1);
	}
	default:
		cout << "\t\t\tWrong Input!\n";
		break;
	}
			system("pause");
}
