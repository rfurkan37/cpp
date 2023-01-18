#include "vectorecpe.hpp"
#include "tetromino.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::move;

Tetromino::Tetromino() // bu da constructor 
{

}

Tetromino::Tetromino(Type tip) // bu constructor 
{
	shape = tip;
	switch (tip)
	{
	case Type::I :
		for (size_t i = 0; i < 4; i++)
		{
		blockPrint.push_back(vectorecpe <char> (1));
		blockPrint[i][0] = 'I';
		}
		
		break;
	case Type:: O :
		for (size_t i = 0; i < 2; i++)
		{
		blockPrint.push_back(vectorecpe <char> (2));
		blockPrint[i][0] = 'O';
		blockPrint[i][1] = 'O';// creating shapes
		}
		break;
	case Type::T :
		for (size_t i = 0; i < 3; i++)
			blockPrint.push_back(vectorecpe <char> (2));
		
		blockPrint[0][0] = 'T';
		blockPrint[0][1] = ' ' ;
		blockPrint[1][0] = 'T';
		blockPrint[1][1] = 'T';
		blockPrint[2][0] = 'T';
		blockPrint[2][1] = ' ' ;

		break;
	case Type::J :
		for (size_t i = 0; i < 3; i++)
			blockPrint.push_back(vectorecpe <char> (2));
		
		blockPrint[0][0] = ' ';
		blockPrint[0][1] = 'J';
		blockPrint[1][0] = ' ';
		blockPrint[1][1] = 'J';
		blockPrint[2][0] = 'J';
		blockPrint[2][1] = 'J';

		break;
	case Type::L :

		for (size_t i = 0; i < 3; i++)
			blockPrint.push_back(vectorecpe <char> (2));
		
		blockPrint[0][0] = 'L';
		blockPrint[0][1] = ' ';
		blockPrint[1][0] = 'L';
		blockPrint[1][1] = ' ';
		blockPrint[2][0] = 'L';
		blockPrint[2][1] = 'L';

		break;
	case Type::S :
		
		for (size_t i = 0; i < 2; i++)
			blockPrint.push_back(vectorecpe <char> (3));
		
		blockPrint[0][0] = ' ';
		blockPrint[0][1] = 'S';
		blockPrint[0][2] = 'S';
		blockPrint[1][0] = 'S';
		blockPrint[1][1] = 'S';
		blockPrint[1][2] = ' ';

		break;
	case Type::Z :
		for (size_t i = 0; i < 2; i++)
			blockPrint.push_back(vectorecpe <char> (3));
		
		blockPrint[0][0] = 'Z';
		blockPrint[0][1] = 'Z';
		blockPrint[0][2] = ' ';
		blockPrint[1][0] = ' ';
		blockPrint[1][1] = 'Z';
		blockPrint[1][2] = 'Z';
		break;
	default:
		break;
	}
}

void Tetromino::rotate(char turn)
{
	if(turn == 'R')
	{
		this->transpose(); // first transposing the matrix than mirroring
		this->mirror();
	}
	else
	{
		this->mirror(); // for left its the reverse version
		this->transpose();
	}
}

void Tetromino::transpose()
{
	vectorecpe <vectorecpe <char> > oc (vectorecpe <char> (this->blockPrint.getSize()), this->blockPrint[0].getSize());

	for(int row = 0; row < this->blockPrint.getSize(); row++)
	{
		for(int column = 0; column < this->blockPrint[0].getSize(); column++)
		{
			oc[column][row] = this->blockPrint[row][column];
		}
	}

	this->blockPrint = oc;
}

void Tetromino::mirror()
{
	vectorecpe <vectorecpe <char> > oc(vectorecpe <char> (this->blockPrint[0].getSize()), this->blockPrint.getSize() );

	for(int row = 0; row < this->blockPrint.getSize(); row++)
	{
		for(int column = 0; column < this->blockPrint[0].getSize(); column++)
		{
			oc[row][column]= this->blockPrint[row][this->blockPrint[0].getSize() - column - 1];// mirroring the matrix
		}
	}

	this->blockPrint= oc;
}

void Tetromino::print()
{
	for (int i = 0; i < blockPrint.getSize(); i++)
	{
		for (int j = 0; j < blockPrint[i].getSize(); j++)
		{
			cout << blockPrint[i][j];
		}
		cout << endl; // printing the matrix
	}
}
