#ifndef HW4_HPP
#define HW4_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

namespace RECPE
{
	class DayofYearSet
	{
	public:
		class DayofYear
		{
		public:
			DayofYear();			 // default constructor assigns 1 january
			DayofYear(int m, int d); // constructor assigns month and day
			bool operator==(const DayofYear &element) const;
			bool operator!=(const DayofYear &element) const;
			string month;
			int day;
		};
		~DayofYearSet();
		DayofYearSet(const DayofYearSet &set);
		DayofYearSet();
		DayofYearSet(std::initializer_list<DayofYear> element); // default constructor
		friend ostream &operator<<(ostream &output, const DayofYearSet &set);
		bool operator==(const DayofYearSet &set) const; // checks if two sets are equal
		bool operator!=(const DayofYearSet &set) const; // checks if two sets are not equal
		DayofYearSet operator+(const DayofYearSet &set);
		DayofYearSet operator+(const DayofYear &element); // returns the union set as member func
		DayofYearSet operator-(const DayofYearSet &set);  // returns the difference set
		DayofYearSet operator-(const DayofYear &element);
		DayofYearSet operator^(const DayofYearSet &set);
		DayofYearSet operator=(const DayofYearSet &set);
		DayofYearSet operator!();
		DayofYear &operator[](int index);
		void remove(const DayofYear &element); // bu pointıra çevrilebilir.
		int getSize();

	private:
		DayofYear *dataSet;
		int size = 0;
		int capacity = 4;
		void reallocate();
		void move_set(DayofYear *dest, DayofYear *src, size_t n);
	};
}

















#endif