#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template <class T>
struct node
{
	T *data;
	node<T> *next;
	node<T> *prev;
};

template <class T>
class List
{
private:
	node<T> *head;
	node<T> *tail;
public:
	template <class T>
	friend class ListIterator;

	List();
	List(const List<T> &l);
	~List();

	bool isEmpty() const;
	int size() const;
	int elementNumber(const T &t) const;
	void clear();

	void insert(ListIterator<T> iterator, const T &t);
	void erase(ListIterator<T> iterator);
	void pushFront(const T &t);
	void popFront();
	void pushBack(const T &t);
	void popBack();
	
	void printList()
	{
		node<T> *temp = head;
		while (temp != NULL) {
			cout << *(temp->data) << endl;
			temp = temp->next;
		}
	}

	ListIterator<T> begin();
	ListIterator<T> end();
};

template <class T>
List<T>::List()
{
	head = NULL;
	tail = NULL;
}

template <class T>
List<T>::List(const List<T> &l)
{
	head = NULL;
	tail = NULL;
	node<T> *temp = l.head;
	while (temp != NULL) {
		node<T> *p = new node<T>;
		p->data = new T(*(temp->data));

		if (head == NULL) {
			head = p;
			tail = p;
			p->next = NULL;
			p->prev = NULL;
		}
		else {
			tail->next = p;
			p->next = NULL;
			p->prev = tail;
			tail = p;
		}
		temp = temp->next;
	}
}

template <class T>
List<T>::~List()
{
	node<T> *temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp->data;
		delete temp;
	}
	tail = NULL;
}

template <class T>
bool List<T>::isEmpty() const
{
	return (head == NULL) || (tail == NULL);
}

template <class T>
void List<T>::insert(ListIterator<T> iterator, const T &t)
{
	int index = 0;
	ListIterator<T> temp = this->begin();

	while (temp != iterator) {
		index++;
		++temp;
	}

	int listSize = this->size();
	if (index < 0 || index > listSize)
		return;

	if (index == 0) {
		this->pushFront(t);
		return;
	}

	if (index == listSize) {
		this->pushBack(t);
		return;
	}

	node<T> *p = new node<T>;
	p->data = new T(t);

	node<T> *prev = head, *post = head->next;
	for (int i = 1; i < listSize; i++) {
		if (i == index) {
			prev->next = p;
			p->prev = prev;

			p->next = post;
			post->prev = p;

			return;
		}
		prev = post;
		post = post->next;
	}
}

template <class T>
void List<T>::erase(ListIterator<T> iterator)
{
	int index = 0;
	ListIterator<T> temp = this->begin();

	while (temp != iterator) {
		index++;
		++temp;
	}

	int listSize = this->size();
	if (index < 0 || index > listSize - 1)
		return;

	if (index == 0) {
		this->popFront();
		return;
	}

	if (index == listSize - 1) {
		this->popBack();
		return;
	}

	node<T> *prev = head, *post = head->next;
	for (int i = 1; i < listSize; i++) {
		if (i == index) {
			node<T> *temp = post->next;

			prev->next = temp;
			temp->prev = prev;

			delete post->data;
			delete post;

			return;
		}
		prev = post;
		post = post->next;
	}
}

template <class T>
void List<T>::pushFront(const T &t)
{
	node<T> *p = new node<T>;
	p->data = new T(t);

	if (this->isEmpty()) {
		head = p;
		tail = p;
		p->next = NULL;
		p->prev = NULL;
		return;
	}

	p->next = head;
	head->prev = p;
	p->prev = NULL;
	head = p;
}

template <class T>
void List<T>::popFront()
{
	if (this->isEmpty())
		return;

	node<T> *temp = head;
	head = head->next;
	delete temp->data;
	delete temp;

	if (this->isEmpty())
		tail = NULL;
	else
		head->prev = NULL;
}

template <class T>
void List<T>::pushBack(const T &t)
{
	node<T> *p = new node<T>;
	p->data = new T(t);

	if (this->isEmpty()) {
		head = p;
		tail = p;
		p->next = NULL;
		p->prev = NULL;
		return;
	}

	p->prev = tail;
	tail->next = p;
	p->next = NULL;
	tail = p;
}

template <class T>
void List<T>::popBack()
{
	if (this->isEmpty())
		return;

	node<T> *temp = tail;
	tail = tail->prev;
	delete temp->data;
	delete temp;

	if (this->isEmpty())
		head = NULL;
	else
		tail->next = NULL;
}

template <class T>
int List<T>::size() const
{
	int count = 0;
	node<T> *temp = head;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}

template <class T>
int List<T>::elementNumber(const T &t) const	//Amount of element
{
	node<T> *temp = head;
	int count = 0;
	while (temp != NULL) {
		if (*(temp->data) == t) {
			count++;
		}
		temp = temp->next;
	}
	return count;
}

template <class T>
void List<T>::clear()
{
	node<T> *temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp->data;
		delete temp;
	}
	tail = NULL;
}

template <class T>
ListIterator<T> List<T>::begin()
{
	ListIterator<T> iterator(*this);
	iterator.begin();
	return iterator;
}

template <class T>
ListIterator<T> List<T>::end()
{
	ListIterator<T> iterator(*this);
	iterator.end();
	return iterator;
}

#endif