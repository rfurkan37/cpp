#include <iostream>
#include <vector>
using namespace std;

class MyVector
{
private:
	int data[100];
	int size;
public:
	MyVector()
	{
		size = 0;
	};
	MyVector(vector <int> a)
	{
		for(int i = 0; i < a.size(); i++)
		{
			pushBack(a[i]);
		}

	}
	void pushBack(int a)
	{
		data[size] = a;
		size++;
	}
	int size()
	{
		return size;
	}
	MyVector operator++(int a)
	{
		for(int i = 0; i < size; i++)
		{
			data[i]++;
		}
	return *this;
	}
	

};

int main()
{
	vector<int> vect = {1, 4, 5, 67, 34, 66};
	MyVector v1, v2(vect);
	
	v1.pushBack(23);
	cout << v1.size() << v1[0];

	cout << v2;

	cout << v2++;
	cout << ++v2;

	return 0;

}