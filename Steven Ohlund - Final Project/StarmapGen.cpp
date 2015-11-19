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


void CreateNewMap()
{}

void OpenExistingMap()
{}

int main()
{
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
			CreateNewMap();
			break;
		case 2:
			OpenExistingMap();
			break;
		default:
			cout << "Error: Invalid selection.";
			system("pause");
		}
	}
	cout << "Goodbye";
	system("pause");
}