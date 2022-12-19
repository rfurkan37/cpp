#include <iostream>
#include "hw4.hpp"

using namespace std;

namespace RECPE
{
	int DayofYearSet::getSize()
	{
		return size;
	}

	DayofYearSet::DayofYearSet(std::initializer_list<DayofYear> elements)
	{
		size = elements.size(); // get the size of the initializer list
		capacity = size + 4; // add 4 to the size to get the capacity
		dataSet = new DayofYear[capacity]; // allocate the array
		int i = 0; // index for the array
		for (auto &d: elements) // iterate through the initializer list
		{
			dataSet[i] = d; // assign the element to the array
			i++; // increment the index
		}
	}

	DayofYearSet::~DayofYearSet()
	{
		delete[] dataSet; // delete the array
	}

	DayofYearSet::DayofYearSet(const DayofYearSet &set)
	{
		size = set.size;
		capacity = set.capacity;

		if (set.dataSet == nullptr)
		{
			// Object being copied is not initialized, so simply allocate a new array for the copy
			dataSet = new DayofYear[capacity];
		}
		else
		{
			// Allocate a new array with the same capacity as the object being copied
			dataSet = new DayofYear[capacity];

			// Copy elements of the object being copied to the new object
			std::copy(set.dataSet, set.dataSet + size, dataSet);
		}
	}

	DayofYearSet DayofYearSet::operator=(const DayofYearSet &set)
	{
		if (this == &set)
			return *this;
		else
		{
			delete[] dataSet;
			dataSet = new DayofYear[set.capacity];
			size = set.size;
			capacity = set.capacity;
			std::copy(set.dataSet, set.dataSet + set.size, dataSet);
			return *this;
		}
	}

	DayofYearSet::DayofYear &DayofYearSet::operator[](int index)
	{
		return dataSet[index];
	}
	ostream &operator<<(ostream &output, const DayofYearSet &set)
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
		if ((d < 0 && d > 31) || (m < 0 && m > 12))
		{
			cerr << "Wrong date input !!!" << endl;
			exit(1);
		}
		else if (m == 2 && d > 29)
		{
			cerr << "February wrong date input !!!" << endl;
			exit(1);
		}
		else if ((m == 4 || m == 6 || m == 9 || m == 11) && d == 31)
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

	bool DayofYearSet::DayofYear::operator==(const DayofYear &element) const
	{
		return ((month == element.month) && (day == element.day)); // compare two elements
	}

	bool DayofYearSet::DayofYear::operator!=(const DayofYear &element) const
	{
		return ((month != element.month) || (day != element.day)); // compare two elements
	}

	bool DayofYearSet::operator==(const DayofYearSet &set) const
	{
		if (size != set.size) //compare sizes first
			return false;
		else
		{
			DayofYear *temp = dataSet; // temp pointer to the first element of the set
			DayofYear *temp2 = set.dataSet; // temp pointer to the first element of the set
			for (size_t i = 0; i < size; i++)
			{
				if (*temp != *temp2)
					return false; // compare two elements
				*temp++;
				*temp2++;
			}
			return true;
		}
	}

	DayofYearSet DayofYearSet::operator+(const DayofYear &element) // add an element to set
	{
		for (int i = 0; i < size; i++)
		{
			if (dataSet[i] == element)
			{
				// Element already exists, do nothing and return the set
				return *this;
			}
		}

		// Element does not exist, add it to the set
		if (size == capacity)
		{
			// Set is at capacity, increase capacity by a factor of 2 and reallocate
			capacity = capacity * 2;
			reallocate();
		}
		dataSet[size++] = element;
		return *this;
	}

	DayofYearSet DayofYearSet::operator-(const DayofYearSet &set)
	{
		DayofYearSet temp;

		// Copy elements of dataSet into temp.dataSet that are not in set.dataSet
		for (size_t i = 0; i < size; i++)
		{
			bool found = false;
			DayofYear *temp2 = set.dataSet;
			for (size_t j = 0; j < set.size; j++)
			{
				if (dataSet[i] == *temp2)
				{
					found = true;// Element already exists, do nothing
					break;
				}
				temp2++;
			}
			if (!found)// Element does not exist, add it to the set
			{
				temp = temp + dataSet[i];
			}
		}

		return temp;
	}

	DayofYearSet DayofYearSet::operator-(const DayofYear &element)
	{
		remove(element); // using remove function
		return *this;
	}

	DayofYearSet DayofYearSet::operator+(const DayofYearSet &set)
	{
		DayofYearSet temp;

		// Allocate memory for temp.dataSet

		// Copy dataSet into temp.dataSet
		for (size_t i = 0; i < size; i++)
		{
			temp = temp + dataSet[i];
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
				temp = temp + set.dataSet[i];
			}
		}

		return temp;
	}

	DayofYearSet DayofYearSet::operator^(const DayofYearSet &set)
	{
		DayofYearSet temp;

		// Allocate memory for temp.dataSet

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
				temp = temp + dataSet[i];
			}
		}

		return temp;
	}

	DayofYearSet DayofYearSet::operator!() // returns the complement set
	{
		vector<string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		vector<int> days = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		DayofYearSet complimentSet;

		for (int i = 0; i < months.size(); i++) // loop through months
		{
			for (int j = 1; j <= days[i]; j++)// loop through days
			{
				DayofYear tempDay(i + 1, j); // create a day object
				complimentSet = complimentSet + tempDay; // add the day object to the set
			}
		}

		return (complimentSet - *this); // return the compliment set
	}
	void DayofYearSet::reallocate()
	{
		DayofYear *new_set = new DayofYear[capacity]; // Allocate memory for new set

		move_set(new_set, dataSet, size); // copy elements from old set to new set

		delete[] dataSet; // Deallocate memory for old set

		dataSet = new_set; // Set dataSet to new set
	}

	void DayofYearSet::move_set(DayofYear *dest, DayofYear *src, size_t n)
	{
		for (size_t i = 0; i < n; i++) // Copy elements from src to dest
		{
			dest[i] = src[i];
		}
	}

	void DayofYearSet::remove(const DayofYear &element)
	{
		// Search for the element in the set
		int index = -1;
		for (int i = 0; i < size; i++)
		{
			if (dataSet[i] == element)
			{
				index = i;
				break;
			}
		}

		// If the element was found, remove it by shifting the remaining elements left
		if (index != -1)
		{
			for (int i = index; i < size - 1; i++)
				dataSet[i] = dataSet[i + 1];
			size--;
		}
	}

	DayofYearSet::DayofYearSet()
	{
		dataSet = new DayofYear[capacity];
	}
}