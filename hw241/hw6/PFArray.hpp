#ifndef PFARRAY_HPP
#define PFARRAY_HPP

#include <iostream>
#include <memory>
#include <algorithm>

namespace RECPE
{
  template <typename T>
  class PFArray
  {
  private:
    std::shared_ptr<T> data;
    size_t size_;
    size_t capacity;

  public:
    class iterator
    {
    private:
      T *ptr;

    public:
      using value_type = T;
      using reference = T &;
      using pointer = T *;
      using difference_type = std::ptrdiff_t;
      using iterator_category = std::random_access_iterator_tag;

      iterator() : ptr(nullptr) {}
      iterator(T *p) : ptr(p) {}
      iterator(const iterator &other) : ptr(other.ptr) {}

      bool operator==(const iterator &other) const { return ptr == other.ptr; }
      bool operator!=(const iterator &other) const { return ptr != other.ptr; }
      bool operator<(const iterator &other) const { return ptr < other.ptr; }
      bool operator>(const iterator &other) const { return ptr > other.ptr; }
      bool operator<=(const iterator &other) const { return ptr <= other.ptr; }
      bool operator>=(const iterator &other) const { return ptr >= other.ptr; }

      T *getPtr() { return ptr; }
      const T *getPtr() const { return ptr; }

      T &operator*() { return *ptr; }
      const T &operator*() const { return *ptr; }

      T *operator->() { return ptr; }
      const T *operator->() const { return ptr; }

      difference_type operator-(const iterator &other) const { return ptr - other.getPtr(); } // return number difference
      iterator operator-(int n) { return iterator(ptr - n); }
      iterator &operator-=(int n)
      {
        ptr -= n;
        return *this;
      }
      iterator &operator--()// prefix
      {
        --ptr;
        return *this;
      }
      iterator &operator--(int)// postfix
      {
        iterator tmp = *this;
        --ptr;
        return tmp;
      }

      iterator operator+(int n) { return iterator(ptr + n); }
      iterator &operator+=(int n)
      {
        ptr += n;
        return *this;
      }
      iterator &operator++()
      {
        ++ptr;
        return *this;
      }
      iterator &operator++(int)
      {
        iterator tmp = *this;
        ++ptr;
        return tmp;
      }

      iterator &operator=(const iterator &other)
      {
        ptr = other.ptr;
        return *this;
      }
      iterator &operator=(T *p)
      {
        ptr = p;
        return *this;
      }
    };

    PFArray() : size_(0), capacity(2)
    {
      data = std::shared_ptr<T>(new T[capacity]);
    }

    PFArray(size_t cap) : size_(0), capacity(cap)
    {
      data = std::shared_ptr<T>(new T[capacity]);
    }

    PFArray(const PFArray &other) : size_(other.size_), capacity(other.capacity)
    {
      data = std::shared_ptr<T>(new T[capacity]);
      std::copy(other.data.get(), other.data.get() + size_, data.get());
    }

    PFArray &operator=(const PFArray &other);

    int size() const;

    T &operator[](size_t i);

    const T &operator[](size_t i) const;

    iterator begin() const
    {
      return iterator(data.get()); // returning begin
    }
    iterator end() const
    {
      return iterator(data.get() + size_); // returning end
    }
    const iterator cbegin() const
    {
      return iterator(data.get()); // returning begin but const
    }
    const iterator cend() const
    {
      return iterator(data.get() + size_); // returning end but const
    }

    bool operator==(const PFArray &other) const;
    bool operator!=(const PFArray &other) const { return !(*this == other); }

    void push_back(const T &value);

    void pop_back();

    void clear() { size_ = 0; }

    void erase(iterator pos);
    void erase(iterator first, iterator last);

    const bool empty() const { return size_ == 0; }
  };
} // namespace RECPE
#endif