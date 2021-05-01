#include <iostream>
#include "List.h"
#include <stdlib.h>
// #include "SortedList.h"

using namespace std;

// TODO make sure selsort works
// This test is ok to use
// Convert the class List provided in LinkedList.zip
// to use a linked list instead of the fixed length array.
// The private instance variable data[] should be modified
// to Node* head_ptr; and the last Node object in the list
// should have a null link_field forward pointer.

int main(int argc, char* argv[]) {
	List tempList;


	for(int i = 0; i < 10; i++)
		tempList.Insert(rand() % 100);

	tempList.Reset();
	cout << tempList;

	cout <<endl;

	tempList.SelSort();

	tempList.Reset();
	for (int i = 0; i < 10; i++)
		cout << tempList.GetNextItem() << " ";
	cout << endl;
}