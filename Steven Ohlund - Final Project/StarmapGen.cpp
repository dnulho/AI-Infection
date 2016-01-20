/************************************
* Author: Steven Ohlund
* File Name: StarmapGen.cpp
* Date Created: 11.2.15
* Modifications: To numerous to count, see github commit history to see changes.
************************************/
#include "MapObjects.h"


// Standard object call

commonResources* LoadObjectFromFile(unsigned int id, fstream & ifile)
{
		// Find ID in file using binary search
		// Read ID info to memory
		// Return pointer to caller
		return nullptr;
}

void SaveObjectToFile(commonResources* object, ofstream & file)
{
		// find number of lines in file
		if (false)
		{ }
		// find correct place in file to insert object
		// make new line to place object
		// write object to file
		// close file
}

int DisplayObjectMenu(commonResources* object)
{
	int choice;
	cout << "0) Exit\n"
		<< "1) Show Detailed Stats\n"
		<< "2) Move to Connected object\n";
	cin >> choice;
	choice -= 2;
					// show menu with options to * display detailed stats
					//							 * move to connected objects (another function)
					//							 * return to main menu
	return choice;
}

unsigned int findSavedID(fstream & file)
{
	unsigned int savedID;
	file >> savedID;
	return savedID;
}


/***************************************************************************
* Assignment: CST116 - Final Project
*
* Overview: This Program is intended to generate a virtual map of objects
*			based on a set of procedural rules that govern said generation.
*			This map generation software is a small piece of a larger program
*			idea that is intended to turn into a game.
*
* Input: * Menu Selections from keyboard
*		 * Object stats From Save File
*
* Output: * Menu Options to Console
*		  * Object Stats to Console - Human readable
*		  * Object Stats to Save File - not very human readable
*
***************************************************************************/
int main()
{
	commonResources *crtObj = nullptr;
	srand(static_cast<unsigned int>(time(NULL)));
	char choice;
	bool done = false;
	char filename[] = "test.txt";
	fstream file(filename);
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
		case '0':
			done = true;
			break;
		case '2':
			
			if (file.fail())
			{
				cout << "Error: could not open save file";
			}
			else
			{
				crtObj = LoadObjectFromFile(findSavedID(file), file);
			}
		case '1':
			crtObj = new cComputer();
			while (!done)
			{
				switch (DisplayObjectMenu(crtObj))
				{
				case -2:
					done = true;
					break;
				case -1:
					crtObj->DisplayStats();
					break;
				case 0:// move to first object
				case 1: // only valid if crtObj points to a router
				case 2: // only valid if crtObj points to a router
				case 3: // only valid if crtObj points to a router
				case 4: // only valid if crtObj points to a router
				case 5: // only valid if crtObj points to a router
				case 6: // only valid if crtObj points to a router
				case 7: // only valid if crtObj points to a router
				default: // Something Broke
					cout << "Error: main()- case 2 - default";
					break;
				}
			}
			done = false;
			break;
		default:
			cout << "Error: Invalid selection.";
			system("pause");
		}
	}
	cout << "Goodbye\n";
	system("pause");
}