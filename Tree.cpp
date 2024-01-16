/***********************************
 * Tree.cpp
 * Written by Allie Ianello
 ***********************************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include "Tree.h"

/**************************************
 * Constructor
 **************************************/
tree::tree()
{
	root = NULL;
}

/**************************************
 * Deconstructor
 **************************************/
tree::~tree()
{
	if (root != NULL) delete root;
}

/**************************************
 * insert()
 **************************************/
bool tree::insert(string arg)
{
	node* p;

	p = new node(arg);
	if (p == NULL) return false;

	insert(p);
	return true;
}

/**************************************
 * show()
 **************************************/
void tree::show(string arg, ostream&out)
{
	if (root != NULL)
	{
		if (arg == "LMR") root->lmr(out);
		if (arg == "MLR") root->mlr(out);
		if (arg == "RML") root->rml(out);
	}
}

/**************************************
 * find()
 **************************************/
bool tree::find(string arg)
{
	node *q;

	if (root == NULL) return false;

	q = root;

	while (q != NULL)
	{
		if (q->value == arg) return true;

		if (arg <= q->value)
		{
			q = q->left;
		}
		else
		{
			q = q->right;
		}		
	};

	return false;
}

/**************************************
 * insert() node*
 **************************************/
void tree::insert(node* p)
{
	node* q;
	if (root == NULL)
	{
		root = p;
		return;
	}
	q = root;
	while (q != p)
	{
		if (p->value <= q->value)
		{
			if (q->left == NULL)
				q->left = p;
			q = q->left;
		}
		else
		{
			if (q->right == NULL)
				q->right = p;
			q = q->right;
		}
	}
}

/**************************************
 * remove()
 **************************************/
bool tree::remove(string arg)
{
	if (root == NULL) return false;

	node *p = root;
	node* q;
	node* save_left;
	node* save_right;
	
	while (p != NULL && arg != p->value)
	{
		q = p;
		if (arg < p->value)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	};

	if (p == NULL) return false;

	if (p == root)
	{
		root = NULL;
	}
	else if (p == q->left)
	{
		q->left = NULL;
	}
	else
	{
		q->right = NULL;
	}

	save_left = p->left;
	save_right = p->right;

	if (save_left != NULL)
	{
		insert(save_left);
	} 

	if (save_right != NULL)
	{
		insert(save_right);
	}

	p->left = NULL;
	p->right = NULL;

	delete(p);

}

/**************************************
 * count()
 **************************************/
int tree::count()
{
	if (root != NULL)
		return root->count();
	else
		return 0;
}

/**************************************
 * depth()
 **************************************/
int tree::depth()
{
	if (root != NULL)
		return root->depth() - 1;
	else
		return -1;
}