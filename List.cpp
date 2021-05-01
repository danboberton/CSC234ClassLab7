// Implementation file array-based list 
// (�List.cpp�)

#include  <iostream>
#include  "List.h"

using namespace std;

int  List::Length()  const
// Post: Return value is length
{
	return  length;
}

bool  List::IsFull()  const
// Post: Return value is true 
//       if length is equal
//  to MAX_LENGTH and false otherwise
{
	return (length == MAX_LENGTH);
}

// *db* modified
List::List()
// Constructor
// Post: length == 0
{
	length = 0;
	currentPos = 0;
	root = NULL;
}

// *db* Modified for linked List
void  List::Insert(ItemType  item)
{
	// Check if linked list is empty
	if (root == NULL){

		// Create root node
		root = new Node(item, NULL);
	} else {

		// add new node at end of list,
		// similar to LinkedList implementation
		{
			Node* curNode = root;
		
			// Find last item in list
			while (curNode->link() != NULL){
				curNode = curNode->link();
			}

			Node* newNode = new Node(item, NULL);
			curNode->set_link(newNode);
		
		}

	}

	length++;
}

// *db* updated
bool  List::IsEmpty()  const
// Post: Return value is true if length is equal
//  to zero and false otherwise
{
	return (root == NULL) ? true : false;
}

// *db* updated
bool List::IsPresent( /* in */ ItemType item) const
// Searches the list for item, reporting 
//   whether found
{
	Node* curNode = root;
	ItemType curItem;

	while (curNode != NULL){

		if (curNode->data() == item){

			return true;
		} else {

			curNode++;
		}
	}

	return false;
}


// *db* modified
bool  List::Delete( /* in */  ItemType  item)
{
	Node* curNode = root;
	Node* prevNode = NULL;

	// Cycle through list
	while (curNode != NULL){

		// Found item?
		if (curNode->data() == item) {

			// Found, in Only Node?
			if (length == 1){

				delete curNode;
				root = NULL;
				length--;
				return true;

			// Found, First item?
			} else if (prevNode == NULL) {

				root = curNode->link();
				delete curNode;
				length--;
				return true;

			// Found, not only or first
			} else {

				// Fill in gap
				prevNode->set_link(curNode->link());

				delete curNode;
				length--;
				return true;

			}

		} else {

			prevNode = curNode;
			curNode = curNode->link();
		} // end Found Item?

	return false;

	}
}

// *db* modified
void List::clear()
{
	Node* curNode = root;
	Node* nextNode;

	// Delete all objects;
	while (curNode != NULL){

		nextNode = curNode->link();
		delete curNode;

		curNode = nextNode;

	}

	length = 0;
}

void List::Reset(){

	currentPos = root;

}

// *db* modified
List::ItemType List::GetNextItem()
{
	ItemType item;

	// Get the current item
	item = currentPos->data();

	// Setup for next
	currentPos = currentPos->link();

	return item;
}

// TODO selSort
void  List::SelSort()
// Sorts list into ascending order 
{
	int passes = 0;
	Node* curNode = root;
	Node* curMin;
	Node* curMinPrev;
	Node* prevNode;

	// Sort n times
	// n = array length
	// Or sort until list is found to be sorted
	while (passes < (length - 1)){

		curNode = root;

		// Start pass at Node (n + passes)
		for(int n = 0; n < passes; n++){

			prevNode = curNode;
			curNode = curNode->link();

		}

		// Find minimum in current subset
		// First value set is default min
		curMin = curNode;
		curMinPrev = prevNode;
		prevNode = curNode;
		curNode = curNode->link();

		while (curNode != NULL){

			// If current node data < currentMin set new curMin
			if (curNode->data() <= curMin->data()){
				curMinPrev = prevNode;
				curMin = curNode;
			}
			
			prevNode = curNode;
			curNode = curNode->link();

		}

		// Fill in gap from lifted Node
		curMinPrev->set_link(curMin->link());

		// Move curMin to next minimum
		curNode = root;
		prevNode = NULL;

		// Find slot to put curMin
		for (int i = 0; i < passes; i++){
			prevNode = curNode;
			curNode = curNode->link();
		}

		// If first slot, reset root
		if (curNode == root){
			curMin->set_link(root);
			root = curMin;
		} else {
		// insert node in between exsisting nodes
			prevNode->set_link(curMin);
			curMin->set_link(curNode);
		}
		
		passes++;
	}
}

ostream& operator << (ostream& os, const List& l) {
	// Post: If the list is not empty, the elements are
	//       printed on the screen in increasing order;
	//       otherwise "The list is empty" is
	//       printed on the screen.
	int index = 0;
	List sl = l;
	sl.Reset();
	while (index < sl.length) {
		os << sl.GetNextItem() << " ";
		index++;
	}
	os << endl;
	return os;
}
