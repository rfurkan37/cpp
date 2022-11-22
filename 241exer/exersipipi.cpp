#include <iostream>
using namespace std;

class A
{
public:
	int x;
	friend ostream &operator<<(ostream &stream, const A &other);
	friend istream &operator>>(istream &input, A &obj);
	A operator+(const A &obj)
	{
		A new_a;
		new_a.x = x + obj.x;

		return new_a;
	}
	bool operator==(const A &obj)
	{
		return (x == obj.x);
	}

	A& operator=(const A &obj)
	{
		if(this == &obj)
			return *this;

		x = obj.x;
		
	}
};

ostream &operator<<(ostream &stream, const A &other)
{
	stream << other.x << ' ';
	return stream;
}

istream &operator>>(istream &input, A &obj)
{
	input >> obj.x;
	return input;
}

int main()
{
	A a;
	A b;
	A c;


	cin >> a;
	cin >> b;

	c = a + b;


	cout << (a == b) << endl;
	cout << c;
}