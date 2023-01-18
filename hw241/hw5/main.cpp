#include <iostream>
#include <vector>
//#include <fstream>
#include <chrono>
#include <thread>

using namespace std;

enum class Type
{
	I,
	O,
	T,
	J,
	L,
	S,
	Z
};

class Tetromino
{
private:
	Type shape;
	void transpose(); // transposing matrix
	void mirror();	  // mirroring matrix
public:
	vector<vector<char>> blockPrint;
	Tetromino(Type);		// this is a constructor
	Tetromino();			// this is a constructor too
	void print();			// this is print func
	void rotate(char turn); // rotate func
};

Tetromino::Tetromino() // bu da constructor
{
}

Tetromino::Tetromino(Type tip) // bu constructor
{
	shape = tip;
	switch (tip)
	{
	case Type::I:
		for (size_t i = 0; i < 4; i++)
		{
			blockPrint.push_back(vector<char>(1));
			blockPrint[i][0] = 'I';
		}

		break;
	case Type::O:
		for (size_t i = 0; i < 2; i++)
		{
			blockPrint.push_back(vector<char>(2));
			blockPrint[i][0] = 'O';
			blockPrint[i][1] = 'O'; // creating shapes
		}
		break;
	case Type::T:
		for (size_t i = 0; i < 3; i++)
			blockPrint.push_back(vector<char>(2));

		blockPrint[0][0] = 'T';
		blockPrint[0][1] = ' ';
		blockPrint[1][0] = 'T';
		blockPrint[1][1] = 'T';
		blockPrint[2][0] = 'T';
		blockPrint[2][1] = ' ';

		break;
	case Type::J:
		for (size_t i = 0; i < 3; i++)
			blockPrint.push_back(vector<char>(2));

		blockPrint[0][0] = ' ';
		blockPrint[0][1] = 'J';
		blockPrint[1][0] = ' ';
		blockPrint[1][1] = 'J';
		blockPrint[2][0] = 'J';
		blockPrint[2][1] = 'J';

		break;
	case Type::L:

		for (size_t i = 0; i < 3; i++)
			blockPrint.push_back(vector<char>(2));

		blockPrint[0][0] = 'L';
		blockPrint[0][1] = ' ';
		blockPrint[1][0] = 'L';
		blockPrint[1][1] = ' ';
		blockPrint[2][0] = 'L';
		blockPrint[2][1] = 'L';

		break;
	case Type::S:

		for (size_t i = 0; i < 2; i++)
			blockPrint.push_back(vector<char>(3));

		blockPrint[0][0] = ' ';
		blockPrint[0][1] = 'S';
		blockPrint[0][2] = 'S';
		blockPrint[1][0] = 'S';
		blockPrint[1][1] = 'S';
		blockPrint[1][2] = ' ';

		break;
	case Type::Z:
		for (size_t i = 0; i < 2; i++)
			blockPrint.push_back(vector<char>(3));

		blockPrint[0][0] = 'Z';
		blockPrint[0][1] = 'Z';
		blockPrint[0][2] = ' ';
		blockPrint[1][0] = ' ';
		blockPrint[1][1] = 'Z';
		blockPrint[1][2] = 'Z';
		break;
	default:
		break;
	}
}

void Tetromino::rotate(char turn)
{
	if ('R')
	{
		this->transpose(); // first transposing the matrix than mirroring
		this->mirror();
	}
	else if ('L')
	{
		this->mirror(); // for left its the reverse version
		this->transpose();
	}
}

void Tetromino::transpose()
{
	vector<vector<char>> oc(this->blockPrint[0].size(), vector<char>(this->blockPrint.size()));

	for (int row = 0; row < this->blockPrint.size(); row++)
	{
		for (int column = 0; column < this->blockPrint[0].size(); column++)
		{
			oc[column][row] = this->blockPrint[row][column];
		}
	}

	this->blockPrint = oc;
}

