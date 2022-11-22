#include "util.hpp"
using namespace std;

int main()
{
	srand(time(NULL));
	int numberOfTetrominos, i = 0;
	char buff;
	cout << "How many tetrominos?" << endl;
	cin >> numberOfTetrominos;
	vector <Tetromino> tetroVector; 
	cout << "What are the types?" << endl;
	while (i != numberOfTetrominos)
	{
		cin >> buff;
		switch (buff)
		{
		case 'i':
		case 'I':
			tetroVector.push_back(Tetromino(Type::I)); // creating new object and pushing into object
			break;
		case 'o':
		case 'O':
			tetroVector.push_back(Tetromino(Type::O));
			break;
		case 't':
		case 'T':
			tetroVector.push_back(Tetromino(Type::T));
			break;
		case 's':
		case 'S':
			tetroVector.push_back(Tetromino(Type::S));
			break;
		case 'z':
		case 'Z':
			tetroVector.push_back(Tetromino(Type::Z));
			break;
		case 'j':
		case 'J':
			tetroVector.push_back(Tetromino(Type::J));
			break;
		case 'l':
		case 'L':
			tetroVector.push_back(Tetromino(Type::L));
			break;
		default:
			cerr << "Wrong input!!" << endl; // at wrong input giving error message
			i--;
			break;
		}
		i++;
	}

	cout << "Your tetrominos:" << endl;

	for (int r = 0; r < numberOfTetrominos; r++)
	{
		tetroVector[r].print(); // printing all shapes
	}
	
	cout << "Horizontally best fit:" << endl;
	Tetromino::bestFit(tetroVector); // finding best fit and printing
	
	return 0;
}

