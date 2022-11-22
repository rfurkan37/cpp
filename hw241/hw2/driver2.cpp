#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "util.hpp"
#include "util2.hpp"
using namespace std;

int main()
{
	int row, column,wrongFlag = 0;
	char buffer;
	string line;
	srand(time(NULL));
	vector<Tetromino> tetroVector; // legend came back
	cout << "Welcome to the Tetris animation" << endl;
	cout << "\nPlease enter the size of Tetris table(RxC):";
	getline(cin, line);
	Tetris gameTable(line);
	cout << "From now on select one block from {I,O,T,J,S,Z,L} or R for random and Q for quit." << endl;
	while (true)
	{
		cout << "\n" << "\033[A"; 
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

		if(wrongFlag != 1)
		{
			gameTable.Fit(tetroVector.back());
			cout << "\e[" << gameTable.table.size()+ 2 << "A";
			cout << "\e[G" << "\033[J";
			gameTable.Draw();
		}
		wrongFlag = 0;
	}
	cout << "Game Over" << endl;

	return 0;
}