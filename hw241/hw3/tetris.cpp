#include "tetromino.hpp"
#include "tetris.hpp"
#include  <chrono>
#include <thread>

using std::endl;
using std::cout;
using std::cin;



Tetris::Tetris(const int& row, const int& column)
{
	vectorecpe <char> rov;
	int column_copy = column, row_copy = row;

	while (column_copy-- > 0) // creating table
		rov.push_back(' ');
	
	while (row_copy-- > 0) // creating
	{
		table.push_back(rov);
	}
		
}

void Tetris::Add(Tetromino sekil, int si, int sj)
{
	int artirmasay = 0;
	int sic = si, sjc = sj;

	for (size_t i = 0; i < sekil.blockPrint.getSize(); i++)
	{
		for (size_t j = 0; j < sekil.blockPrint[0].getSize(); j++)
		{
			if(sekil.blockPrint[i][j] != ' ')
				table[sic][sjc] = sekil.blockPrint[i][j]; // printing cell
			sjc++;
			artirmasay++;
		}
		sjc -= artirmasay; // taking j reverse to print next row
		artirmasay = 0;
		sic++; 
	}

}

void Tetris::Draw(void)
{
	int size = table[0].getSize();
	for (int i = 0; i < table.getSize(); i++)
	{
		cout << '#';
		for (int j = 0; j < table[i].getSize(); j++)
		{
			cout << table[i][j];
		}
		cout << '#';
		cout << endl; // printing the matrix
	}

	while (size-- + 2 > 0)
		cout << '#';

	cout << endl;
}

Tetris& Tetris::operator+=(const Tetromino& Tetro)
{
	this->Add(Tetro, 0, table[0].getSize() / 2);

	return *this;
}

void Tetris::Erase(int si, int sj, Tetromino sekil)
{
	int artirmasay = 0;

	for (size_t i = 0; i < sekil.blockPrint.getSize(); i++)
	{
		for (size_t j = 0; j < sekil.blockPrint[0].getSize(); j++)
		{
			if(table[si][sj] != ' ')
				table[si][sj] = ' '; // printing cell
			sj++;
			artirmasay++;
		}
		sj -= artirmasay; // taking j reverse to print next row
		artirmasay = 0;
		si++; 
	}

}

void Tetris::Animate(Tetromino shape)
{
	char rotation_direction, move_direction;
	int rotation_count,  move_count;
	int si = 0, sj = table[0].getSize() / 2;
	int shape_size, table_size = table[0].getSize(), table_verticalsize = table.getSize(), shape_verticalsize;
	Draw();
	Erase(si, sj, shape);

	cout << "Please enter rotation direction('L' || 'R'): ";
	cin >> rotation_direction;
	cout << "Please enter rotation count: ";
	cin >> rotation_count;

	while(rotation_count-- > 0)
		shape.rotate(rotation_direction);


	shape_size = shape.blockPrint[0].getSize();
	shape_verticalsize = shape.blockPrint.getSize();

	while(1)
	{
	cout << "Please enter move direction: ";
    cin >> move_direction;

	cout << "Please enter move count: ";
    cin >> move_count;

	if(move_direction == 'L')
	{
		if(sj - move_count < 0)
			cout << "Out of borders try again!!" << endl; 
		else
		{

			sj -= move_count;
			break;
		}
	}
	else if(move_direction == 'R')
	{
		if(sj + move_count + shape_size > table_size)
			cout << "Out of borders try again!!" << endl;
		else
		{
			sj += move_count;
			break;
		}
	}
	}

	cout << shape_verticalsize << endl;
	cout << shape_size << endl;
	while(si +  shape_verticalsize - 1 < table_verticalsize && table[si + shape_verticalsize - 1][sj] == ' ' && shape.blockPrint[shape_verticalsize - 1][0] != ' ' && table[si + shape_verticalsize - 1][sj + 1] == ' ')
	{
		Add(shape, si, sj);
		Draw();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		Erase(si, sj, shape);
		cout << "\033[" << table.getSize() + 1 << "A";
		cout << "\033[" << 10 << "D";

		si++;
	}

	cout << "\033[" << table.getSize() + 1 << "B";


	Add(shape, si - 1, sj);


}

