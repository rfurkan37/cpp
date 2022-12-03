#ifndef TETRIS_HPP
#define TETRIS_HPP

#include "tetromino.hpp"

class Tetris
{
private:
	int row, column;
public:
	Tetris(const char *);
	Tetris(const int& row, const int& column);
	void Draw();
	void Animate(Tetromino sekil);
	void Add(Tetromino sekil, int si, int sj);
	void Erase(int si, int sj, Tetromino sekil);

	vectorecpe <vectorecpe <char>> table;
	int getRow() { return row; }
	int getColumn() { return column; }
	Tetris& operator+=(const Tetromino& Tetro);
};


#endif