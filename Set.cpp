#include <iostream>
#include "Set.h"

using namespace std;

Set::Set()
{
	card = 0;
	capacity = 0;
	elements = new int[MAX_CARD];
	if (elements == NULL)
		cout << "Not enough memory for this set!" << endl;
	else
		capacity = MAX_CARD;
}

Set::Set(const Set& s)
{
	int i;
	elements = new int[s.capacity];
	if (elements == NULL)
		cout << "Not enough memory!" << endl;
	else
	{
		capacity = s.capacity;
		card = s.card;

		for (i = 0; i < s.card; ++i)
			elements[i] = s.elements[i];
	}
}

Set::~Set()
{
	delete[] elements;
}

int Set::cardinality()
{
	return card;
}

bool Set::is_member(int x)
{
	int i;
	for (i = 0; i < card; ++i)
		if (elements[i] == x) return true;

	return false;
}

int Set::get_item(int index)
{
	if (index < card)
		return elements[index];
	cout << "Index out of Range!" << endl;
	return 0; //just a default
}

bool Set::add_element(int x)
{
	int i;

	if (card == capacity)
	{
		int new_cap = capacity + MAX_CARD / 2;
		int *temp;
		temp = new int[new_cap];
		if (temp == NULL)
		{
			cout << "Not Enough Memory" << endl;
			return false;
		}

		for (i = 0; i < card; ++i)
			temp[i] = elements[i];

		delete [] elements;
		elements = temp;
		capacity = new_cap;
	}
	
	for (i = 0; i < card; ++i)
		if (elements[i] == x) return true;

	elements[card++] = x;
	return true;
}

void Set::remove_element(int x)
{
	int i, p = -1;

	for (i = 0; i < card; ++i)
	{
		if (elements[i] == x)
		{
			p = i;
			break;
		}
	}

	if (p != -1)
	{
		for (i = p; i < card; ++i)
			elements[i] = elements[i + 1];
		--card;
	}
}

bool Set::subset(Set s)
{
	int i;
	for (i = 0; i < card; ++i)
		if (!s.is_member(elements[i])) return false;

	return true;
}

bool Set::equal(Set s)
{
	//this --> E
	//int i;
	//this->elements[i];
	//this->card;
	//Set s
	//Set *p;

	//p = &s;
	//s.card;
	//p->card;

	//subset(s) == this->subset(s)
	//E called this method. (E is a set)
	//We want E to be a subset of s
	//And s to be a subset of E
	//this is a pointer that points E
	if (subset(s) && s.subset(*this))
		return true;

	return false;
}

Set Set::Union(Set s)
{
	int i;
	Set result;
	for (i = 0; i < card; ++i)
		result.add_element(elements[i]);

	for (i = 0; i < s.card; ++i)
		result.add_element(s.elements[i]);

	return result;
}

Set Set::intersection(Set s)
{
	int i;
	Set result;
	for (i = 0; i < card; ++i)
		if (s.is_member(elements[i])) result.add_element(elements[i]);

	return result;
}

Set Set::difference(Set s)
{
	int i;
	Set result;
	for (i = 0; i < card; ++i)
		if (!s.is_member(elements[i])) result.add_element(elements[i]);

	return result;
}

Set Set::mutual_difference(Set s)
{
	int i;
	Set s1 = difference(s);
	Set s2 = s.difference(*this);
	return s1.Union(s2);
}
