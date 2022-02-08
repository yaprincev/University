#pragma once
#ifndef SET_H
#define SET_H

#include <iostream>
using namespace std;

template <typename sType>
class Set {
	static const int DEFAULT_SIZE = 20;
	static const int GROWTH_SIZE = 10;
	sType* _setPtr;
	int _memSize;
	int _size;
public:
	Set(int size = DEFAULT_SIZE);
	Set(const Set& other);
	~Set();

	int size() const { return _size; }
	int capacity() const { return _memSize; }

	void insert(const sType& value);  // добавление элемента
	void remove(const sType& value);  // удаление элемента
	int indexOf(const sType& value) const;  // возвращение индекса элемента
	bool isExist(const sType& value) const; // является ли value членом множества
	void unite(const Set<sType>& set);	//объединение множеств
	void subtract(const Set<sType>& set);	//вычитание множеств
	void intersect(const Set<sType>& set);	//пересечение множеств

	Set<sType>& operator =(const Set<sType>& other);

	template<typename sType>
	friend ostream& operator <<(ostream& stream, const Set<sType>& set);
};

template <typename sType>
Set<sType>::Set(int size) {
	_setPtr = new sType[size];
	_memSize = size;
	_size = 0;
}

template <typename sType>
Set<sType>::Set(const Set<sType>& other) {
	_memSize = other._memSize;
	_setPtr = new sType[_memSize];
	_size = other._size;
	for (int i = 0; i < _size; ++i)
		_setPtr[i] = other._setPtr[i];
}

template <typename sType>
Set<sType>::~Set() {
	delete[] _setPtr;
	_memSize = 0;
	_size = 0;
}

template <typename sType>
int Set<sType>::indexOf(const sType& value) const {
	for (int i = 0; i < _size; i++)
		if (_setPtr[i] == value)
			return i;
	return -1;
}

template <typename sType>
bool Set<sType>::isExist(const sType& value) const {
	return indexOf(value) != -1;
}

template <typename sType>
void Set<sType>::insert(const sType& value) {
	if (isExist(value))
		return;
	if (_size == _memSize) {
		_memSize += GROWTH_SIZE;
		sType* tmp = new sType[_memSize];
		for (int i = 0; i < _size; i++)
			tmp[i] = _setPtr[i];
		delete[] _setPtr;
		_setPtr = tmp;
	}
	int i = 0;
	while (i < _size && _setPtr[i] < value)
		++i;
	for (int j = _size - 1; j >= i; j--)
		_setPtr[j + 1] = _setPtr[j];
	_setPtr[i] = value;
	_size++;
}

template <typename sType>
void Set<sType>::remove(const sType& value) {
	int index = indexOf(value);
	if (index != -1) {
		for (; index < _size - 1; ++index)
			_setPtr[index] = _setPtr[index + 1];
		_size--;
	}
}

template <typename sType>
void Set<sType>::unite(const Set<sType>& set) {
	sType* tmp = new sType[_size + set._size];
	int i = 0, j = 0, index = 0;
	while (i < _size && j < set._size) {
		if (_setPtr[i] < set._setPtr[j])
			tmp[index++] = _setPtr[i++];
		else if (_setPtr[i] > set._setPtr[j])
			tmp[index++] = set._setPtr[j++];
		else {
			tmp[index++] = _setPtr[i++];
			++j;
		}
	}
	while (i < _size)
		tmp[index++] = _setPtr[i++];
	while (j < set._size)
		tmp[index++] = set._setPtr[j++];
	delete[] _setPtr;
	_setPtr = tmp;
	_memSize = _size + set._size;
	_size = index;
}

template <typename sType>
void Set<sType>::subtract(const Set<sType>& set) {
	sType* tmp = new sType[_memSize];
	int i = 0, j = 0, index = 0;
	while (i < _size && j < set._size) {
		if (_setPtr[i] < set._setPtr[j])
			tmp[index++] = _setPtr[i++];
		else if (_setPtr[i] > set._setPtr[j])
			tmp[index++] = set._setPtr[j++];
		else {
			j++;
			i++;
		}
	}
	while (i < _size)
		tmp[index++] = _setPtr[i++];
	delete[] _setPtr;
	_setPtr = tmp;
	_size = index;
}

template <typename sType>
void Set<sType>::intersect(const Set<sType>& set) {
	sType* tmp = new sType[_memSize];
	int i = 0, j = 0, index = 0;
	while (i < _size && j < set._size) {
		if (_setPtr[i] < set._setPtr[j])
			++i;
		else if (_setPtr[i] > set._setPtr[j])
			++j;
		else {
			tmp[index++] = _setPtr[i++];
			++j;
		}
	}
	delete[] _setPtr;
	_setPtr = tmp;
	_size = index;
}

template <typename sType>
ostream& operator <<(ostream& stream, const Set<sType>& set) {
	stream << "{ ";
	for (int i = 0; i < set._size; ++i)
		stream << set._setPtr[i] << " ";
	stream << "}";
	return stream;
}

template <typename sType>
Set<sType>& Set<sType>::operator =(const Set<sType>& other) {
	if (this == *other) return *this;
	_memSize = other._memSize;
	delete[] _setPtr;
	_setPtr = new sType[_memSize];
	_size = other._size;
	for (int i = 0; i < _size; ++i)
		_setPtr[i] = other._setPtr[i];
	return *this;
}

#endif