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
			{'I'},
			{'I'},// assigning the shapes
			{'I'},
			{'I'}
		};
		break;
	case Type:: O :
		blockPrint = 
		{
			{'O','O'},
			{'O','O'},
		};
		break;
	case Type::T :
		blockPrint =
		{
			{'T',' '},
			{'T','T'},
			{'T',' '}
		};
		break;
	case Type::J :
		blockPrint =
		{
			{' ','J'},
			{' ','J'},
			{'J','J'}
		};
		break;
	case Type::L :
		blockPrint =
		{
			{'L',' '},
			{'L',' '},
			{'L','L'}
		};
		break;
	case Type::S :
		blockPrint =
		{
			{' ','S','S'},
			{'S','S',' '}
		};
		break;
	case Type::Z :
		blockPrint =
		{
			{'Z','Z',' '},
			{' ','Z','Z'}
		};
		break;
	default:
		break;
	}
}

void Tetromino::rotate(char turn)
{
	if('R')
	{
		this->transpose(); // first transposing the matrix than mirroring
		this->mirror();
	}
	else if('L')
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
			oc[row][column]= this->blockPrint[row][this->blockPrint[0].size() - column -1];// mirroring the matrix
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

int Tetromino::canFit(Tetromino another)
{
	int i, j, counter = 0, curbosluk = 0, satirmaxbosluk = 0, intersatirlar = 0, satirmaxharf = 0;
	bool isSpace;
	vector<int> spaceVec;
	vector<int> harfVec;
	Tetromino fitting;

	for (auto &row : blockPrint)
	{
		isSpace = false;
		for (auto &cell : row)
		{
			if (cell != ' ')
				isSpace = true;
		}
		if (isSpace != false)
			fitting.blockPrint.push_back(row); // not pushing the full space rows
	}

	for (auto &row : another.blockPrint)
	{
		isSpace = false;
		for (auto &cell : row)
		{
			if (cell != ' ')
				isSpace = true;
		}
		if (isSpace != false)
			fitting.blockPrint.push_back(row); // not pushing the full space rows
	}

	for (auto count : {1, 2, 3})
		fitting.rotate('L'); // rotating 3 times to find the first order

	for (auto &row : fitting.blockPrint)
	{
		curbosluk = 0;
		for (auto &cell : row)
		{
			if (cell == ' ')
				curbosluk++; // counting spaces to delete them after
			else
			{
				if (curbosluk >= satirmaxbosluk)
					satirmaxbosluk = curbosluk; // taking max space for each row
				curbosluk = 0;
			}
		}
		if (curbosluk >= satirmaxbosluk)
			satirmaxbosluk = curbosluk;
		spaceVec.push_back(satirmaxbosluk); // making vector to find smallest 
		satirmaxbosluk = 0;
	}
	intersatirlar = *(min_element(spaceVec.begin(), spaceVec.end())); // finding min_element

	vector<int> v(intersatirlar);

	for (auto &row : fitting.blockPrint)
	{
		for (auto say : v)
		{
			row.erase(find(row.begin(), row.end(), ' ')); // eerasing space element
		}
	}

	int harf = 0;
	int a = 0, finalHarf = 0;
	for (int i = fitting.blockPrint[fitting.blockPrint.size() - 1].size() - 1; i >= 0; --i)
	{
		if (fitting.blockPrint[fitting.blockPrint.size() - 1][i] != ' ') // counting last row's letter count
			++harf;
	}

	fitting.print();
	return (harf);
}

