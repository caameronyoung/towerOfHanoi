//LinkedList.h
//Cameron Young; c3330431
//last updated: 12/10/19
//this file holds the methods and declarations for the LinkedList template. 
#ifndef LINKEDLIST_H //creating macroguard
#define LINKEDLIST_H
#include "Node.h" //including relevant files so I can access desired methods within this header file 

template <class L> //creates a template for the LInkedList class
class LinkedList
{
	public: //public member variables
		//precondition: the constructor for a LinkedList() is called 
		//postcondition: the variables and/or pointers are assigned their correct default values
		LinkedList()
		{
			this->head = NULL;
			this->tail = NULL;
			this->current = head;
			this->length = 0;
		}
		//precondition: the destructor is called
		//postcondition: the linkedlist and its reference pointers are deleted 
		~LinkedList()  
		{
			while (head != NULL) //ie; while there is still something in the LinkedList
			{
				removeFromHead();
			}
		}

		//precondition: the program calls for getCurrent() of an unknown data type
		//poscondition: the program returns the discs pointed to by the current node 
		const L getCurrent() const
		{
			return this->current->getDiscs();
		}
		//precondition: the program tries to add a node to the head of the linked list 
		//postcondition: the program succesffully adds the inputted node to the head of the linked list 
		void addToHead(const L& s) //const L& so that the input parameter is added as a reference instead of creating an extra variable on the stack
		{
			if (head == NULL) //ie; if there is nothing added to the list yet
			{
				Node<L>* node = new Node<L>(s);
				head=node;
				tail = node;//0 nodes so the tail and head are equivalent.
				length++;
			}

			else //much harder to move pointers around if the head already points to a non-null value 
			{
				Node<L>* node = new Node<L>(s); //creates a new node to become the head
				head->setPrev(node); // sets the initial head's previous pointer to be that of the new node (as it is becoming the 2nd one in the list )
				node->setNext(head); //sets the new node's next pointer to be the initial head (now the 2nd node in the list)
				head=node; //sets the head pointer to point to the new node
				length++;
			}

		}

		//precondition: the program tries to get the head node of the current linked list
		//postcondition: the discs in the head node of the linked list are returned without them changing in the process (ie; const)
		const L getHead() const 
		{
			return this->head->getDiscs();
		}

		//precondition: the program tries to remove the head node from the linked list 
		//postcondition: the head node is removed form the linked list with any memory allocated to it also being deleted 
		const L removeFromHead()
		{
			Node<L>* temp = head; //stores the current head data and all its pointers
			head = head->getNext(); //the current head node just become the next node, because, if the head gets removed, the next one becomes the head 
			if (head != NULL) //assumes the new head node still has data in it, meaning there will be a previous pointer that points outside the list 
			{ 
				head->setPrev(NULL); //sets the head's previous pointer to be non-existant.
			}
			this->length--;
			
			L data = temp->getDiscs(); //stores the discs of the original head node, so they can be used with the push/pop functions. 
			delete temp;
			return data;
			//delete temp; //removes the data stored in temp, which was head's data
		}

		//precondition: the program tries to get the length of the linked list
		//postcondition: the length of the linked list is returned. 
		int getLength() const
		{
			return this->length;
		}

		//precondition: the program tries to access the discs that come after the current node. 
		//postcondition: the program returns the unknown data type that stores the next node 
		const L next()
		{
			L data = current->getDiscs(); //creates a new variable of an unknown type that stores the discs of the current node
			current = current->getNext(); //points the current node to be the next node in the list.
			return data; //the discs are returned. 
		}

		//precondition: the program tries to reset the current node in the stack
		//precondition: the program reassigns where the current node is so that the tower prints in the correct order. 
		void resetCurrent() 
		{
			current = head;
		}

	private: //private member variables 
		Node<L>* head;
		Node<L>* tail; 
		Node<L>* current; 
		int length;
};
#endif
