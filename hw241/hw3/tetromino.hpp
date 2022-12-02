#ifndef TETROMINO_HPP
#define TETROMINO_HPP

#include "vectorecpe.hpp"
#include <iostream>
//using namespace custom;

enum class Type {I, O, T, J, L, S, Z};

class Tetromino
{
private:
	Type shape;
	void transpose();// transposing matrix
	void mirror(); // mirroring matrix
public:
	vectorecpe <vectorecpe <char>> blockPrint;
	Tetromino(Type);// this is a constructor
	Tetromino();// this is a constructor too
	void print();// this is print func
	void rotate(char turn);// rotate func
	int canFit(Tetromino another);//not working canFit func
};

#endif