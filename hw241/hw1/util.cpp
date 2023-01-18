#include "util.hpp"
using namespace std;


Tetromino::Tetromino() // bu da constructor 
{

}

Tetromino::Tetromino(Type tip) // bu constructor 
{
	shape = tip;
	switch (tip)
	{
	case Type::I :
		blockPrint =
		{
			{' ',' ',' '},// assigning the shapes
			{'I','I','I'},
			{' ',' ',' '}
		};
		break;
	case Type:: O :
		blockPrint = 
		{
			{' ',' ',' '},
			{'O','O',' '},
			{'O','O',' '},
		};
		break;
	case Type::T :
		blockPrint =
		{
			{' ',' ',' '},
			{'T','T','T'},
			{' ','T',' '}
		};
		break;
	case Type::J :
		blockPrint =
		{
			{' ',' ','J'},
			{' ',' ','J'},
			{' ','J','J'}
		};
		break;
	case Type::L :
		blockPrint =
		{
			{'L',' ',' '},
			{'L',' ',' '},
			{'L','L',' '}
		};
		break;
	case Type::S :
		blockPrint =
		{
			{' ',' ',' '},
			{' ','S','S'},
			{'S','S',' '}
		};
		break;
	case Type::Z :
		blockPrint =
		{
			{' ',' ',' '},
			{'Z','Z',' '},
			{' ','Z','Z'}
		};
		break;
	default:
		break;
	}
}

void Tetromino::bestFit(vector <Tetromino> tetroVector)
{
	vector <char> row(tetroVector.size()*3,' ');
	Tetromino fitting;
	tetroVector.insert(tetroVector.begin(), Tetromino(Type::O)); //temp object to apply canFit

	for(int i = 0; i < tetroVector.size() - 1; i++)
	{
		for(int x = 0; x < 4; x++)
		{
			if (tetroVector[i].canFit(tetroVector[i+1]) == false) // finding the best fit if not rotating the second object
				tetroVector[i+1].rotate('R');
			else
				break;
		}
	}
	
	tetroVector.erase(tetroVector.begin()); // erasing the temp object

	bool isSpace= false;

	for(auto &tetro : tetroVector)// rotating the vector
		tetro.rotate('R');

	for(auto &tetro : tetroVector)
	{
		for(auto &row : tetro.blockPrint)
		{
			isSpace= false;
			for(auto &cell : row)
			{
				if(cell != ' ')	isSpace= true; 
			}
			if(isSpace != false)
				fitting.blockPrint.push_back(row);// not pushing the full space rows
		}
	}

	for (auto count : {1,2,3})
		fitting.rotate('L'); // rotating 3 times to find the first order
	
	fitting.print(); // printing
}

void Tetromino::rotate(char turn)
{
	if(turn == 'R')
	{
		this->transpose(); // first transposing the matrix than mirroring
		this->mirror();
	}
	else if(turn == 'L')
	{
		this->mirror(); // for left its the reverse version
		this->transpose();
	}
}

void Tetromino::transpose()
{
	vector <vector <char>> oc(this->blockPrint[0].size(), vector <char> (this->blockPrint.size()));

	for(int row = 0; row < this->blockPrint.size(); row++)
	{
		for(int column = 0; column < this->blockPrint[0].size(); column++)
		{
			oc[column][row]= this->blockPrint[row][column]; // transposing element and transferring to temp oc
		}
	}

	this->blockPrint= oc;
}

void Tetromino::mirror()
{
	vector <vector <char>> oc(this->blockPrint.size(), vector <char> (this->blockPrint[0].size()));

	for(int row = 0; row < this->blockPrint.size(); row++)
	{
		for(int column = 0; column < this->blockPrint[0].size(); column++)
		{
			oc[row][column]= this->blockPrint[row][this->blockPrint[0].size() -column -1];// mirroring the matrix
		}
	}

	this->blockPrint= oc;
}

void Tetromino::print()
{
	for (int i = 0; i < blockPrint.size(); i++)
	{
		for (int j = 0; j < blockPrint[i].size(); j++)
		{
			cout << blockPrint[i][j];
		}
		cout << endl; // printing the matrix
	}
}

bool Tetromino::canFit(Tetromino another)
{
	int i,j, counter = 0;
	vector <vector <char>> fitting(3, vector <char> (6,' '));
// couldn't write best canFit function
	return (rand()%2); 
}

