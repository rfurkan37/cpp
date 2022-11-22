#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "util.hpp"
#include "util2.hpp"
using namespace std;

int main()
{
	Tetromino a (Type::L);
	Tetris b (10,10);
	cout << "Tetromino functions" << "\n";
	cout << "1) Print(works properly)" << "\n";
	a.print();
	cout << "2) Rotate(works properly)" << "\n";
	a.rotate('R');
	a.print();
	a.rotate('R');
	a.print();
	cout << "3) canFit(canFit returns number of letter-including cells at the bottom of matrix after placing the shapes I didn't use it." << "\n";
	cout << Tetromino(Type::O).canFit(Tetromino(Type::L)) << "\n";
	cout << "Tetris functions" << "\n";
	cout << "1) Draw(works properly)" << "\n";
	b.Draw();
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n2) Add(works properly) adds certain coordinates a shape used in Fit Func\n" << "\n";
	b.Add(a, b.getRow(), 0);
	b.Draw();
	cout << "\n3) Fit(works properly but don't check if table is full)\n" << "\n";
	cout << "\n";
	b.Fit(a);
	b.Draw();
	cout << "4. Animate is not working :(" << "\n";	

	cout << "DRIVER 1 ENDS......" << "\n";

	return 0;
}