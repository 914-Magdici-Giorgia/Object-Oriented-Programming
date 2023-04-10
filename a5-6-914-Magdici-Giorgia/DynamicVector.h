#pragma once

template<typename T>
class DynamicVector {
private:
	T* elems;
	int size;
	int capacity;

public:
	//default constructor
	DynamicVector(int capacity = 10);

	//copy constructor
	DynamicVector(const DynamicVector& v);

	//destructor
	~DynamicVector();

	bool operator==(const DynamicVector& other_vector);

	//assignment operator for a DynsmicVector
	DynamicVector& operator=(const DynamicVector& v);

	//


	//	Overloading the subscript operator
	//	Input: pos -a valid position within the vector
	//	Output: a reference to the element on position pos
	T& operator[](int pos);

	DynamicVector<T> operator+(T e);

	//	add an element to the current DynamicVector
	void add(T e);

	void remove(T e);

	void update(T e, int pos);

	//	Returns the size of the DynamicVector
	int getSize() const;

	//Returns the capacity of the DynamicVector
	int getCapacity() const;

	

private:

	//resizes teh current DynamicVector, multiplying its capacity by a given factor (real number)
	void resize(int factor = 2);

public:
	class iterator {
	private:
		T* pointer;
	public:
		iterator(T* pointer) { this->pointer = pointer; }
		iterator operator++() { this->pointer++; return *this; }
		iterator operator++(int) { iterator i = *this; this->pointer++; return i; }
		T& operator*() { return *this->pointer; }
		bool operator!=(const iterator& it) { return this->pointer != it.pointer; }
		bool operator==(const iterator& it) { return this->pointer == it.pointer; }
	};

	iterator begin()
	{
		return iterator{ this->elems };
	}

	iterator end()
	{
		return iterator{ this->elems + this->size };
	}
};

template<typename T>
DynamicVector<T>::DynamicVector(int capacity) {
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template<typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v) {
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template<typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[]this->elems;
}

template<typename T>
T& DynamicVector<T>::operator[](int pos)
{
	return this->elems[pos];
}

template<typename T>
inline DynamicVector<T> DynamicVector<T>::operator+(T e)
{
	this->add(e);
	return *this;
}


template<typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
	//if (this == &v)
	//	return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

template<typename T>
bool DynamicVector<T>::operator==(const DynamicVector& other_vector)
{
	for (int i = 0; i < this->size; i++)
		if (this->elems[i] != other_vector.elems[i])
			return false;
	return this->size==other_vector.size;
}



template<typename T>
void DynamicVector<T>::add(T e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

template<typename T>
inline void DynamicVector<T>::remove(T e)
{
	int pos = -1;
	for (int i = 0; i < this->size; i++) {
		if (this->elems[i] == e) {
			pos = i;
			break;
		}
	}
	//if (pos == -1)
	//	return;

	for (int i = pos; i < this->size; i++)
		this->elems[i] = this->elems[i + 1];
	this->size--;
}

template<typename T>
void DynamicVector<T>::update(T e, int pos)
{
	this->elems[pos] = e;
}

template<typename T>
inline int DynamicVector<T>::getSize() const
{
	return this->size;
}

template<typename T>
int DynamicVector<T>::getCapacity() const
{
	return this->capacity;
}

template<typename T>
void DynamicVector<T>::resize(int factor)
{
	this->capacity *= factor;
	T* els = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}

