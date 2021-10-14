#include "DynamicVector.h"

DynamicVector::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elements = new TElement[capacity];
}

DynamicVector::DynamicVector(const DynamicVector& vector)
{
	this->size = vector.size;
	this->capacity = vector.capacity;
	this->elements = new TElement[this->capacity];
	for (int index = 0; index < this->size; index++)
	{
		this->elements[index] = vector.elements[index];
	}
}

DynamicVector::~DynamicVector()
{
	delete[] this->elements;
}

DynamicVector& DynamicVector::operator=(const DynamicVector& vector)
{
	if (this == &vector)
		return *this;
	this->size = vector.size;
	this->capacity = vector.capacity;

	delete[] this->elements;
	this->elements = new TElement[this->capacity];

	for (int index = 0; index < this->size; index++)
	{
		this->elements[index] = vector.elements[index];
	}

	return *this;
}

void DynamicVector::resize()
{
	this->capacity *= 2;

	TElement* newElements = new TElement[this->capacity];
	for (int index = 0; index < this->size; index++)
	{
		newElements[index] = this->elements[index];
	}
	delete[] this->elements;
	this->elements = newElements;
	delete[] newElements;
}

void DynamicVector::deleteElement(int position)
{
	int index;
	for (index = position; index < this->size; index++)
	{
		this->elements[index] = this->elements[index + 1];
	}
	this->size--;
}

void DynamicVector::update(const TElement& element, int position)
{
	this->elements[position] = element;
}

void DynamicVector::add(TElement element)
{
	if (this->size == this->capacity)
		this->resize();
	this->elements[this->size++] = element;
}

int DynamicVector::getSize() const
{
	return this->size;
}

TElement& DynamicVector::getElement(int position)
{
	return this->elements[position];
}