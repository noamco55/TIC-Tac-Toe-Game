//XO.cpp
//This program Realizes the game tic tac toe between two players

//Noam cohen 312129596
//23.12.2018
//----------------------------------------------------------------------


#include <iostream>
using namespace std;

//the board of the game
struct Board
{
	char A1 = ' ', A2 = ' ', A3 = ' ', B1 = ' ', B2 = ' ', B3 = ' ', C1 = ' ', C2 = ' ', C3 = ' ';
};

//A point that points to a location on the board
struct PointOnBoard
{
	char row;
	char column;
};

typedef struct Board Board;
typedef struct PointOnBoard PointOnBoard;

void printBoard(Board board);
PointOnBoard nextInputX();
PointOnBoard nextInputO();
bool ifThePlaceTaken(PointOnBoard point , Board board);
bool ifThereIsAwinner(Board board);
bool ifItsAdraw(int turns , Board board);
Board PutOnBoard(PointOnBoard point, Board board,char sim);     
bool checkingValidInput(PointOnBoard point);
char ChangeSymbol(char sim);
PointOnBoard WhichInput(char sim, PointOnBoard point);

int main()
{
	int turn = 1;
	char sim = 'X';
	Board board;
	PointOnBoard point;

    printBoard(board);
	cout << "X start\n";
	point = nextInputX();    // take input from first player 

	// checking if the input is valid
	while (!checkingValidInput(point))
	{
		cout << "The input is not valid Please try again\n";
		point = nextInputX();
	}
	board = PutOnBoard(point, board, sim);   // placed the new input on the board
	printBoard(board);

	// checking if there is a winner or a draw
	while (ifThereIsAwinner(board)==false && ifItsAdraw(turn,board)==false)
	{
		sim = ChangeSymbol(sim);           // Change to next symbol
		point = WhichInput(sim, point);    // take the right input from the next player
		turn++;                            // count the turns of the game

		// checking if the input is valid and if the place of the input already taken 
		while (ifThePlaceTaken(point, board) || !checkingValidInput(point))
		{
			if(ifThePlaceTaken(point, board))
				cout << "This place is already taken please try again\n";
			if(!checkingValidInput(point))
				cout << "The point is not on the board Please try again\n";
			point = WhichInput(sim, point);     // take the right input from the next player
		}
		board = PutOnBoard(point, board,sim);  // placed the new input on the board
		printBoard(board);
	}

	// condition if there are no winners
	if (ifItsAdraw(turn , board))
		cout << "Its a draw\n";
	// condition if player 1 won
	else if (sim == 'X')
		cout << "Congratulations player X won!\n";
	else  // if player 2 won
		cout << "Congratulations player O won\n";
	system("pause");
}

// Change to next symbol
char ChangeSymbol(char sim)
{
	if (sim == 'X')
		sim = 'O';
	else
		sim = 'X';
	return sim;
}

// teke input from player X
PointOnBoard nextInputX()
{
	PointOnBoard x;
	cout << "Player X turn ,enter where you want to place your X\n";
	cin >> x.row >> x.column;
	return x;
}
// teke input from player O
PointOnBoard nextInputO()
{
	PointOnBoard o;
	cout << "Player O turn ,enter where you want to place your O\n";
	cin >> o.row >> o.column;
	return o;
}
// take the right input from the next player
PointOnBoard WhichInput(char sim, PointOnBoard point)
{
	if (sim == 'X')
		point = nextInputX();
	else
		point = nextInputO();;
	return point;
}

// print the board of the game
void printBoard(Board board)
{
	cout << "  1 2 3" << endl;
	cout << "A " << board.A1 << " " << board.A2 << " " << board.A3 << endl;
	cout << "B " << board.B1 << " " << board.B2 << " " << board.B3 << endl;
	cout << "C " << board.C1 << " " << board.C2 << " " << board.C3 << endl;

}

// checking if the input is valid
bool checkingValidInput(PointOnBoard point)
{
	bool res = true;
	if (point.row != 'A' && point.row != 'B' &&  point.row != 'C' || point.column != '1' && point.column != '2' && point.column != '3')
	{
		res = false;
	}
	return res;
}

// checking if the place of the input already taken
bool ifThePlaceTaken(PointOnBoard point, Board board)
{
	bool res = false;
	if (point.row == 'A' && point.column == '1' && board.A1 != ' ')
		res = true;
	if (point.row == 'A' && point.column == '2' && board.A2 != ' ')
		res = true;
	if (point.row == 'A' && point.column == '3' && board.A3 != ' ')
		res = true;
	if (point.row == 'B' && point.column == '1' && board.B1 != ' ')
		res = true;
	if (point.row == 'B' && point.column == '2' && board.B2 != ' ')
		res = true;
	if (point.row == 'B' && point.column == '3' && board.B3 != ' ')
		res = true;
	if (point.row == 'C' && point.column == '1' && board.C1 != ' ')
		res = true;
	if (point.row == 'C' && point.column == '2' && board.C2 != ' ')
		res = true;
	if (point.row == 'C' && point.column == '3' && board.C3 != ' ')
		res = true;
	return res;
}

// placed the new input on the board
Board PutOnBoard(PointOnBoard point, Board board,char sim)
{
	if (point.row == 'A' && point.column == '1')
		board.A1 = sim;
	if (point.row == 'A' && point.column == '2')
		board.A2 = sim;
	if (point.row == 'A' && point.column == '3')
		board.A3 = sim;
	if (point.row == 'B' && point.column == '1')
		board.B1 = sim;
	if (point.row == 'B' && point.column == '2')
		board.B2 = sim;
	if (point.row == 'B' && point.column == '3')
		board.B3 = sim;
	if (point.row == 'C' && point.column == '1')
		board.C1 = sim;
	if (point.row == 'C' && point.column == '2')
		board.C2 = sim;
	if (point.row == 'C' && point.column == '3')
		board.C3 = sim;
	return board;
}
// checking if there is a winner
bool ifThereIsAwinner(Board board)
{
	bool res = false;
	if (board.A1 == board.B1 && board.B1 == board.C1 && board.A1 != ' ' && board.B1 != ' ' && board.C1 != ' ')
		res = true;
	if (board.A2 == board.B2 && board.B2 == board.C2 && board.A2 != ' ' && board.B2 != ' ' && board.C2 != ' ')
		res = true;
	if (board.A3 == board.B3 && board.B3 == board.C3 && board.A3 != ' ' && board.B3 != ' ' && board.C3 != ' ')
		res = true;
	if (board.A1 == board.A2 && board.A2 == board.A3 && board.A1 != ' ' && board.A2 != ' ' && board.A3 != ' ')
		res = true;
	if (board.B1 == board.B2 && board.B2 == board.B3 && board.B1 != ' ' && board.B2 != ' ' && board.B3 != ' ')
		res = true;
	if (board.C1 == board.C2 && board.C2 == board.C3 && board.C1 != ' ' && board.C2 != ' ' && board.C3 != ' ')
		res = true;
	if (board.A1 == board.B2 && board.B2 == board.C3 && board.A1 != ' ' && board.B2 != ' ' && board.C3 != ' ')
		res = true;
	if (board.A3 == board.B2 && board.B2 == board.C1 && board.A3 != ' ' && board.B2 != ' ' && board.C1 != ' ')
		res = true;
	return res;
}

//  if there are no winners
bool ifItsAdraw(int turns , Board board)
{
	bool res = false;

	if (turns == 9 && !ifThereIsAwinner(board))
		res = true;
	return res;
}
