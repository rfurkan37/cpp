#ifndef VECTORECPE_HPP
#define VECTORECPE_HPP

#include <iostream>

template <typename Object>
class vectorecpe
{
private:
	size_t size = 0;
	size_t capacity = 4;
	Object* objects = nullptr;
	void reallocate();
	void move_arr(Object* dest, Object* src, size_t n);
	void copy(const vectorecpe<Object>& v);
public:

	vectorecpe();
	vectorecpe(size_t n);
	vectorecpe(size_t r, size_t c);
	vectorecpe(const Object& a,size_t n);
	vectorecpe(const vectorecpe<Object> &origin);
	~vectorecpe();
	const Object & operator[](size_t index ) const {return objects[index];}
	Object & operator[](size_t index){return objects[index];}
	void push_back(const Object& x);
	Object& back(){return objects[size - 1];}
	Object* begin() {return objects;}
	Object* end(){return objects + size;}
	
	vectorecpe<Object>& operator=(const vectorecpe<Object>& origin);
	int getSize() {return size;}
};

template <typename Object> void vectorecpe<Object>::copy(const vectorecpe<Object>& v)
{
	size = v.size;
	capacity = v.capacity;
    objects = new Object[capacity];

	for (size_t i = 0; i < size; i++)
    {
		objects[i] = v.objects[i];
	}
}

template <typename Object> vectorecpe<Object>::vectorecpe()
{
	objects = new Object[capacity];
}

template <typename Object> vectorecpe<Object>::vectorecpe(size_t n)
{
	size = n;
	capacity = n + n / 2 + 1;
	objects = new Object[capacity];

}

template <typename Object> vectorecpe<Object>::vectorecpe(const Object& a, size_t n)
{
	size = n;
	capacity = n + n / 2 + 1;
	objects = new Object[capacity];

	for(size_t i = 0; i < n; i++)
	{
		objects[i] = a;
	}

}

template <typename Object> inline vectorecpe<Object>::vectorecpe(const vectorecpe &origin)
{
    size = origin.size;
    capacity = origin.size;
    objects = new Object[capacity];
    for (size_t i = 0; i < size; i++)
        objects[i] = origin.objects[i];
}

template <typename Object> vectorecpe<Object>::~vectorecpe()
{
		for(int i = 0; i < size; i++)
		{
        	objects[i].~Object();
		}
}

template <typename Object> inline vectorecpe<Object>& vectorecpe<Object>::operator=(const vectorecpe<Object>& v)
{
	if (this != &v) {
		delete [] objects;
		this->copy(v); 
	}
		return *this;
}

template <typename Object> void	vectorecpe<Object>::push_back(const Object& x)
{
	if(size == capacity)
	{
		capacity += (capacity / 2) + 1;
		reallocate();
	}
	objects[size++] = x;
}

template <typename Object> void	vectorecpe<Object>::move_arr(Object* dest, Object* src, size_t n)
{
	if (dest < src)
    {
        Object *_dest = dest, *_src = src;
        for (size_t i = 0; i < n; i++)
            *_dest++ = std::move(*_src++);
    }
    else if (dest > src)
    {
        Object *_dest = dest + n - 1, *_src = src + n - 1;
        for (size_t i = n; i > 0; i--)
            *_dest-- = std::move(*_src--);
    }
    else
        return;

}

template <typename Object> void	vectorecpe<Object>::reallocate()
{
	Object* new_arr = new Object[capacity];

	move_arr(new_arr, objects, size);
	delete [] objects;
	objects = new_arr;
}


#endif