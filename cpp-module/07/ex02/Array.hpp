#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>

using std::cout;
using std::endl;

template<typename T>
class Array {
public:
	Array() : _size(0), data(NULL) {};
	Array(unsigned int n){
		_size = n;
		data = new T[n];
	}
	Array(const Array& array)
	{
		*this = array;
	}

	Array& operator=(const Array& array){
		if(this == &array)
			return *this;
		_size = array._size;
		data = new T[_size];
		for(unsigned int i = 0; i < _size; i++){
			this->data[i] = array.data[i];
		}
		return *this;
	}


	T& operator[](unsigned int index){
		if(index < 0 || index >= _size)
			throw std::out_of_range("index is out of bounds");
		else
			return data[index];
	}

	~Array(){
		if(data)
			delete data;
	}

	unsigned int size(){ return this->_size; }


private:
	T *data;
	unsigned int _size;

};


#endif
