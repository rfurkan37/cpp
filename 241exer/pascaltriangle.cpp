#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generatePascalTriangle(int row)
{
	vector<vector<int> > result;

	for (int i = 1; i <= row; i++)
	{
		if(i == 1)
		{
			result.push_back(vector<int>(1));
			result[0][0] = 1;
		}	
		else if(i == 2)
		{
			result.push_back(vector<int>(2));
			result[1][0] = 1;
			result[1][1] = 1;
		}
		else
		{
			result.push_back(vector<int>(i));
			for(int j = 0; j < i; j++)
			{
				if(j == 0 || j == i)
					result[i - 1][j] = 1;
				else
					result[i - 1][j] = result[i - 2][j] + result[i - 2][j - 1];
			}
		}
	}

	for(auto a: result)
		{
			for (auto b: a)
				cout << b << "/";

			cout << endl;
		}


	return result;
}

int main()
{

	generatePascalTriangle(10);


	return 0;
}