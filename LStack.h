//Lstack.h
//Cameron Young; c3330431
//last updated: 12/10/19
//this file holds the methods and declarations for the LStack template. 
#ifndef LSTACK_H //creating a macroguard
#define LSTACK_H
#include "LinkedList.h"
#include <iostream> 
#include <algorithm> //a standard library so i can use the count() function to look for lengths of discs. 
using namespace std;

template <class S> //creates a template for the LStack class. 
class LStack
{
	public: //public member variables
		//precondition: the default constructor is called
		//postcondition: the program successfully creates a new instance of the LStack class which successfully assigns all the variables their default values 
		LStack()
		{
			 list = new LinkedList<S>();
			 length = 0;
		}

		//precondtion: the destructor for the LStack is called
		//postcondition: the linkedlist inside the stack is successfully removed. 
		~LStack()
		{
			delete this->list;
		}
		//postcondition: the program tries to push a new item to the top of the stack
		//precondition: the program adds a new item to the top of the stack
		void push(const S& item) 
		{
			this->list->addToHead(item);
			this->length++;
		}
		//precondition: the program looks for the next item in the list inside the stack
		//postcondition: the program returns the next item in the stack
		const S next()
		{
			return list->next();
		}
		//precondition: the program tries to remove an item from the top of the stack
		//postcondition: the program successfully removes the top item in the stack, returns what is removed, and decreases the length of the stack by one. 
		const S pop() //remove from top of stack, and return what is removed 
		{
			this->length--;
			return this->list->removeFromHead();
		}
		//precondition: the program tries to find the top (first) item in the stack
		//postcondition: the program returns the head of the LinkedList in the ctack, which is effectively the first item in the stack. 
		//const is used here so that the first item in the stack cannot be altered in any way by the use of the function. 
		const S peek() const //return the object at the top of the stack; return NULL if the stack is empty 
		{
			return this->list->getHead();
		}
		
		//precondition: the program tries to find the length of the stack (ie; amount of items in the stack)
		//postcondition: the program returns the amount of items in the stack
		int getLength() const 
		{
			return this->length;
		}

		//precondition: the program tries to reset where the current node is inside the LinkedList
		//postcondition: the program points to the same method inside the LinkedList class so that it can be adjusted without violating encapsulation
		void resetCurrent()
		{
			list->resetCurrent();
		}

		//precondition: the program wants to see if the stack contains any elements
		//postCondition: returns true or false depending on the value of length in the list
		bool isEmpty()
		{
			if (this->length == 0)
			{
				return true;
			}
			else
			{
				return false; 
			}
		}

	//private member variables
	private:
		LinkedList<S>* list;
		int length; 

};
#endif