#include <iostream>
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
    size = origin.vector_size;
    capacity = origin.reserved_size;
    objects = new T[reserved_size];
    for (size_t i = 0; i < size; i++)
        storage[i] = origin.storage[i];
}

template <typename Object>
vectorecpe<Object>::~vectorecpe()
{
	 if (objects != nullptr)
        delete[] objects;
}

template <typename Object>
void	vectorecpe<Object>::push_back(const Object& x)
{
	if(size == capacity)
	{
		capacity += capacity / 2 + 1;
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
	delete objects [];
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
		blockPrint
		break;
	case Type:: O :
		blockPrint = 
		{
			{'O','O'},
			{'O','O'},
		};
		break;
	case Type::T :
		blockPrint =
		{
			{'T',' '},
			{'T','T'},
			{'T',' '}
		};
		break;
	case Type::J :
		blockPrint =
		{
			{' ','J'},
			{' ','J'},
			{'J','J'}
		};
		break;
	case Type::L :
		blockPrint =
		{
			{'L',' '},
			{'L',' '},
			{'L','L'}
		};
		break;
	case Type::S :
		blockPrint =
		{
			{' ','S','S'},
			{'S','S',' '}
		};
		break;
	case Type::Z :
		blockPrint =
		{
			{'Z','Z',' '},
			{' ','Z','Z'}
		};
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
public:
    Tetris(const int& row, const int& column);
    void Draw();
    void Animate();
    Tetris& operator+=(const Tetromino& Tetro);
};

Tetris::Tetris(const int& row, const int& column)
{
}

int main()
{





	return 0;
}