void Tetromino::mirror()
{
	vector<vector<char>> oc(this->blockPrint.size(), vector<char>(this->blockPrint[0].size()));

	for (int row = 0; row < this->blockPrint.size(); row++)
	{
		for (int column = 0; column < this->blockPrint[0].size(); column++)
		{
			oc[row][column] = this->blockPrint[row][this->blockPrint[0].size() - column - 1]; // mirroring the matrix
		}
	}

	this->blockPrint = oc;
}

void Tetromino::print()
{
	for (int i = 0; i < blockPrint.size(); i++)
	{
		for (int j = 0; j < blockPrint[i].size(); j++)
		{
			cout << blockPrint[i][j];
		}
		cout << endl; // printing the matrix
	}
}

class AbstractTetris
{
public:
	virtual void Draw() = 0;
	// virtual void readFromFile() = 0;
	// virtual void writeToFile() = 0;
	virtual void Animate(Tetromino shape) = 0;
	// virtual void lastMove() = 0;
	// virtual void numberOfMoves() = 0;
};

class TetrisVector : public AbstractTetris
{
private:
	vector<vector<char>> table;
	int row, column;

public:
	TetrisVector(const char *);
	TetrisVector(const int &row, const int &column);
	void Draw();
	void Animate(Tetromino shape) override
	{
		char rotation_direction, move_direction;
		int rotation_count, move_count;
		int si = 0, sj = table[0].size() / 2;
		int shape_size, table_size = table[0].size(), table_verticalsize = table.size(), shape_verticalsize;
		Draw();
		Erase(si, sj, shape);

		cout << "Please enter rotation direction('L' || 'R'): ";
		cin >> rotation_direction;
		cout << "Please enter rotation count: ";
		cin >> rotation_count;

		while (rotation_count-- > 0)
			shape.rotate(rotation_direction); // rotating

		shape_size = shape.blockPrint[0].size();
		shape_verticalsize = shape.blockPrint.size();

		while (1)
		{
			cout << "Please enter move direction: ";
			cin >> move_direction; // taking the inputs

			cout << "Please enter move count: ";
			cin >> move_count;

			if (move_direction == 'L')
			{
				if (sj - move_count < 0)
					cout << "Out of borders try again!!" << endl; // looking at borders
				else
				{

					sj -= move_count;
					break;
				}
			}
			else if (move_direction == 'R')
			{
				if (sj + move_count + shape_size > table_size)
					cout << "Out of borders try again!!" << endl; // borders
				else
				{
					sj += move_count;
					break;
				}
			}
		}

		while (si + shape_verticalsize - 1 < table_verticalsize && table[si + shape_verticalsize - 1][sj] == ' ') // checking the bottom and the whitespace
		{
			Add(shape, si, sj);
			Draw();
			std::this_thread::sleep_for(std::chrono::milliseconds(50)); // sleep func
			Erase(si, sj, shape);
			cout << "\033[" << table.size() + 1 << "A"; // moving cursor
			cout << "\033[" << 10 << "D";

			si++;
		}

		cout << "\033[" << table.size() + 1 << "B";

		Add(shape, si - 1, sj);
	}
	void Add(Tetromino sekil, int si, int sj);
	void Erase(int si, int sj, Tetromino sekil);

	int getRow() { return row; }
	int getColumn() { return column; }
	TetrisVector &operator+=(const Tetromino &Tetro);
};

TetrisVector::TetrisVector(const int &row, const int &column)
{
	vector<char> rov;
	int column_copy = column, row_copy = row;

	while (column_copy-- > 0) // creating table
		rov.push_back(' ');

	while (row_copy-- > 0) // creating
	{
		table.push_back(rov);
	}
}

void TetrisVector::Add(Tetromino sekil, int si, int sj)
{
	int artirmasay = 0;
	int sic = si, sjc = sj;

	for (size_t i = 0; i < sekil.blockPrint.size(); i++)
	{
		for (size_t j = 0; j < sekil.blockPrint[0].size(); j++)
		{
			if (sekil.blockPrint[i][j] != ' ')
				table[sic][sjc] = sekil.blockPrint[i][j]; // printing cell
			sjc++;
			artirmasay++;
		}
		sjc -= artirmasay; // taking j reverse to print next row
		artirmasay = 0;
		sic++;
	}
}

