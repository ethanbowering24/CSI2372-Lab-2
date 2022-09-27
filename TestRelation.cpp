#include <iostream>
#include "Set.h"
#include "Relation.h"

using namespace std;

int main()
{
	Relation R, S, T, U, W, X, Y, Z;
	int i;

	for (i = 1; i <= 50; ++i)
	{
		R.add_to_set(i);
		S.add_to_set(i);
		T.add_to_set(i);
		U.add_to_set(i);
		W.add_to_set(i);
		X.add_to_set(i);
		Y.add_to_set(i);
		Z.add_to_set(i);
	}

	for (i = 1; i <= 50; ++i)
	{
		Pair p;
		p.first = p.second = i;
		R.add_element(p);
	}

	for (i = 1; i <= 40; ++i)
	{
		Pair p;
		p.first = p.second = i;
		S.add_element(p);
	}

	//Testing Cardinality
	if (R.cardinality() == 50) cout << "Cardinality - Test 1 - Passed." << endl;
	else cout << "Cardinality - Test 1 - Failed!" << endl;

	if (S.cardinality() == 40) cout << "Cardinality - Test 2 - Passed." << endl;
	else cout << "Cardinality - Test 2 - Failed!" << endl;

	if (T.cardinality() == 0) cout << "Cardinality - Test 3 - Passed." << endl;
	else cout << "Cardinality - Test 3 - Failed!" << endl;

	//Testing is_member
	Pair p;
	p.first = 10;
	p.second = 10;
	if (R.is_member(p)) cout << "is_member - Test 1 - Passed." << endl;
	else cout << "is_member - Test 1 - Failed!" << endl;

	p.first = 5;
	p.second = 2;
	if (!S.is_member(p)) cout << "is_member - Test 2 - Passed." << endl;
	else cout << "is_member - Test 2 - Failed!" << endl;

	if (!T.is_member(p)) cout << "is_member - Test 3 - Passed." << endl;
	else cout << "is_member - Test 3 - Failed!" << endl;

	p.first = 40;
	p.second = 40;
	if (S.is_member(p)) cout << "is_member - Test 4 - Passed." << endl;
	else cout << "is_member - Test 4 - Failed!" << endl;


	//Testing add_element
	p.first = 2;
	p.second = 5;
	R.add_element(p);
	if (R.is_member(p)) cout << "add_element - Test 1 - Passed." << endl;
	else cout << "add_element - Test 1 - Failed!" << endl;

	p.first = 6;
	p.second = 15;
	S.add_element(p);
	if (S.is_member(p)) cout << "add_element - Test 2 - Passed." << endl;
	else cout << "add_element - Test 2 - Failed!" << endl;

	if (!T.is_member(p)) cout << "add_element - Test 3 - Passed." << endl;
	else cout << "add_element - Test 3 - Failed!" << endl;

	//Testing remove_element
	p.first = 50;
	p.second = 50;
	R.remove_element(p);
	if (!R.is_member(p)) cout << "remove_element - Test 1 - Passed." << endl;
	else cout << "remove_element - Test 1 - Failed!" << endl;

	S.remove_element(p);
	if (!S.is_member(p)) cout << "remove_element - Test 2 - Passed." << endl;
	else cout << "remove_element - Test 2 - Failed!" << endl;

	T.remove_element(p);
	if (!T.is_member(p)) cout << "remove_element - Test 3 - Passed." << endl;
	else cout << "remove_element - Test 3 - Failed!" << endl;

	
	//Testing reflexive
	p.first = 50;
	p.second = 50;
	R.add_element(p);
	if (R.reflexive()) cout << "reflexive - Test 1 - Passed." << endl;
	else cout << "reflexive - Test 1 - Failed!" << endl;

	if (!S.reflexive()) cout << "reflexive - Test 2 - Passed." << endl;
	else cout << "reflexive - Test 2 - Failed!" << endl;

	if (!T.reflexive()) cout << "reflexive - Test 3 - Passed." << endl;
	else cout << "reflexive - Test 3 - Failed!" << endl;

	//Testing Irreflexive
	if (!R.irreflexive()) cout << "irreflexive - Test 1 - Passed." << endl;
	else cout << "irreflexive - Test 1 - Failed!" << endl;

	if (!S.irreflexive()) cout << "irreflexive - Test 2 - Passed." << endl;
	else cout << "irreflexive - Test 2 - Failed!" << endl;

	if (T.irreflexive()) cout << "irreflexive - Test 3 - Passed." << endl;
	else cout << "irreflexive - Test 3 - Failed!" << endl;

	//Testing symmetric
	p.first = 5;
	p.second = 2;
	R.add_element(p);
	if (R.symmetric()) cout << "symmetric - Test 1 - Passed." << endl;
	else cout << "symmetric - Test 1 - Failed!" << endl;

	if (!S.symmetric()) cout << "symmetric - Test 2 - Passed." << endl;
	else cout << "symmetric - Test 2 - Failed!" << endl;

	if (T.symmetric()) cout << "symmetric - Test 3 - Passed." << endl;
	else cout << "symmetric - Test 3 - Failed!" << endl;

	
	//Testing asymmetric
	if (!R.asymmetric()) cout << "asymmetric - Test 1 - Passed." << endl;
	else cout << "asymmetric - Test 1 - Failed!" << endl;

	if (S.asymmetric()) cout << "asymmetric - Test 2 - Passed." << endl;
	else cout << "asymmetric - Test 2 - Failed!" << endl;

	p.first = 1;
	p.second = 2;
	T.add_element(p);
	p.first = 2;
	p.second = 1;
	T.add_element(p);
	if (!T.asymmetric()) cout << "asymmetric - Test 3 - Passed." << endl;
	else cout << "asymmetric - Test 3 - Failed!" << endl;

	//Testing transitive
	if (R.transitive()) cout << "transitive - Test 1 - Passed." << endl;
	else cout << "transitive - Test 1 - Failed!" << endl;

	p.first = 15;
	p.second = 10;
	S.add_element(p);
	if (!S.transitive()) cout << "transitive - Test 2 - Passed." << endl;
	else cout << "transitive - Test 2 - Failed!" << endl;

	p.first = 6;
	p.second = 10;
	S.add_element(p);
	if (S.transitive()) cout << "transitive - Test 3 - Passed." << endl;
	else cout << "transitive - Test 3 - Failed!" << endl;

	//Testing is_funciton
	if (!R.is_function()) cout << "is_function - Test 1 - Passed." << endl;
	else cout << "is_function - Test 1 - Failed!" << endl;

	if (T.is_function()) cout << "is_function - Test 2 - Passed." << endl;
	else cout << "is_function - Test 2 - Failed!" << endl;

	return 0;
}