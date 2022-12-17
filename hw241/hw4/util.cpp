#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <memory>

using namespace std;

class DayofYearSet
{
	public:
		class DayofYear
		{
			public:
				DayofYear();// default constructor assigns 1 january
				DayofYear(int m, int d);// constructor assigns month and day
			private:
				int	day;
				string month;
			
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
		int					size() {return sizeofSet;};

		
	private:
		DayofYear* dataSet;
		int sizeofSet = 0;
		int capacity = 4;
		void reallocate();
		void move_set(DayofYear* dest, DayofYear* src, size_t n);
};

DayofYearSet::DayofYear::DayofYear()
{
	day = 1;
	month = "January";
}

DayofYearSet::DayofYear::DayofYear(int m, int d)
{
	if((d < 0 && d > 31) || (m < 0 && m > 12))
	{
		cerr << "Wrong date input !!!" << endl;
		exit(1);
	}
	else if(m == 2 && d > 29)
	{
		cerr << "February wrong date input !!!" << endl;
		exit(1);
	}
	else if((m == 4 || m == 6 || m ==  9|| m == 11) && d == 31)
	{
		cerr << "This month doesn't have 31 days !!!" << endl;
		exit(1); 
	}
	else
		day = d;
		switch (m)
		{
		case 1:
			month = "January";
			break;
		case 2:
			month = "February";
			break;
		case 3:
			month = "March";
			break;
		case 4:
			month = "April";
			break;
		case 5:
			month = "May";
			break;
		case 6:
			month = "June";
			break;
		case 7:
			month = "July";
			break;
		case 8:
			month = "August";
			break;
		case 9:
			month = "September";
			break;
		case 10:
			month = "October";
			break;
		case 11:
			month = "November";
			break;
		case 12:
			month = "December";
			break;
		default:
			cerr << "Wrong input !!!" << endl;
			exit(1);
			break;
		}

}


void DayofYearSet::reallocate()
{
	DayofYear* new_set = new DayofYear[capacity];
	
	move_set(dataSet, new_set, sizeofSet);

	delete [] dataSet;

	dataSet = new_set;

}

void DayofYearSet::move_set(DayofYear* dest, DayofYear* src, size_t n)
{
  // Check if the arrays pointed to by dest and src overlap
	if (dest >= src && dest < src + n)
	{
    // The arrays overlap. Use a temporary buffer to hold the elements.
		std::unique_ptr<DayofYear[]> temp(new DayofYear[n]);

    // Copy the elements from src to the temporary buffer
		for (size_t i = 0; i < n; i++)
			temp[i] = std::move(src[i]);

    // Move the elements from the temporary buffer to dest
    	for (size_t i = 0; i < n; i++)
      		dest[i] = std::move(temp[i]);
	}
	else
	{	// The arrays do not overlap. Use the original approach to move the elements.
		if (dest < src)
		{	// Move the elements in increasing order
      		DayofYear *_dest = dest, *_src = src;
      		for (size_t i = 0; i < n; i++)
        		*_dest++ = std::move(*_src++);
		}
		else
		{	// Move the elements in decreasing order
      		DayofYear* _dest = dest + n - 1;
      		DayofYear* _src = src + n - 1;
      		for (size_t i = n; i > 0; i--)
        		*_dest-- = std::move(*_src--);
    	}
  	}
}



DayofYearSet::DayofYearSet()
{
	dataSet = new DayofYear[capacity];
}



int main()
{


	return 0;
}