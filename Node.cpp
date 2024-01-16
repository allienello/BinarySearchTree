/***********************************
 * Node.cpp
 * Written by Allie Ianello
 ***********************************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include "Node.h"

/**************************************
 * Constructor
 **************************************/
node::node(string arg)
{
	value = arg;
	left = right = NULL;
}

/**************************************
 * Deconstructor
 **************************************/
node::~node()
{
	if (left != NULL) delete left;
	if (right != NULL) delete right;
}

/**************************************
 * put()
 **************************************/
void node::put(ostream& out)
{
	cout << value << endl;
}

/**************************************
 * lmr()
 **************************************/
void node::lmr(ostream& out)
{
	if (left != NULL) left->lmr(out);
	put(out);
	if (right != NULL) right->lmr(out);
}

/**************************************
 * mlr()
 **************************************/
void node::mlr(ostream& out)
{
	put(out);
	if (left != NULL) left->mlr(out);
	if (right != NULL) right->mlr(out);
}

/**************************************
 * rml()
 **************************************/
void node::rml(ostream& out)
{
	if (right != NULL) right->rml(out);
	put(out);
	if (left != NULL) left->rml(out);
}

/**************************************
 * count()
 **************************************/
int node::count()
{
	int num = 1;
	if (left != NULL) num += left->count();
	if (right != NULL) num += right->count();
	return num;
}

/**************************************
 * depth()
 **************************************/
int node::depth()
{
	int l, r;
	l = r = 0;
	if (left != NULL) l = left->depth();
	if (right != NULL) r = right->depth();
	return max(l, r) + 1;
}


