#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "ListIterator.h"

template <class Iterator>
void sort(Iterator first, Iterator last)
{
	while (first < --last)
		for (Iterator i = first; i < last; ++i)
			if (*(i + 1) < *i)
				swap(i, i + 1);
}

template <class Iterator, class T>
Iterator findElement(Iterator first, Iterator last, T value)
{
	for (Iterator i = first; i < last; ++i)
		if (*i == value)
			return i;
	return last;
}

template <class Iterator, class T, class Compare>
Iterator findElement(Iterator first, Iterator last, T value, Compare comp)
{
	for (Iterator i = first; i < last; ++i)
		if (comp(*i, value))
			return i;
	return last;
}

template <class Iterator>
Iterator findMin(Iterator first, Iterator last)
{
	Iterator min = first;
	for (Iterator i = first + 1; i < last; ++i)
		if (*i < *min)
			min = i;
	return min;
}

template <class Iterator>
Iterator findMax(Iterator first, Iterator last)
{
	Iterator max = first;
	for (Iterator i = first + 1; i < last; ++i)
		if (*i > *max)
			max = i;
	return max;
}

template <class Iterator, class T>
void fillData(Iterator first, Iterator last, T value)
{
	while (first != last) {
		*first = value;
		++first;
	}
}

template <class Iterator>
bool equal(Iterator first1, Iterator last1, Iterator first2)
{
	Iterator last2 = first2;
	last2.end();
	while (first1 < last1 && first2 < last2) {
		if (*first1 != *first2)
			return false;
		++first1;
		++first2;
	}

	if (first1 == last1 && first2 == last2)
		return true;
	return false;
}

template <class Iterator>
bool equal(Iterator first1, Iterator last1, Iterator first2, Iterator last2)
{
	while (first1 < last1 && first2 < last2) {
		if (*first1 != *first2)
			return false;
		++first1;
		++first2;
	}

	if (first1 == last1 && first2 == last2)
		return true;
	return false;
}

template <class Iterator>
void reverseElements(Iterator first, Iterator last)
{
	--last;
	while (first < last) {
		swap(first, last);
		++first;
		--last;
	}
}

template <class T>
void swap(ListIterator<T> &first, ListIterator<T> &second)
{
	T *data = first.getCurrentElement()->data;
	first.getCurrentElement()->data = second.getCurrentElement()->data;
	second.getCurrentElement()->data = data;
}

#endif
