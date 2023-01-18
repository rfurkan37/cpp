#include "PFArray.hpp"

namespace RECPE
{
	template <typename T>
	void PFArray<T>::push_back(const T &value)
	{
		if (size_ == capacity) // if the array is full
		{
			capacity *= 2;										  // double the capacity
			std::shared_ptr<T> tmp(new T[capacity]);			  // create a new array with the new capacity
			std::copy(data.get(), data.get() + size_, tmp.get()); // copy the old array to the new array
			data = tmp;											  // set the old array to the new array
		}
		data.get()[size_++] = value; // add the value to the array
	}

	template <typename T>
	void PFArray<T>::pop_back()
	{
		if (size_ > 0) // if the array is not empty
		{
			size_--; // decrease the size
		}
	}

	template <typename T>
	void PFArray<T>::erase(iterator pos)
	{
		if (pos < begin() || pos >= end()) // if the iterator is out of range
		{
			throw std::out_of_range("Invalid iterator position."); // throw an exception
		}

		std::copy(pos + 1, end(), pos); // copy the array from the next element to the end to the current element
		--size_;						// decrease the size
	}

	template <typename T>
	void PFArray<T>::erase(iterator first, iterator last)
	{
		try
		{
			if (first < begin() || first  >= end() || last < begin() || last >= end()) // if the iterators are out of range
			{
				throw std::out_of_range("Invalid iterator position."); // throw an exception
			}
		}
		catch (const std::out_of_range &e) // catch the exception
		{
			std::cerr << e.what() << '\n'; // print the error message
			exit(0);					   // exit the program
		}
		std::copy(last.getPtr(), data.get() + size_, first.getPtr());
		size_ -= (last - first);
	}

	template <typename T>
	int PFArray<T>::size() const
	{
		return size_; // return the size
	}

	template <typename T>
	const T &PFArray<T>::operator[](size_t i) const
	{
		try
		{
			if (i < 0 || i >= size_)						   // if the index is out of range
				throw std::out_of_range("Index out of range"); // throw an exception
		}
		catch (const std::out_of_range &e) // catch the exception
		{
			std::cerr << e.what() << '\n'; // print the error message
			exit(0);					   // exit the program
		}
		return data.get()[i];
	}

	template <typename T>
	T &PFArray<T>::operator[](size_t i)
	{
		try
		{
			if (i < 0 || i >= size_)// if the index is out of range
				throw std::out_of_range("Index out of range");// throw an exception
		}
		catch (const std::out_of_range &e)// catch the exception
		{
			std::cerr << e.what() << '\n';// print the error message
			exit(0);// exit the program
		}
		return data.get()[i];// return the value at the index
	}

	template <typename T>
	bool PFArray<T>::operator==(const PFArray &other) const// check if two arrays are equal
	{
		if (size_ != other.size_)// if the sizes are not equal
			return false;// return false
		for (size_t i = 0; i < size_; i++)// loop through the array
			if (data.get()[i] != other.data.get()[i])// if the values are not equal
				return false;// return false
		return true;
	}

	template <typename T>
	PFArray<T> &PFArray<T>::operator=(const PFArray<T> &other)
	{
		if (this != &other)// if the arrays are not the same
		{
			size_ = other.size_;// set the size
			capacity = other.capacity;// set the capacity
			data = std::shared_ptr<T>(new T[capacity]);// create a new array
			std::copy(other.data.get(), other.data.get() + size_, data.get());// copy the values from the other array to the new array
		}
		return *this;// return the array
	}

} // namespace RECPE
