//TowerHanoi.h
//Cameron Young; c3330431
//last updated: 12/10/19
//this file holds the class declarations for the TowerHanoi class. 
#ifndef TOWERHANOI_H //creating a macroguard
#define TOWERHANOI_H
#include <iostream>
#include "LStack.h"
using namespace std;

class TowerHanoi
{
	//public member variables
	public:
		//precondition: the default constructor is called
		//postcondition: the default constructor assigns the new instance of TowerHanoi with all the correct default values 
		TowerHanoi(int discs); //default constructor

		//precondition: the destructor is called
		//postcondition: the TowerHanoi and any references to it are deleted from memory
		~TowerHanoi(); //destructor method

		//precondition: the user wants to check if the game is complete
		//postcondition: the program checks if the winning conditions have been met, and is returned true/false respectively 
		bool checkWin(); //method to check if the game is completed or not

		//precondition: the program tries to create the initial sets of disc for the first tower
		//postcondtion: the program creates the initial discs and stores them in the corresponding nodes.
		string makeDiscs(int row); //creates the disc for each disc on the tower

		//precondition: the program tries to print the intial instance of the game
		//postcondition: creates the tower as a string for each time the << operator is called 
		string toPrint(); //prints the instance of the game each time

		//precondition; the program tries to move a disc to another rod
		//postcondition: the program moves the disc to another rod via pushing and poppings
		void move(int from, int to); //moves the top discs around the 3 rods
	//private member variables
	private:
		int length;
		LStack<string> towersArray[3];
};

std::ostream& operator <<(ostream& out, TowerHanoi& tower); //an overloaded << operator for printing the instance of the game each time. 
#endif