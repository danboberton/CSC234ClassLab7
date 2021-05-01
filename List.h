#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

// Specification file array-based list (�List.h�)

const  int  MAX_LENGTH = 50; 
class  List {
public: 	          // Public member functions

    typedef int ItemType; // Needs to be int for Node linking
    List();           // constructor
    bool IsEmpty() const;
    bool IsFull()  const;
    int  Length()  const; // Returns length of list 
    void Insert(ItemType  item);
    bool Delete(ItemType  item); // Changed to bool
    bool IsPresent(ItemType  item)  const;
    void SelSort();
    void Reset();
    void clear();
    ItemType GetNextItem();

    friend ostream& operator << (ostream&, const List&);

protected:	      // Private data members
    int length; // Number of values currently stored
    Node* root;
    Node* currentPos;  // Used in iteration       
};