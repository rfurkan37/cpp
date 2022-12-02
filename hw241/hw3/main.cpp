#include <iostream>
#include <cstring>

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
	void copy(const vectorecpe<Object>& v);
public:

	vectorecpe();
	vectorecpe(size_t n);
	vectorecpe(size_t r, size_t c);
	vectorecpe(const Object& a,size_t n);
	vectorecpe(const vectorecpe<Object> &origin);
    vectorecpe(vectorecpe<Object> &&origin) noexcept;
	~vectorecpe();
	const Object & operator[](size_t index ) const {return objects[index];}
	Object & operator[](size_t index){return objects[index];}
	void push_back(const Object& x);
	Object& back(){return objects[size - 1];}
	Object* begin() {return objects;}
	Object* end(){return objects + size;}
	
	vectorecpe<Object>& operator=(const vectorecpe<Object>& origin);  //Assign will modify reserved_size to origin.reserved_size, which behaves differently from STL vector.
        
	int getSize() {return size;}
    
};

template <typename Object> void vectorecpe<Object>::copy(const vectorecpe<Object>& v)
{
	size = v.size;
	capacity = v.capacity;
    objects = new Object[capacity];

	for (size_t i = 0; i < size; i++)
    {
		objects[i] = v.objects[i];
	}
}

template <typename Object> vectorecpe<Object>::vectorecpe()
{
	objects = new Object[capacity];
}

template <typename Object> vectorecpe<Object>::vectorecpe(size_t n)
{
	size = n;
	capacity = n + n / 2 + 1;
	objects = new Object[capacity];

}

template <typename Object> vectorecpe<Object>::vectorecpe(const Object& a, size_t n)
{
	size = n;
	capacity = n + n / 2 + 1;
	objects = new Object[capacity];

	for(size_t i = 0; i < n; i++)
	{
		objects[i] = a;
	}

}

template <typename Object> inline vectorecpe<Object>::vectorecpe(const vectorecpe &origin)
{
    size = origin.size;
    capacity = origin.size;
    objects = new Object[capacity];
    for (size_t i = 0; i < size; i++)
        objects[i] = origin.objects[i];
}

template <typename Object> vectorecpe<Object>::~vectorecpe()
{
		for(int i = 0; i < size; i++)
		{
        	objects[i].~Object();
		}
}

template <typename Object> inline vectorecpe<Object>& vectorecpe<Object>::operator=(const vectorecpe<Object>& v)
{
	if (this != &v) {
		delete [] objects;
		this->copy(v); 
	}
		return *this;
}

template <typename Object> void	vectorecpe<Object>::push_back(const Object& x)
{
	if(size == capacity)
	{
		capacity += (capacity / 2) + 1;
		reallocate();
	}
	objects[size++] = x;
}

template <typename Object> void	vectorecpe<Object>::move_arr(Object* dest, Object* src, size_t n)
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

template <typename Object> void	vectorecpe<Object>::reallocate()
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
		blockPrint[i][0] = 'I';
		}
		
		break;
	case Type:: O :
		for (size_t i = 0; i < 2; i++)
		{
		blockPrint.push_back(vectorecpe <char> (2));
		blockPrint[i][0] = 'O';
		blockPrint[i][1] = 'O';
		}
		break;
	case Type::T :
		for (size_t i = 0; i < 3; i++)
			blockPrint.push_back(vectorecpe <char> (2));
		
		blockPrint[0][0] = 'T';
		blockPrint[0][1] = ' ' ;
		blockPrint[1][0] = 'T';
		blockPrint[1][1] = 'T';
		blockPrint[2][0] = 'T';
		blockPrint[2][1] = ' ' ;

		break;
	case Type::J :
		for (size_t i = 0; i < 3; i++)
			blockPrint.push_back(vectorecpe <char> (2));
		
		blockPrint[0][0] = ' ';
		blockPrint[0][1] = 'J';
		blockPrint[1][0] = ' ';
		blockPrint[1][1] = 'J';
		blockPrint[2][0] = 'J';
		blockPrint[2][1] = 'J';

		break;
	case Type::L :

		for (size_t i = 0; i < 3; i++)
			blockPrint.push_back(vectorecpe <char> (2));
		
		blockPrint[0][0] = 'L';
		blockPrint[0][1] = ' ';
		blockPrint[1][0] = 'L';
		blockPrint[1][1] = ' ';
		blockPrint[2][0] = 'L';
		blockPrint[2][1] = 'L';

		break;
	case Type::S :
		
		for (size_t i = 0; i < 2; i++)
			blockPrint.push_back(vectorecpe <char> (3));
		
		blockPrint[0][0] = ' ';
		blockPrint[0][1] = 'S';
		blockPrint[0][2] = 'S';
		blockPrint[1][0] = 'S';
		blockPrint[1][1] = 'S';
		blockPrint[1][2] = ' ';

		break;
	case Type::Z :
		for (size_t i = 0; i < 2; i++)
			blockPrint.push_back(vectorecpe <char> (3));
		
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
			oc[column][row] = this->blockPrint[row][column];
			//cout << oc[row][column];
			 // transposing element and transferring to temp oc
		}
		//cout << endl;
	}
	this->blockPrint = oc;

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
	Tetris(const char *);
	Tetris(const int& row, const int& column);
	void Draw();
	void Animate();
	void Add(Tetromino sekil, int si, int sj);

	vectorecpe <vectorecpe <char>> table;
	int getRow() { return row; }
	int getColumn() { return column; }
	Tetris& operator+=(const Tetromino& Tetro);
};

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

; //  ,I, ,
									//  ,I, ,  for I letter for example taking i 4 minus becacuse it's size is 4 vertical 
									//  ,I, ,
	//cout << sekil.blockPrint[0].getSize() << endl;
	for (size_t i = 0; i < sekil.blockPrint.getSize(); i++)
	{
		for (size_t j = 0; j < sekil.blockPrint[0].getSize(); j++)
		{
			if(sekil.blockPrint[i][j] != ' ')
				table[sic][sjc] = sekil.blockPrint[i][j]; // printing cell
			sjc++;
			artirmasay++;
			//cout << "ben gonderdim" << endl;
		}
		sjc -= artirmasay; // taking j reverse to print next row
		artirmasay = 0; // 
		sic++; //
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

int main()
{
	int row, column,wrongFlag = 0;
	char buffer;
	char* line = new char[100];
	srand(time(NULL));
	vectorecpe<Tetromino> tetroVector; // legend came back
	cout << "Welcome to the Tetris animation" << endl;
	cout << "\nPlease enter the size of Tetris table row:";
	cin >> row;
	cout << "Please enter the size of Tetris table column:";
	cin >> column;
	Tetris gameTable(row, column);
	cout << "From now on select one block from {I,O,T,J,S,Z,L} or R for random and Q for quit." << endl;
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

		gameTable += tetroVector.back();
		gameTable.Draw();
		



		


		cout << endl;
	}
	cout << "Game Over" << endl;

	return 0;

}