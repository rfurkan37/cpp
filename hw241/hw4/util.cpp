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
				bool operator == (const DayofYear& element) const;
				bool operator != (const DayofYear& element) const;
				int	day;
				string month;
			
		};
		DayofYearSet();
		DayofYearSet(std::initializer_list<DayofYear> element);// default constructor
		friend	ostream&	operator << (ostream& output, const DayofYearSet& set);
		bool				operator ==	(const DayofYearSet& set) const;// checks if two sets are equal
		bool				operator !=	(const DayofYearSet& set) const;// checks if two sets are not equal
		DayofYearSet		operator +	(const DayofYearSet& set);
		DayofYearSet&		operator +	(const DayofYear& element);// returns the union set as member func
		DayofYearSet		operator -	(const DayofYearSet& set);// returns the difference set
		DayofYearSet		operator -	(const DayofYear& element);
		DayofYearSet		operator ^	(const DayofYearSet& set);
		DayofYearSet		operator !	();
		DayofYear&			operator []	(int index){return dataSet[index]; };
		void				remove(const DayofYear& element); // bu pointıra çevrilebilir.
		int					getSize() {return size;};
		
		DayofYear* dataSet;
		int size = 0;
		int capacity = 4;
		void reallocate();
		void move_set(DayofYear* dest, DayofYear* src, size_t n);
};

DayofYearSet::DayofYearSet(std::initializer_list<DayofYear> element)
{
	dataSet = new DayofYear[capacity];
	for (auto i : element)
	{
		dataSet[size] = i;
		size++;
	}
}
ostream& operator << (ostream& output, const DayofYearSet& set)
{
	DayofYearSet::DayofYear *temp = set.dataSet;
	for (size_t i = 0; i < set.size; i++)
	{
		output << temp->month << " " << temp->day << endl;
		*temp++;
	}
	return output;
}


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

bool DayofYearSet::DayofYear::operator==(const DayofYear& element) const
{
	return ((month == element.month) && (day == element.day));
}

bool DayofYearSet::DayofYear::operator!=(const DayofYear& element) const
{
	return ((month != element.month) || (day != element.day));
}

bool DayofYearSet::operator==(const DayofYearSet& set) const
{
	if(size != set.size)
		return false;
	else
	{
		DayofYear *temp = dataSet;
		DayofYear *temp2 = set.dataSet;
		for (size_t i = 0; i < size; i++)
		{
			if(*temp != *temp2)
				return false;
			*temp++;
			*temp2++;
		}
		return true;
	}
}

DayofYearSet& DayofYearSet::operator+(const DayofYear& element)// add an element to set
{
	for (int i = 0; i < size; i++) {
      if (dataSet[i] == element) {
        // Element already exists, do nothing and return the set
        return *this;
      }
    }

    // Element does not exist, add it to the set
    if (size == capacity) {
      // Set is at capacity, increase capacity by a factor of 2 and reallocate
      capacity = capacity * 2;
      reallocate();
    }
    dataSet[size++] = element;
    return *this;
}

DayofYearSet DayofYearSet::operator-(const DayofYearSet& set)
{
    DayofYearSet temp;

    // Allocate memory for temp.dataSet
    temp.dataSet = new DayofYear[size];

    // Copy elements of dataSet into temp.dataSet that are not in set.dataSet
    for (size_t i = 0; i < size; i++)
    {
        bool found = false;
        DayofYear *temp2 = set.dataSet;
        for (size_t j = 0; j < set.size; j++)
        {
            if (dataSet[i] == *temp2)
            {
                found = true;
                break;
            }
            temp2++;
        }
        if (!found)
        {
            temp.dataSet[temp.size++] = dataSet[i];
        }
    }

    return temp;
}

DayofYearSet DayofYearSet::operator-(const DayofYear& element)
{
	remove(element);
	return *this;
}


DayofYearSet DayofYearSet::operator+(const DayofYearSet& set)
{
    DayofYearSet temp;

    // Allocate memory for temp.dataSet
    temp.dataSet = new DayofYear[size + set.size];

    // Copy dataSet into temp.dataSet
    for (size_t i = 0; i < size; i++)
    {
        temp.dataSet[temp.size++] = dataSet[i];
    }

    // Add elements from set.dataSet to temp.dataSet if they are not already present
    for (size_t i = 0; i < set.size; i++)
    {
        bool found = false;
        for (size_t j = 0; j < temp.size; j++)
        {
            if (set.dataSet[i] == temp.dataSet[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            temp.dataSet[temp.size++] = set.dataSet[i];
        }
    }

    return temp;
}



DayofYearSet DayofYearSet::operator^(const DayofYearSet& set)
{
    DayofYearSet temp;

    // Allocate memory for temp.dataSet
    temp.dataSet = new DayofYear[size];

    // Copy elements of dataSet into temp.dataSet that are also in set.dataSet
    for (size_t i = 0; i < size; i++)
    {
        bool found = false;
        DayofYear *temp2 = set.dataSet;
        for (size_t j = 0; j < set.size; j++)
        {
            if (dataSet[i] == *temp2)
            {
                found = true;
                break;
            }
            temp2++;
        }
        if (found)
        {
            temp.dataSet[temp.size++] = dataSet[i];
        }
    }

    return temp;
}

//DayofYearSet DayofYearSet::operator!()// returns the complement set

void DayofYearSet::reallocate()
{
	DayofYear* new_set = new DayofYear[capacity];
	
	move_set(dataSet, new_set, size);

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

void DayofYearSet::remove(const DayofYear& element)
{
	int fo = 0;
	DayofYear *temp = dataSet;
	for (size_t i = 0; i < this->size; i++)
	{
		if(*temp == element)
		{
			move_set(dataSet + i, dataSet + i + 1, size - i);
			size--;
			fo++;
			break;
		}
		*temp++;
	}
	if(fo == 0)
		cout << "Not found" << endl;
}


DayofYearSet::DayofYearSet()
{
	dataSet = new DayofYear[capacity];
}



int main()
{
	DayofYearSet::DayofYear day1(1, 1);
	DayofYearSet::DayofYear day2(2, 2);
	DayofYearSet::DayofYear day3(3, 3);
	DayofYearSet::DayofYear day4(4, 4);
	DayofYearSet::DayofYear day5(5, 5);
	DayofYearSet::DayofYear day6(1, 1);

	DayofYearSet set1{day1, day2, day3};
	DayofYearSet set2{day4, day5, day6};

	return 0;
}