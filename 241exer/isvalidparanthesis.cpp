#include <iostream>
#include <string>

using namespace std;

bool isValid(string s)
{
	int flag1 = 0, flag2 = 0 , flag3 = 0;


	for(auto i : s)
	{
		switch(i)
		{
			case '{':
				flag1 = 1;
				break;
			case '[':
				flag2 = 1;
				break;
			case '(':
				flag3 = 1;
				break;
			case '}':
				if(flag1 == 0 && flag2 + flag3 != 0)
					return false;
				flag1 = 0;
				break;
			case ']':
				if( flag2 == 0 && flag1 + flag3 != 0)
					return false;
				flag2 = 0;
				break;
			case ')':
				if(flag3 == 0 && flag1 + flag2 != 0)
					return false;
				flag3 = 0;
				break;
		}
	}
	if(flag1 + flag2 + flag3 == 0)
			return true;
		else
			return false;
}
	



int main()
{

	cout << isValid("{[]}") << endl;

}