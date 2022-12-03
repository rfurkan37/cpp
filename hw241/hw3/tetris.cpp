#include "tetromino.hpp"
#include "tetris.hpp"

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

void Tetris::Erase(int si, int sj)
{

}

void Tetris::Animate()
{
	char rotation_direction, move_direction;
	int rotation_count,  move_count;
	int si = 0, sj = table[0].getSize() / 2;
	/* erase add döngüsü
	draw
	ask rotation direction and count
	ask move direction and count
	rotate and move
	draw
	sleep 50 miliseconds
	lower tetromino one level and draw sleep down

	*/
	Draw();
	cout << "Please enter rotation direction('L' || 'R'): ";
	cin >> rotation_direction;
	cout << "Please enter rotation count: ";
	cin >> rotation_count;

	cout << "Please enter move direction: ";
    cin >> move_direction;
	cout << "Please enter move count: ";
    cin >> move_count;

}

