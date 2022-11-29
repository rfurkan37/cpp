#include <iostream>
#include <string>

using namespace std;

enum class Type {I, O, T, J, L, S, Z};

template <typename Object>
class vectorecpe
{
private:
	size_t size = 0;
	size_t capacity = 4;
	Object* objects = nullptr;
	void reallocate();
	void move_arr(Object* dest, Object* src, size_t n);
public:

	vectorecpe();
	vectorecpe(size_t n);
	vectorecpe(const Object& a,size_t n);
	vectorecpe(const vectorecpe &origin);

	~vectorecpe();
	const Object & operator[](size_t index ) const {return objects[ index ];}
	Object & operator[](size_t index){return objects[index];}
	void push_back(const Object& x);
	Object& back(){return objects[size - 1];}

	int getSize() {return size;}
    
};

template <typename Object>
vectorecpe<Object>::vectorecpe()
{
	objects = new Object[capacity];
}

template <typename Object>
vectorecpe<Object>::vectorecpe(size_t n)
{
	size = n;
	capacity = n + n / 2 + 1;
	objects = new Object[capacity];

}

template <typename Object>
vectorecpe<Object>::vectorecpe(const Object& a, size_t n)
{
	size = n;
	capacity = n + n / 2 + 1;
	objects = new Object[capacity];

	for(size_t i = 0; i < n; i++)
	{
		objects[i] = a;
	}

}

template<typename Object>
vectorecpe<Object>::vectorecpe(const vectorecpe &origin)
{
    size = origin.size;
    capacity = origin.size;
    objects = new Object[capacity];
    for (size_t i = 0; i < size; i++)
        objects[i] = origin.objects[i];
}

template <typename Object>
vectorecpe<Object>::~vectorecpe()
{
		cout << "desktruk" << endl;
        	delete objects;
}

template <typename Object>
void	vectorecpe<Object>::push_back(const Object& x)
{
	if(size == capacity)
	{
		capacity += (capacity / 2) + 1;
		reallocate();
	}
	objects[size++] = x;
}

template <typename Object>
void	vectorecpe<Object>::move_arr(Object* dest, Object* src, size_t n)
{
	if (dest < src)
    {
        Object *_dest = dest, *_src = src;
        for (size_t i = 0; i < n; i++)
            *_dest++ = move(*_src++);
    }
    else if (dest > src)
    {
        Object *_dest = dest + n - 1, *_src = src + n - 1;
        for (size_t i = n; i > 0; i--)
            *_dest-- = move(*_src--);
    }
    else
        return;

}

template <typename Object>
void	vectorecpe<Object>::reallocate()
{
	Object* new_arr = new Object[capacity];

	move_arr(new_arr, objects, size);
	delete [] objects;
	objects = new_arr;
}

class Tetromino
{
private:
	Type shape;
	void transpose();// transposing matrix
	void mirror(); // mirroring matrix
public:
	vectorecpe <vectorecpe <char> > blockPrint;
	Tetromino(Type);// this is a constructor
	Tetromino();// this is a constructor too
	void print();// this is print func
	void rotate(char turn);// rotate func
	int canFit(Tetromino another);//not working canFit func
};


Tetromino::Tetromino() // bu da constructor 
{

}


