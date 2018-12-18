/* 
 * File:   LinkedList.cpp
 * Author: Alexandros Anastasiou
 *
 * Last modified 02/04/2017
 * Implements the LinkedList class.
 */

#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
#include "linked_list.h"
using namespace std;

//creates an empty list
LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

//creates a list with an initial value to store
LinkedList::LinkedList(int value)
{	
	// make a new node - which gets the initial value 
	Node *newnode = new Node();
	newnode->data = value;
	// make newnode head and tail
	head = newnode;
	tail = newnode;
}

//copy constructor (performs a deep copy)
LinkedList::LinkedList(const LinkedList& rhs)
{	
	/*Node *copy = new Node;
	Copy = new Node(*head);*/
}

//destroys (cleans up) the list
LinkedList::~LinkedList()
{
	// while head != null(list not empty)  head point to the next(null)
	while (head != nullptr)
	{	
		//tail=head point to the next(null)
		tail = head;
		head = head->next;
		delete tail;
	}
	head = nullptr;
}

//adds a value to the head of the list
void LinkedList::push(int value)
{	
	// new temp Node that hold the value 
	Node *temp = new Node();
	temp->data = value;
	
	// check that list is empty and make temp Node to head
	if (head == nullptr)
	{
		head = temp;
	}
	else
	{
		// make current_head the head in case the list has more than one elements
		Node *current_head = head;
		//update temp to head
		head = temp;
		//head next now points to current head (which was the head before)
		head->next = current_head;
	}
	
}

//gets the last element from the list, without removing it
//requires: list not empty
int LinkedList::peekTail()
{	
	// make sure that the list is not empty by asserting head different to nullptr
	assert(head != nullptr);
	// return tail 
	return tail->data;
}

//prints the list in order from head to tail
string LinkedList::toString() const
{
	// empty string 
	string list_content = "";
	
	Node *first = this->head;
	// while first is not empty
	while (first != nullptr)
	{	// string list_content cast data to string 
		list_content += to_string(first->data);
		//assign next to first node 
		first = first->next;
		// if first is not empty - add a space
		if (first != nullptr)
		{
			list_content += " ";
		}
	}
    return list_content;
}

//removes and returns the value at the head of the list
//requires: list not empty
int LinkedList::pop()
{	
	// make sure that the list is not empty by asserting head different to nullptr
	assert(head != nullptr);
	// assign result int to head 
	int result = head -> data;
	
	Node *temp = head;
	head = head->next;
	
	delete temp; 	
    return result;
}

//adds a value to the end of the list
void LinkedList::append(int value)
{
	Node *newnode = new Node();
	// value is assigned to newnode and next points to null
	newnode->data = value;
	newnode->next = nullptr;
	// if head && tail are null
	if (head == nullptr && tail==nullptr)
	{	
		// head becomes newnode and at the same time tail
		head = newnode;
		tail = newnode;
	}
	else
	{	
		// if head is not null - tail points to newnode and newnode becomes tail
		tail->next = newnode;
		tail = newnode;
	}
}

//appends the deep copies of the nodes of rhs on to the end of this list
void LinkedList::appendList(const LinkedList& rhs)
{
/*	Node *newnode;
	Node *tmp;
	Node *temp2 = rhs.head->data;
	
	while (tmp != nullptr)
	{
		if (newnode->next = nullptr)
			newnode=tmp2
	}*/
}

//inserts a value immediately after the first occurrence of afterValue,
//if afterValue is not in the list then inserts at the tail
void LinkedList::insertAfter(int value, int afterValue)
{	
    Node *previous = new Node;
	Node *current = new Node;
	Node *newnode = new Node;
	
	newnode->data = value;
	// traverse 
	int tempPosition = 0; 
	// current assigned as head
	current = head;
	// check if list is empty
	if (head != nullptr)
	{	
		// while current is not pointing to null and list position is not equal to the aftervalue
		while (current->next != nullptr && tempPosition != afterValue)
		{	
			// previous is assigned to current
			previous = current;
			current = current->next;
			tempPosition++;
		}
	}
	if (afterValue == 2)
	{
		//cout << "ADDING TO HEAD" << endl;
		append(value);
	}
	// if current is pointing to null (tail) and aftervalue is equal to listposition +1
	else if(current->next == nullptr && afterValue == tempPosition + 1)
	{
		//cout << "ADDING TO END" << endl;
		append(value);
	}
	// if aftervalue is in greater list position 
	else if (afterValue > tempPosition + 1)
	{
		append(value);
	}
	else
	{		
		// previous points to newnode then it becomes current
		previous->next = newnode;
		newnode ->next = current;
		//cout <<"ADDED AT POS :" << afterValue << endl;
	}
}

//removes all occurrences of value from the list
void LinkedList::removeAllOccurences(int value)
{
    Node *temp;
	Node *previous = nullptr;
	Node *next;
	
	// as long temp is head and its not empty
	for (temp = head; temp != nullptr; temp = next)
	{	
		
		next = temp->next;
		// if temp is not equal to value
		if (temp->data != value)
		{
			//set temp to previous
			previous = temp;
			continue;
		}
		// if previous is not empty 
		if (previous != nullptr)
		{
			// assign next to previous
			previous->next = next;
		}
		else
		{
			head = next;
		}
		delete temp;
	}
}

//reverses the list
void LinkedList::reverse()
{	
	Node *previous = nullptr;
	Node *current = head;
	Node *next = nullptr;
	
	// check if list is empty
	while(current != nullptr)
	{
		// update next to previous
		current->next = previous;
		previous = current;
		current = next;
	}
}

//checks if two lists are equal in state (contain the same values in the same order)
bool LinkedList::operator ==(const LinkedList& other) const
{
	return false;
}

//checks if two lists are not equal in state
bool LinkedList::operator !=(const LinkedList& other) const
{
    return false;
}

//pushes a new value onto the head of the list
LinkedList& LinkedList::operator +(int value)
{   
	this->push(value);
	return *this;
}

//copy assignment operator (performs a deep copy)
LinkedList& LinkedList::operator =(const LinkedList& rhs)
{   
	return *this;
}

//pushes values from an input stream onto the front of the list
std::istream& operator>>(std::istream &in, LinkedList &value)
{
	return in;
}

//writes the values, in order, to an output stream
std::ostream& operator<<(std::ostream &out, const LinkedList &value)
{	
	/*LinkedList::Node* p;
	for(p = value.head; p != 0; p->next)
	{
		out << p->data << endl;
	}*/
    return out;
}