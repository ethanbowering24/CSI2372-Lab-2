#pragma once

#define MAX_CARD 100
class Set
{
private:
	int card;
	int *elements;
	int capacity;
public:
	Set();
	Set(const Set&);
	~Set();//Destructor
	int cardinality();
	bool add_element(int);
	void remove_element(int);
	int get_item(int);
	bool is_member(int);
	bool equal(Set);
	bool subset(Set);
	Set Union(Set);
	Set intersection(Set);
	Set difference(Set);
	Set mutual_difference(Set);
};