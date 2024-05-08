//Cameron Young; c3330431
//last updated: 12/10/19
//this file holds the class methods for the TowerHanoi class. 
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "TowerHanoi.h"
using namespace std;

TowerHanoi::TowerHanoi(int discs) //the default constructor for the TowerHanoi class 
{
	this->length = discs;
	for (int i = discs; i>0; i--) //loops through from the bottom layer of discs to the first layer of discs and pushes the correct disc onto the stack
	{
		towersArray[0].push(makeDiscs(i)); //only executs on towersArray[0] because that is what has the discs initially 
	}
}

TowerHanoi::~TowerHanoi() // the destructor method for the Tower Hanoi Class
{
}


string TowerHanoi::makeDiscs(int row) //the method to create the discs initally for use in the default constructor
{
	string space = ""; //initially the row starts with a blank string
	int spaces = this->length - row; //determines the amount of whitespace on either side of the discs
	for (int i = 0; i < spaces; i++) //adds whitespace to the left hand side of the empty string
	{
		space += " ";
	} 
	//the amount of x's required to make the centered pattern is 2*row - 1. 
	//hence, the loop runs the amount of times to add enough x's to the string
	for (int i = 0; i < ((2*row) - 1); i++) 
	{
		space += "x";
	}
	//the same method to add white space to the left of the discs is applied here to add them to the right of the discs also 
	for (int i = 0; i < spaces; i++)
	{
		space += " ";
	}
	return space; //the built disc is returned 
}

string TowerHanoi::toPrint() //creates the tower that is printed each time the << operator is called
{
    string s = ""; //the tower is initally built with an empty string to start

    LStack<string> tempTowersArray[3]; //creates an array of empty stacks
    for (int i = 0; i < 3; i++)
    {
        while (!towersArray[i].isEmpty()) //while the rod has discs on it
        {
            tempTowersArray[i].push(towersArray[i].pop()); 
        }
    }


    for (int i = 0; i < this->length; i++) //loops through this process the amount of times based off how many discs there are at the start.
    {
        string line = "  ";//the 2 space margin is added initially
       
        for (int j = 0; j < 3; j++) //loops through three times for three temp stacks
        {
            if (tempTowersArray[j].isEmpty())  //if the temp stack has no items on the rod 
            {
                for (int k = 0; k < 2 * this->length - 1; k++) //this is done so many times as equal to the length of the disc that is being worked with 
                {
                    line += " ";
                }
            }
            else
            {
                string temp = tempTowersArray[j].pop(); //else, removes a disc from the top of the temp stack
                line += temp; //concatenates the line with what was removed in the line above 
                towersArray[j].push(temp); //adds what was just removed to the array of rods.
            }
            
            line += " ";
        }      
        line += "\n";
        s = line + s;
    }
    //this is the length of the board with the max number of discs whilst also accounting for whitespace on each side of the bottom discs
    for (int i = 0; i < 6 * this->length + 3; i++) //prints the dashes underneath the tower to give the illusion of a board
    {
        s += "-";
    }
 
    s += "\n";
 
    for (int i = 0; i < 6 * this->length + 3; i++) //loops across the bottom of the board to find where the numbering of the towers gets placed
    {
        if (i == this->length + 1) //if the loop is currently in the center of the first tower, a 1 is placed
            s += "1";
        else if (i == 3 * this->length + 1) //if the loop is in the center of the second tower, a 2 is placed.
            s += "2";
        else if (i == 5 * this->length + 1) //if the loop is in the center of the third tower, a 3rd is placed.
            s += "3";
        else
            s += " ";                       //if none of those are the case, the program adds another space instead of a number
    }
 
 
    s += "\n";
 
    return s;
}

std::ostream& operator <<(ostream& out, TowerHanoi& tower) //an overloaded << operator for printing the instance of the game each time. 
{
	string print = ""; //starts out with an empty string which is then concatenated to hold the rest of the towers 
	print += tower.toPrint(); //adds the content of toPrint() to the string that will be sent to the output stream 
	out << print << endl; //prints the contents of print to the screen
	return out; //returns the content that was output. 
}

void TowerHanoi::move(int from, int to) //the function to move the discs to differing rods
{
	from--; //decremented to count from 0
	to--;   //decremented to count from 0

	if (towersArray[from].isEmpty()) //condition to check if the rod is empty
	{
		cout << "cannot move from a rod that is empty" << endl;
		return;
	}

	if (from < 0 || from > 2 || to < 0 || to > 2) //error trapping to see if an input for a tower not between 1&3 is called
	{
		cout << "number not between 1 and 3" << endl;
		return;
	}

	else if (towersArray[to].isEmpty()) //if the rod to put the disc on to is empty
	{
		towersArray[to].push(towersArray[from].pop());
		return;
	}
	//creating these two variables makes the if statement below a lot less messy 
	string fromStr = towersArray[from].peek();
	string toStr = towersArray[to].peek();

	//if the rod you try to put the disc on to has a shorter disc on top this if statement catches it
	if (count(fromStr.begin(), fromStr.end(), 'x') < count(toStr.begin(), toStr.end(), 'x'))
	{
		towersArray[to].push(towersArray[from].pop());
	}
	else
	{
		cout << "invalid move" << endl;
	}
}

bool TowerHanoi::checkWin() //checks if the game has been completed
{
	return towersArray[0].isEmpty() && towersArray[1].isEmpty();
}

