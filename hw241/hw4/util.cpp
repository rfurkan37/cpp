#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class DayofYearSet
{
	public:
		class DayofYear
		{
			public:
				DayofYear();// default constructor assigns 1 january
				DayofYear(int m, int d);// constructor assigns month and day
				void	input();// reads in month and day from keyboard
				
			private:
				int	day, month;
			
		};
		DayofYearSet();// default constructor
		friend	ostream&	operator << (ostream& output, const DayofYearSet& set);
		bool				operator ==	(const DayofYearSet& set) const;// checks if two sets are equal
		bool				operator !=	(const DayofYearSet& set) const;// checks if two sets are not equal
		DayofYearSet		operator +	(const DayofYearSet& set);
		DayofYearSet		operator +	(const DayofYear& element);// returns the union set as member func
		DayofYearSet		operator -	(const DayofYearSet& set);// returns the difference set
		DayofYearSet		operator -	(const DayofYear& element);
		DayofYearSet		operator ^	(const DayofYearSet& set);
		DayofYearSet		operator !	();
		DayofYearSet		operator []	(int index);
		void				remove(const DayofYear& element); // bu pointıra çevrilebilir.
		int					size();

		
	private:
		DayofYear* dataSet;
		int size;
		int capacity;
};




int main()
{


	return 0;
}