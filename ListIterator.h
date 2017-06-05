#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "List.h"

template <class T>
class ListIterator
{
private:
	List<T> *list;
	node<T> *currentElement;
public:
	ListIterator();
	ListIterator(List<T> &list);

	ListIterator& operator++();
	ListIterator operator++(int);

	ListIterator& operator--();
	ListIterator operator--(int);

	ListIterator operator + (int number);
	ListIterator operator - (int number);

	T& operator*();

	bool operator == (ListIterator &iterator);
	bool operator != (ListIterator &iterator);

	bool operator > (ListIterator &iterator);
	bool operator < (ListIterator &iterator);

	void begin();
	void end();

	node<T>* getCurrentElement();
	void setCurrentElement(node<T> *currentElement);
};

template <class T>
ListIterator<T>::ListIterator()
{
	this->list = NULL;
	this->currentElement = NULL;
}

template <class T>
ListIterator<T>::ListIterator(List<T> &list)
{
	this->list = &list;
	this->currentElement = list.head;
}

template <class T>
ListIterator<T>& ListIterator<T>::operator++()
{
	if (currentElement == list->tail->next)
		this->begin();
	else
		this->currentElement = this->currentElement->next;
	return *this;
}

template <class T>
ListIterator<T> ListIterator<T>::operator++(int)
{
	ListIterator<T> temp = *this;
	++(*this);
	return temp;
}

template <class T>
ListIterator<T>& ListIterator<T>::operator--()
{
	if (currentElement == NULL)
		this->currentElement = list->tail;
	else
		this->currentElement = this->currentElement->prev;
	return *this;
}

template <class T>
ListIterator<T> ListIterator<T>::operator--(int)
{
	ListIterator<T> temp = *this;
	--(*this);
	return temp;
}

template <class T>
ListIterator<T> ListIterator<T>::operator+(int number)
{
	ListIterator<T> temp = *this;
	ListIterator<T> lastElement = list->end();

	for (int i = 0; temp != lastElement && i < number; i++, ++temp);

	return temp;
}

template <class T>
ListIterator<T> ListIterator<T>::operator-(int number)
{
	ListIterator<T> temp = *this;
	ListIterator<T> beforeFirst = --list->begin();

	if (temp == list->end()) {
		number--;
		--temp;
	}

	for (int i = 0; temp != beforeFirst && i < number; i++, --temp);

	return temp;
}

template <class T>
T& ListIterator<T>::operator*()
{
	if (currentElement == NULL)
		this->begin();
	return *(this->currentElement->data);
}

template <class T>
bool ListIterator<T>::operator==(ListIterator &iterator)
{
	return this->currentElement == iterator.currentElement;
}

template <class T>
bool ListIterator<T>::operator!=(ListIterator &iterator)
{
	return this->currentElement != iterator.currentElement;
}

template <class T>
bool ListIterator<T>::operator >(ListIterator &iterator)
{
	ListIterator<T> temp = list->begin();
	bool wasCurrent = false;
	bool wasIterator = false;

	while (temp != list->end()) {
		if (temp == *this)
			wasCurrent = true;
		if (temp == iterator)
			wasIterator = true;

		if (!wasCurrent && wasIterator)
			return true;
		else if (wasCurrent)
			return false;
		++temp;
	}
	return false;
}

template <class T>
bool ListIterator<T>::operator <(ListIterator &iterator)
{
	ListIterator<T> temp = list->begin();
	bool wasCurrent = false;
	bool wasIterator = false;

	while (temp != list->end()) {
		if (temp == *this)
			wasCurrent = true;
		if (temp == iterator)
			wasIterator = true;

		if (wasCurrent && !wasIterator)
			return true;
		else if (wasIterator)
			return false;
		++temp;
	}
	return false;
}

template <class T>
void ListIterator<T>::begin()
{
	currentElement = list->head;
}

template <class T>
void ListIterator<T>::end()
{
	currentElement = list->tail->next;
}

template <class T>
node<T>* ListIterator<T>::getCurrentElement()
{
	return currentElement;
}

template <class T>
void ListIterator<T>::setCurrentElement(node<T> *currentElement)
{
	this->currentElement = currentElement;
}

#endif