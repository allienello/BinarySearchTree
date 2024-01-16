/***********************************
 * Node.h
 * Written by Allie Ianello
 ***********************************/

class tree;

class node
{
	friend class tree;
public:
	node(string arg = "");
	~node();
	void put(ostream& out);
	void lmr(ostream& out);
	void mlr(ostream& out);
	void rml(ostream& out);
	int count();
	int depth();
private:
	string value;
	node* left, * right;
};