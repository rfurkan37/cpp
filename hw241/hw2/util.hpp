#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


enum class Type {I, O, T, J, L, S, Z};


class Tetromino
{
private:
	Type shape;
	void transpose();// transposing matrix
	void mirror(); // mirroring matrix
public:
	vector <vector<char>> blockPrint;
	Tetromino(Type);// this is a constructor
	Tetromino();// this is a constructor too
	void print();// this is print func
	void rotate(char turn);// rotate func
	int canFit(Tetromino another);//not working canFit func
};



#endif