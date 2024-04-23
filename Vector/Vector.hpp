#pragma once
#include<iostream>
#include<cassert>

template<class T>
class vector
{
private:
	T* _arr;
	size_t _size;
	size_t _capacity;
public:
	vector() :_arr(nullptr), _size(0), _capacity(0) {}
	vector(size_t n);
	void Push_Back(const T& x);
	void Pop_Back();
	size_t size();
	T& operator[](size_t x);
	~vector();
};

template<class T>
vector<T>::vector(size_t n)
{
	_arr = new T[n];
	_size = 0;
	_capacity = n;
}
template<class T>
void vector<T>::Push_Back(const T& x)
{
	if (_size == _capacity)
	{
		size_t newcapacity = _capacity == 0 ? 2 : 2 * _capacity;
		T* temp = new T[newcapacity];
		if (_size)
		{
			memcpy(temp, _arr, sizeof(T) * _size);
			delete[] _arr;
		}
		_capacity = newcapacity;
		_arr = temp;
	}
	_arr[_size++] = x;
}
template<class T>
void vector<T>::Pop_Back()
{
	assert(_size > 0);
	--_size;
}
template<class T>
size_t vector<T>::size()
{
	return _size;
}
template<class T>
T& vector<T>::operator[](size_t x)
{
	assert(x >= 0 && x < _size);
	return _arr[x];
}
template<class T>
vector<T>::~vector()
{
	delete[] _arr;
	_size = 0;
	_capacity = 0;
}