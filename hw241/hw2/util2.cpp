#include "util2.hpp"
using namespace std;

Tetris::Tetris(int rowin, int columnin)
{
	vector<char> rov;

	row = rowin;
	column = columnin;

	while (columnin-- > 0)
		rov.push_back(' ');

	while (rowin-- > 0)
		table.push_back(rov);
}
Tetris::Tetris(const string input)
{
	int placeOfX;
	vector<char> rov;

	placeOfX = input.find('x');
	row = atoi(input.substr(0, placeOfX).c_str());
	column = atoi(input.substr(placeOfX + 1, input.length() - placeOfX).c_str());
	while (column-- > 0) // creating table
		rov.push_back(' ');

	while (row-- > 0)
		table.push_back(rov); // creating table
}

void Tetris::Draw(void)
{
	int size = table[0].size();
	for (int i = 0; i < table.size(); i++)
	{
		cout << '#';
		for (int j = 0; j < table[i].size(); j++)
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

void Tetris::Add(Tetromino sekil, int si, int sj)
{
	int artirmasay = 0;
	int sic = si, sjc = sj;

	sic -= sekil.blockPrint.size(); //  ,I, ,
									//  ,I, ,  for I letter for example taking i 4 minus becacuse it's size is 4 vertical 
									//  ,I, ,

	for (auto &row : sekil.blockPrint)
	{
		for (auto &cell : row)
		{
			table[sic][sjc++] = cell; // printing cell
			artirmasay++;
		}
		sjc -= artirmasay; // taking j reverse to print next row
		artirmasay = 0; // 
		sic++; //
	}

}
void Tetris::Fit(Tetromino shape)
{
	Tetris tempTable(this->table.size(), this->table[0].size()); // temporary table to put new letter in it and shift freely
	int si = tempTable.table.size();
	int sj = 0;
	char c;
	int broken = 0, done = 0;


	while (done != 1)
	{
		broken = 0; // check if it is not suitable
		for (auto i : {1, 2, 3, 4})
		{
			tempTable.Add(shape, si, sj); // adding shape to temporary

			for (int k = 0; k < tempTable.table.size(); k++)
			{
				for (int l = 0; l < tempTable.table[k].size(); l++)
				{
					c=this->table[k][l] + tempTable.table[k][l] - 32;
					if ((this->table[k][l] + tempTable.table[k][l] - 32 )>'Z') // if its letter and letter
					{
						broken = 1;
						break;
					}
				}
				if (broken)
					break; // exiting the loop
			}
			if (broken == 1)
			{
				shape.rotate('L');
				for (auto &row : tempTable.table)
				{
					for (auto &cell : row)
					{
						cell = ' '; // cleaning the temptable
					}
				}
			}
			else
			{
				done = 1; // if its okey prints ok
				broken = 0;
				break;
			}
		}
		if(broken != 1)
		{
			for (int k = 0; k < tempTable.table.size(); k++)
			{
				for (int l = 0; l < tempTable.table[k].size(); l++)
				{
					if (tempTable.table[k][l] != ' ')
					{
						this->table[k][l] = tempTable.table[k][l]; // putting shape on real table
					}
				}
			}
		}
		if (sj + 1 < tempTable.table[0].size()) // edge control
			sj++; 
		else
		{
			sj = 0;
			if (si - 1 > 0)
			{
				si--; // edge control
			}
		}
	}

}
