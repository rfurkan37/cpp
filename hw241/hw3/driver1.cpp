#include <iostream>
#include "tetromino.hpp"
#include "tetris.hpp"
#include "vectorecpe.hpp"

using namespace std;

int main()
{
	
	cout << "Tetromino functions" << endl;
	cout << "======================" << endl;
	Tetromino a (Type::I);

	cout << "print function works properly" << endl;
	a.print();  
	cout << "rotate function" << endl;
	a.rotate('R');
	a.print();

	cout << "Tetris functions" << endl;
	cout << "======================" << endl;
	Tetris t(10, 10);
	
	cout << "operator += call Add function works properly also Draw function" << endl;
	t += a;
	t.Draw();

	cout << "and now the animate function" << endl;

	t.Animate(a);

}