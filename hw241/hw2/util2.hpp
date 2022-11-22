#ifndef UTIL2_HPP
#define UTIL2_HPP

#include <vector>
#include <string>
#include <iostream>
#include "util.hpp"

class Tetris
{
private:
	int row, column;
public:
	Tetris(string);
	Tetris(int, int);
	void Add(Tetromino, int, int);
	void Draw();
	void Fit(Tetromino);
	void Animate();
	vector<vector<char>> table;
	int getRow() { return row; }
	int getColumn() { return column; }
};



#endif