Tetromino::Tetromino(Type tip) // bu constructor 
{
	shape = tip;
	switch (tip)
	{
	case Type::I :
		for (size_t i = 0; i < 4; i++)
		{
		blockPrint.push_back(vectorecpe <char> (1));
		blockPrint[i].push_back('I');
		}
		
		break;
	case Type:: O :
		for (size_t i = 0; i < 2; i++)
		{
		blockPrint.push_back(vectorecpe <char> (2));
		blockPrint[i].push_back('O');
		blockPrint[i].push_back('O');
		}
		break;
	case Type::T :
		for (size_t i = 0; i < 3; i++)
			blockPrint.push_back(vectorecpe <char> (2));
		
		blockPrint[0].push_back('T');
		blockPrint[0].push_back(' ');
		blockPrint[1].push_back('T');
		blockPrint[1].push_back('T');
		blockPrint[2].push_back('T');
		blockPrint[2].push_back(' ');

		break;
	case Type::J :
		for (size_t i = 0; i < 3; i++)
			blockPrint.push_back(vectorecpe <char> (2));
		
		blockPrint[0].push_back(' ');
		blockPrint[0].push_back('J');
		blockPrint[1].push_back(' ');
		blockPrint[1].push_back('J');
		blockPrint[2].push_back('J');
		blockPrint[2].push_back('J');

		break;
	case Type::L :

		for (size_t i = 0; i < 3; i++)
			blockPrint.push_back(vectorecpe <char> (2));
		
		blockPrint[0].push_back('L');
		blockPrint[0].push_back(' ');
		blockPrint[1].push_back('L');
		blockPrint[1].push_back(' ');
		blockPrint[2].push_back('L');
		blockPrint[2].push_back('L');

		break;
	case Type::S :
		
		for (size_t i = 0; i < 2; i++)
			blockPrint.push_back(vectorecpe <char> (3));
		
		blockPrint[0].push_back(' ');
		blockPrint[0].push_back('S');
		blockPrint[0].push_back('S');
		blockPrint[1].push_back('S');
		blockPrint[1].push_back('S');
		blockPrint[1].push_back(' ');

		break;
	case Type::Z :
		for (size_t i = 0; i < 2; i++)
			blockPrint.push_back(vectorecpe <char> (3));
		
		blockPrint[0].push_back('Z');
		blockPrint[0].push_back('Z');
		blockPrint[0].push_back(' ');
		blockPrint[1].push_back(' ');
		blockPrint[1].push_back('Z');
		blockPrint[1].push_back('Z');
		break;
	default:
		break;
	}
}

void Tetromino::rotate(char turn)
{
	if('R')
	{
		this->transpose(); // first transposing the matrix than mirroring
		this->mirror();
	}
	else if('L')
	{
		this->mirror(); // for left its the reverse version
		this->transpose();
	}
}


void Tetromino::transpose()
{
	vectorecpe <vectorecpe <char> > oc (vectorecpe <char> (this->blockPrint.getSize()), this->blockPrint[0].getSize());

	for(int row = 0; row < this->blockPrint.getSize(); row++)
	{
		for(int column = 0; column < this->blockPrint[0].getSize(); column++)
		{
			oc[column][row]= this->blockPrint[row][column]; // transposing element and transferring to temp oc
		}
	}

	this->blockPrint= oc;
}

void Tetromino::mirror()
{
	vectorecpe <vectorecpe <char> > oc(vectorecpe <char> (this->blockPrint[0].getSize()), this->blockPrint.getSize() );

	for(int row = 0; row < this->blockPrint.getSize(); row++)
	{
		for(int column = 0; column < this->blockPrint[0].getSize(); column++)
		{
			oc[row][column]= this->blockPrint[row][this->blockPrint[0].getSize() - column - 1];// mirroring the matrix
		}
	}

	this->blockPrint= oc;
}


void Tetromino::print()
{
	for (int i = 0; i < blockPrint.getSize(); i++)
	{
		for (int j = 0; j < blockPrint[i].getSize(); j++)
		{
			cout << blockPrint[i][j];
		}
		cout << endl; // printing the matrix
	}
}


class Tetris
{
private:
	int row, column;
public:
	Tetris(string);
	Tetris(const int& row, const int& column);
	void Draw();
	void Animate();
	vectorecpe <vectorecpe <char>> table;
	int getRow() { return row; }
	int getColumn() { return column; }
	Tetris& operator+=(const Tetromino& Tetro);
};

Tetris::Tetris(const int& row, const int& column)
{
}

Tetris::Tetris(const string input)
{
	int placeOfX;
	vectorecpe <char> rov;
	cout << "rov yapildi" << endl;

	placeOfX = input.find('x');
	row = atoi(input.substr(0, placeOfX).c_str());
	column = atoi(input.substr(placeOfX + 1, input.length() - placeOfX).c_str());
	while (column-- > 0) // creating table
		rov.push_back(' ');

	while (row-- > 0)
		table.push_back(rov); // creating table

	cout << "konstraktir biti";
}

int main()
{
	int row, column,wrongFlag = 0;
	char buffer;
	string line;
	srand(time(NULL));
	vectorecpe<Tetromino> tetroVector; // legend came back
	cout << "Welcome to the Tetris animation" << endl;
	cout << "\nPlease enter the size of Tetris table(RxC):";
	getline(cin, line);
	Tetris gameTable(line);
	cout << "From now on select one block from {I,O,T,J,S,Z,L} or R for random and Q for quit." << endl;
	while (true)
	{
		cout << "\n" << "\033[A"; 
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

		tetroVector.back().print();
		cout << endl;
	}
	cout << "Game Over" << endl;

	return 0;







	return 0;
}