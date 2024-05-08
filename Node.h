//Node.h 
//Cameron Young; c3330431
//last updated: 12/10/19
//this file holds the methods and declarations for the Node template. 
#ifndef NODE_H //creating a macro guard
#define NODE_H

using namespace std;
#include <iostream>
template <class N> //creates a template for the Node class
class Node
{	
	//public member variables
	public:
		//precondition: the default constructor for the node class is called
		//postcondition: a new instance of a node is created with all the variables being assigned their default values correctly
		Node() 
		{
			this->disc = ""; //sets the default value for the tower's discs to be an empty string instead of null (which would create errors)
			next = NULL;
			prev = NULL;
		}
		//pre-condition: the destructor is called
		//post-condition: the data in the node is deleted, along with any references to it 
		~Node()
		{
		}

		//pre-condition: a LinkedList passes in data for a node (ie, not the default constructor)
		//post-condition: a new node is created that stores the data given
		Node(const N& d)
		{
			disc = d;
			next = NULL;
			prev = NULL;
		}

		//pre-condition: the node tries to return the disc stored in the node
		//post-condition: the disc this node stores is returned
		const N getDiscs() const
		{
			return this->disc;
		}

		//pre-condition: the program looks for the pointer to the next node in the LinkedList
		//post-condition: the program returns the pointer
		Node<N>* getNext() const
		{
			return next;
		}

		//pre-condition: the program tries to set the pointer for the next node
		//post-condition: the program sets the pointer for the next node
		void setNext(Node<N>* node)
		{
			this->next = node;
		}

		//pre-condition: the program tries to set the pointer for the previous node
		//post-condition: the program sets the pointer for the previous node
		void setPrev(Node<N>* node)
		{
			this->prev = node;
		}
 		
 		//pre-condition: the program looks for the pointer to the prev node in the LinkedList
		//post-condition: the program returns the pointer
 		Node<N>* getPrev() const
		{
			return this->prev;
		}
	//private member variables.
	private:
		N disc;
		Node<N>* next;
		Node<N>* prev; 
};
#endif