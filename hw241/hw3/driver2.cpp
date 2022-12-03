#include <iostream>
#include "vectorecpe.hpp"
#include "tetris.hpp"
#include "tetromino.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::cerr;


int main()
{
	int row, column,wrongFlag = 0;
	char buffer;
	char* line = new char[100];
	srand(time(NULL));
	vectorecpe<Tetromino> tetroVector;
	cout << "Welcome to the Tetris animation" << endl;
	cout << "\nPlease enter the size of Tetris table row:";
	cin >> row;
	cout << "Please enter the size of Tetris table column:";
	cin >> column;
	Tetris gameTable(row, column);
	cout << "From now on select one block from {I,O,T,J,S,Z,L} or R for random and Q for quit." << endl;
	while (true)
	{ 
		cin >> buffer;

		if (buffer == 'Q' || buffer == 'q')
			break;

		switch (buffer)
		{
		case 'R':
		case 'r':
			tetroVector.push_back(Tetromino(static_cast<Type>(rand() % 8)));
			break;
		case 'I':
		case 'i':
			tetroVector.push_back(Tetromino(Type ::I));
			break;
		case 'O':
		case 'o':
			tetroVector.push_back(Tetromino(Type ::O));
			break;
		case 'T':
		case 't':
			tetroVector.push_back(Tetromino(Type ::T));
			break;
		case 'J':
		case 'j':
			tetroVector.push_back(Tetromino(Type ::J));
			break;
		case 'L':
		case 'l':
			tetroVector.push_back(Tetromino(Type ::L));
			break;
		case 'S':
		case 's':
			tetroVector.push_back(Tetromino(Type ::S));
			break;
		case 'Z':
		case 'z':
			tetroVector.push_back(Tetromino(Type ::Z));
			break;
		default:
			cerr << "Wrong input try again !!" << endl;
			wrongFlag = 1;
			break;
		}

		gameTable += tetroVector.back(); // operator+= is calling add function
		gameTable.Animate(tetroVector.back()); // aniamte function takes care of everything
		cout << endl;
	}
	cout << "Game Over" << endl;

	return 0;


}
