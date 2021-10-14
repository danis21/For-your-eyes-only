#pragma once
#include <algorithm>
#include <iterator>

template <typename TElement>
class DynamicVector
{
private:
	TElement* elements;
	int size;
	int capacity;

public:
	/*
	Default constructor for Dynamic Vecotr
		input - int capacity, the capacity of the vector
		output -
	*/
	DynamicVector(int capacity = 10);

	/*
	Copy constructor for Dynamic Array
	input - int capacity, the capacity of the vector
	output -
*/
	DynamicVector(const DynamicVector& vector);
	
	//destructor for the DynamicArray
	~DynamicVector();


	//Assignment operator for the Vector
	DynamicVector& operator=(const DynamicVector& vector);

	/*
	Adds an element to Dynamic Vector
	input - TElement element, the new element that will be added
	output -
*/
	void add(TElement element);

	/*
	Deletes an existing element from the Vector
	input - int position, the position where the element is
	output -
*/
	void deleteElement(int position);

	/*
	Update an existing element from the Dynamic Vector
	input - TElement element, the new element that will be added
		-int position, the position of the element to be replaced
	output -
*/
	void update(const TElement& element, int position);


	/*
	Get the size of the Vector
	input -
	output -
*/
	int getSize();

	/*
	Get an specific element from the Vector
	input - int position, the position where the element is.
	output -
*/
	TElement& getElement(int position);
	int getPosition(TElement element);
	TElement& operator[](int position);

private:
	void resize();

public:
	class Iterator {
	private:
		TElement* index;
	public:
		Iterator() = default;
		Iterator(TElement* pointer) :index{ pointer } {}
		TElement operator*();
		bool operator!=(const Iterator& it);
		typename Iterator operator++();
		typename Iterator operator++(int notInUse);
		bool operator==(const Iterator& it);

	};

	typename Iterator begin();
	typename Iterator end();
};

template<typename TElement>
inline DynamicVector<TElement>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elements = new TElement[capacity];
}

template<typename TElement>
inline DynamicVector< TElement>::DynamicVector(const DynamicVector& vector)
{
	this->size = vector.size;
	this->capacity = vector.capacity;
	this->elements = new TElement[capacity];

	for (int index = 0; index < size; ++index)
	{
		elements[index] = vector.elements[index];
	}
}

template<typename TElement>
inline DynamicVector<TElement>::~DynamicVector()
{
	delete[] this->elements;
}

template<typename TElement>
inline void DynamicVector<TElement>::resize()
{
	this->capacity *= 2;

	TElement* newElements = new TElement[this->capacity];

	for (int index= 0; index < this->size; ++index)
		newElements[index] = this->elements[index];

	delete[] this->elements;
	this->elements = newElements;
}
template<typename TElement>
inline void DynamicVector<TElement>::add(TElement element)
{
	if (this->size == this->capacity)
	{
		resize();
	}
	this->elements[this->size++] = element;
}

template<typename TElement>
inline void DynamicVector<TElement>::update(const TElement& element, int position)
{
	this->elements[position] = element;
}

template<typename TElement>
inline void DynamicVector<TElement>::deleteElement(int position)
{
	for (int index = 0; index < this->size - 1; ++index)
	{
		this->elements[index] = this->elements[index + 1];
	}
	this->size--;
}

template<typename TElement>
inline TElement& DynamicVector<TElement>::getElement(int position)
{
	return this->elements[position];
}

template<typename TElement>
inline int DynamicVector<TElement>::getSize()
{
	return this->size;
}

template<typename TElement>
inline TElement& DynamicVector<TElement>::operator[](int position) 
{
	return this->elements[position];
}

template<typename TElement>
inline DynamicVector<TElement>& DynamicVector<TElement>::operator=(const DynamicVector& vector)
{
	if (this == &vector) {
		return *this;
	}
	this->capacity = vector.capacity;
	this->size = vector.size;
	delete[]this->elements;
	this->elements = new TElement[this->capacity];
	for (int index = 0; index < this->size; index++)
		this->elements[index] = vector.elements[index];
	return *this;
}

template<typename TElement>
inline typename DynamicVector<TElement>::Iterator DynamicVector<TElement>::begin()
{
	return Iterator{ this->elements };
}

template<typename TElement>
inline typename DynamicVector<TElement>::Iterator DynamicVector<TElement>::end()
{
	return Iterator{ this->elements + this->size };
}

template<typename TElement>
inline TElement DynamicVector<TElement>::Iterator::operator*()
{
	return *this->index;
}

template<typename TElement>
inline bool DynamicVector<TElement>::Iterator::operator!=(const Iterator& iterator)
{
	return this->index != iterator.index;
}

template<typename TElement>
inline typename DynamicVector<TElement>::Iterator DynamicVector<TElement>::Iterator::operator++()
{
	this->index++;
	return *this;
}

template<typename TElement>
inline typename DynamicVector<TElement>::Iterator DynamicVector<TElement>::Iterator::operator++(int notInUse)
{
	Iterator newIterator{ *this };
	this->index++;
	return newIterator;
}

template<typename TElement>
inline bool DynamicVector<TElement>::Iterator::operator==(const Iterator& iterator)
{
	return this->index == iterator.index;
}
template<typename TElement>
inline int DynamicVector<TElement>::getPosition(TElement element)
{
	for (int index = 0; index < this->size; index++)
		if (this->elements[index] == element)
			return index;
	return -1;
}