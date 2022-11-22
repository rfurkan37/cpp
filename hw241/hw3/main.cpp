#include <iostream>
using namespace std;

enum class Type {I, O, T, J, L, S, Z};

class Tetromino
{
private:
	Type shape;
	void transpose();// transposing matrix
	void mirror(); // mirroring matrix
public:
	char** blockPrint;
	Tetromino(Type);// this is a constructor
	Tetromino();// this is a constructor too
	void print();// this is print func
	void rotate(char turn);// rotate func
	int canFit(Tetromino another);//not working canFit func
};

class Tetris
{
public:
    Tetris(const int& row, const int& column);
    void Draw();
    void Animate();
    Tetris& operator+=(const Tetromino& Tetro);
};

Tetris::Tetris(const int& row, const int& column)
{
}

