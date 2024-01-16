/***********************************
 * Tree.h
 * Written by Allie Ianello
 ***********************************/

#include "Node.h"

class tree
{
public:
    tree();                       // Constructor
    ~tree();                        // Deconstructor
    bool insert(string arg);          // Insert string into tree
    void show(string arg, ostream&out);            // Display in order
    bool find(string arg);             // Find in tree
    bool remove(string arg);
    int count();
    int depth();
private:         
    void insert(node* p);
    node* root;
};