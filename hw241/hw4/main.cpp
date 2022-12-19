#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "hw4.hpp"

using namespace std;
using namespace RECPE;



int main()
{
	ofstream outf {"output.txt"};

	DayofYearSet::DayofYear d1(1, 1);
	DayofYearSet::DayofYear d2(2, 2);
	DayofYearSet::DayofYear d3(3, 3);
	DayofYearSet::DayofYear d4(1, 1);
	DayofYearSet::DayofYear d5(5, 5);
	DayofYearSet::DayofYear d6(6, 6);

	DayofYearSet set1{d1, d2, d3};
	DayofYearSet set2{d3, d4, d5};

	DayofYearSet set3;

	cout << "Welcome to the Day of Year Set Program" << endl;

	cout << "Here is set1:\n" << set1 << endl;
	outf << "Here is set1:\n" << set1 << endl;

	cout << "Here is set2:\n" << set2 << endl;
	outf << "Here is set2:\n" << set2 << endl;

	cout << "Here is size of set1:\n" << set1.getSize() << endl;
	outf << "Here is size of set1:\n" << set1.getSize() << endl;

	cout << "Here is size of set2:\n" << set2.getSize() << endl;
	outf << "Here is size of set2:\n" << set2.getSize() << endl;

	set1 = set1 + d6;
	cout << "Here when we add d6(d6 is not in set1 and its 6 June) to set1:\n" << set1 << endl;
	outf << "Here when we add d6(d6 is not in set1 and its 6 June) to set1:\n" << set1 << endl;
	
	set1 = set1 + d3;
	cout << "Here when we add d3(d3 is in set1 and its 3 March) to set1:\n" << set1 << endl;
	outf << "Here when we add d3(d3 is in set1 and its 3 March) to set1:\n" << set1 << endl;

	set1 = set1 - d6;
	cout << "Here when we remove d6(d6 is in set1 and its 6 June) from set1:" << endl << set1 << endl;
	outf << "Here when we remove d6(d6 is in set1 and its 6 June) from set1:" << endl << set1 << endl;

	set3 = set1 + set2;
	cout << "Here is set3 which is set1 + set2:" << endl << set3 << endl;
	outf << "Here is set3 which is set1 + set2:" << endl << set3 << endl;

	set3 = set1 - set2;
	cout << "Here is set3 which is set1 - set2:" << endl << set3 << endl;
	outf << "Here is set3 which is set1 - set2:" << endl << set3 << endl;
	
	set3 = set1 ^ set2;
	cout << "Here is set3 which is set1 ^ set2(intersection):\n" << set3 << endl;
	outf << "Here is set3 which is set1 ^ set2(intersection):\n" << set3 << endl;

	set3 = !set1;
	
	cout << "Here is set3 which is !set1:\n" << set3 << endl;
	outf << "Here is set3 which is !set1:\n" << set3 << endl;


	return 0;
}