void TetrisVector::Draw(void)
{
	int size = table[0].size();
	for (int i = 0; i < table.size(); i++)
	{
		std::cout << '#';
		for (int j = 0; j < table[i].size(); j++)
		{
			std::cout << table[i][j];
		}
		std::cout << '#';
		std::cout << endl; // printing the matrix
	}

	while (size-- + 2 > 0)
		std::cout << '#';

	std::cout << endl;
}

TetrisVector &TetrisVector::operator+=(const Tetromino &Tetro)
{
	this->Add(Tetro, 0, table[0].size() / 2); // middle of the top arr

	return *this;
}

void TetrisVector::Erase(int si, int sj, Tetromino sekil)
{
	int artirmasay = 0; // erasing the last drawed shape

	for (size_t i = 0; i < sekil.blockPrint.size(); i++)
	{
		for (size_t j = 0; j < sekil.blockPrint[0].size(); j++)
		{
			if (table[si][sj] != ' ')
				table[si][sj] = ' '; // printing cell
			sj++;
			artirmasay++;
		}
		sj -= artirmasay; // taking j reverse to print next row
		artirmasay = 0;
		si++;
	}
}

class TetrisArray1D : public AbstractTetris
{
private:
	char *table;

public:
	TetrisArray1D(/* args */);
	~TetrisArray1D();
};

TetrisArray1D::TetrisArray1D(/* args */)
{
}

TetrisArray1D::~TetrisArray1D()
{
}

class TetrisAdapter : public AbstractTetris
{
private:
	/* data */
public:
	TetrisAdapter(/* args */);
	~TetrisAdapter();
};

TetrisAdapter::TetrisAdapter(/* args */)
{
}

TetrisAdapter::~TetrisAdapter()
{
}

int main()
{
	int row, column;
	vector<Tetromino> tetroVector;

	char type, buffer;
	bool wrongFlag;
	std::cout << "Welcome to Tetris Game" << endl;

	std::cout << "Please enter table size: (row column)" << endl;

	cin >> row;
	cin >> column;

	std::cout << "Please enter Tetris type: (V-Vector, 1-Array1D, A-Adapter)" << endl;
	cin >> type;

	TetrisVector gameTableV(row, column);

	switch (type)
	{
	case '1':
		/* code */
		break;
	case 'A':
		/* code */
		break;
	case 'V':
		while (true)
		{
			cin >> buffer;

			if (buffer == 'Q' || buffer == 'q')
				break;

			switch (buffer)
			{
			case 'R':
			case 'r':
				tetroVector.push_back(Tetromino(static_cast<Type>(rand() % 8)));
				break;
			case 'I':
			case 'i':
				tetroVector.push_back(Tetromino(Type ::I));
				break;
			case 'O':
			case 'o':
				tetroVector.push_back(Tetromino(Type ::O));
				break;
			case 'T':
			case 't':
				tetroVector.push_back(Tetromino(Type ::T));
				break;
			case 'J':
			case 'j':
				tetroVector.push_back(Tetromino(Type ::J));
				break;
			case 'L':
			case 'l':
				tetroVector.push_back(Tetromino(Type ::L));
				break;
			case 'S':
			case 's':
				tetroVector.push_back(Tetromino(Type ::S));
				break;
			case 'Z':
			case 'z':
				tetroVector.push_back(Tetromino(Type ::Z));
				break;
			default:
				cerr << "Wrong input try again !!" << endl;
				wrongFlag = 1;
				break;
			}

			gameTableV += tetroVector.back();	   // operator+= is calling add function
			gameTableV.Animate(tetroVector.back()); // aniamte function takes care of everything
			std::cout << endl;
		}
		std::cout << "Game Over" << endl;
		break;
	default:
		break;
	}
}