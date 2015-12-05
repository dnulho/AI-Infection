/************************************
* Author: Steven Ohlund
* File Name: StarmapGen.cpp
* Date Created: 11.2.15
* Modifications:
************************************/
#include "MapObjects.h"
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

// Standard object call
commonResources* CreateNewObject()
{
	switch (rand() % 4)// random selection of possible objects to create
	{
	case 0:	//	* Empty - ID will always be 0
		return nullptr;
	case 1:	//	* Computer
		return new cComputer();
	case 2:	//	* Router
		return new cRouter();
	case 3:	//	* Phone
		return new cPhone();
	default:
		cout << "Error: CreateNewObject()::rand is outside allowed values" << endl;
		return nullptr;
	}
}

commonResources* LoadObjectFromFile(unsigned int id, ifstream & ifile)
{

		// Find ID in file using binary search
		// Read ID info to memory
		// Return pointer to caller
		return nullptr;

}

void SaveObjectToFile(commonResources object, ofstream & ofile)
{
		// find number of lines in file
		if (false)
		{ }
		// find correct place in file to insert object
		// make new line to place object
		// write object to file
		// close file


}
int DisplayObjectMenu(commonResources * object)
{
	unsigned char choice = 0;
	// show menu with options to * display detailed stats
	//							 * move to connected objects (another function)
	//							 * return to main menu
	return choice;
}
int main()
{
	commonResources *crtObj = nullptr;
	srand(static_cast<unsigned int>(time(NULL)));
	char choice;
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
		case '0':
			done = true;
			break;
		case '1':
			crtObj = new cComputer();
		case '2':
			while (!done)
			{
				switch (DisplayObjectMenu(crtObj))
				{
				case -2:
					done = true;
					break;
				case -1:
					crtObj.DisplayStats();
					break;
				case 0:
						// move to first object
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
	cout << "Goodbye";
	system("pause");
}