#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>
#include <vector>
using namespace std;


enum class Type {I, O, T, J, L, S, Z};


class Tetromino
{
private:
	Type shape;
	vector <vector<char>> blockPrint;
	void transpose();// transposing matrix
	void mirror(); // mirroring matrix
public:
	Tetromino(Type);// this is a constructor
	Tetromino();// this is a constructor too
	void print();// this is print func
	void rotate(char turn);// rotate func
	bool canFit(Tetromino another);//not working canFit func
	static void bestFit(vector <Tetromino> tetroVector); // combining 
};



#endif
