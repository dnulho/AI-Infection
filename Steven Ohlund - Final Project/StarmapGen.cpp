/************************************
* Author: Steven Ohlund
* File Name: StarmapGen.cpp
* Date Created: 11.2.15
* Modifications:
************************************/
#include "MapObjects.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;


void CreateNewObject(unsigned int newOb, cRouter * connectedTo)
{
	// random selection of possible objects to create
	//	* Empty - ID will always be 0
	//	* Router								// Do I want to have a large value deliniate between objects?
	//	* Computer
	//	* Phone
	// Create instance of selected object
	// set first pointer to *connectedTo
	// write object to file
}

void LoadObjectFromFile(unsigned int ID)
{
	// Find ID in file
	// Read ID info to memory
	// find pointers to all loaded connected objects
	// assign pointers of loaded objects
}

void SaveObjectToFile(int*ID)
{
	// find correct place in file to insert object
	// make new line to place object
	// write object to file
	// close file
}

void FillPointer()
{
	// determine type of object pointed to
	//	* If 1: uninitialized, call CreateNewObject()
	//	* If 0: empty, leave empty
	//	* If anything else: call LoadObjectFromFile() 
}

int main()
{
/*
	int choice;
	bool done = false;
	while (!done)
	{
		system("cls");
		cout << "---Main Menu---\n"
			<< "1) Start New Map\n"
			<< "2) Open Existing Map\n"
			<< "0) Exit\n";
		cin >> choice;
		switch (choice)
		{
		case 0:
			done = true;
			break;
		case 1:
			CreateNewObject(2,null); // (CreateFirstObject()??)

			break;
		case 2:
			LoadObjectFromFile();
			break;
		default:
			cout << "Error: Invalid selection.";
			system("pause");
		}
	}
	cout << "Goodbye";
	system("pause");
*/
}