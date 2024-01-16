/***********************************
 * Program 05
 * Updated by Allie Ianello
 ***********************************/ 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Tree.h"

/***********************************
 * Main
 * Test function 
 ***********************************/ 
void main()
{ tree t;
  string fname,s,order;
  fstream infile;

// Get file name

  cout << "Enter file name: ";
  cin >> fname;
  cout << endl;
//fname = "People.txt";

// Open file

  infile.open(fname,ios::in);

// Loop through file

  while(!infile.eof())
    { infile >> s;
    
// Process if okay

      if(infile.good())
        t.insert(s);
    };

// Close

  infile.close();

// Input display order

  cout << "Order to display (LMR,MLR,RML): ";
  cin >> order;

// Display 

  cout << endl << order << " Order\n--------------\n";
  t.show(order,cout);
  cout << endl;

// Display count

  cout << "Count: " << t.count() << endl;

// Display depth

  cout << "Depth: " << t.depth() << endl;

// Find node

  cout << endl;
  cout << "Enter value to find: ";
  cin >> s;

  cout << endl << "Find: ";
  if(t.find(s))
    { 
      cout << s << " found!" << endl;

      // If found, remove node

      t.remove(s);
      cout << endl << "Remove: ";
      cout << s << " removed" << endl;

      // Display 
       cout << endl << order << " Order\n--------------\n" << endl;
       t.show(order, cout);
       cout << endl;

      // Display new count and depth

      cout << "Count: " << t.count() << endl;
      cout << "Depth: " << t.depth() << endl;

    }
  else
    cout << s << " not found" << endl;

}
