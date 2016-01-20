/************************************
* Author: Steven Ohlund
* File Name: MapObjects.h
* Date Created: 11.2.15
* Modifications: To numerous to count, see github commit history to see changes.
************************************/

#pragma once
#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::ios;

enum ObjectType {Computer, Phone, Router};

const char* ObjectValue[];

enum MemorySize {
	B1, B2, B4, B8, B16, B32, B64, B128, B256, B512, KB1, KB2, KB4, KB8, KB16, KB32, KB64,
	KB128, KB256, KB512, MB1, MB2, MB4, MB8, MB16, MB32, MB64, MB128, MB256, MB512, GB1,
	GB2, GB4, GB8, GB16, GB32, GB64, GB128, GB256, GB512, TB1, TB2, TB4, TB8,
	TB16, TB32, TB64, TB128, TB256, TB512, PB1
};
const char* MemValues[];

enum CPUSpeed { MHz400, MHz600, MHz800, MHz1000, MHz1200, MHz1500, MHz1800, MHz2000 };
const char* CPUvalues[];

const int MAX_CONNECTIONS = 8;

double MemorySizeVal(MemorySize size);

struct Connection
{
	unsigned int connectedID;
	bool wired;
	unsigned char signalStrength;     // using values 1-100 for % strength
	int signalSpeed;
	ObjectType object;
};

/**********************************************************************************************
* Class: commonResources
*
* Purpose: To have an abstract base class that I can polymorph into all of the child classes
*
* Public Member Functions
*		void TurnPowerOn(); and	void TurnPowerOff();
*			changes the Poweron flag;
*		bool IsPowerOn();
*			Returns poweron flag
*		int GetID();
*			Returns object's ID
*		MemorySize GetRAM();
*			Returns Object's RAM value 
*		CPUSpeed GetCPU();
*			Returns Object's CPU speed value				
*		unsigned char GetCPUCores();
*			Returns Object's # of CPU cores
*		virtual void DisplayStats() =0;
*			Pure virtual function that displays Objects stats to console in a human understandable way
*		ObjectType GetObject();
*			Returns Object's type
*		virtual void WriteObjectToFile(ofstream & file);'
*			Writes the stats of the object to the passed filestream
*
* Methods:
*		None at this time
*
**********************************************************************************************/
class commonResources
{
public:
	commonResources::commonResources();
	void TurnPowerOn();
	void TurnPowerOff();
	bool IsPowerOn();
	int GetID();
	MemorySize GetRAM();
	CPUSpeed GetCPU();
	unsigned char GetCPUCores();
	virtual void DisplayStats() =0;
	ObjectType GetObject();
	virtual void WriteObjectToFile(ofstream & file);

protected:
	unsigned int GetNewID();
	void SetID(unsigned int ID);
	void SetRAM(MemorySize RAM);
	void SetCPU(CPUSpeed CPU_Speed, unsigned char Cores);
	void SetObject();
	void SetObject(ObjectType object);

private:
	ObjectType object;
	bool PowerOn;
	unsigned int UniqueID;
	MemorySize RAM;
	CPUSpeed CPU;
	unsigned char CPU_Cores;
	static int IDcounter;
};

/********************************************************************************************
* Class: cComputer
*
* Purpose: To define an object of type computer
*
* Public Member Functions:
*		Inherits all functions from commonResources
*		MemorySize GetHDSize();
*			Returns the Hard drive size
*		double GetHDFill();
*			Returns the percent filled of the hard drive
*		void SetConnection(unsigned int ID);
*			Sets the ID given as the router connected to, and the connection as wired with random speed and strength
*
* Methods:
*		None at this time
*
**********************************************************************************************/
class cComputer : public commonResources
{
public:
	cComputer();
	void DisplayStats();
	MemorySize GetHDSize();
	double GetHDFill();
	void SetConnection(unsigned int ID);
protected:
	void SetHDSize(MemorySize size);
	void SetHDFill(double fill);

private:
	MemorySize HDD_Size;
	double HDD_Filled;
	Connection router;
};

/********************************************************************************************
* Class: cPhone
*
* Purpose: To define an object of type phone
*
* Public Member Functions:
*		Inherits all functions from commonResources
*		void SetConnection(unsigned int ID);
*			Sets the ID given as the router connected to, and the connection as wireless with random speed and strength
*
* Methods:
*		None at this time
*
**********************************************************************************************/
class cPhone : public commonResources
{
public:
	cPhone();
	void DisplayStats();
	void SetConnection(unsigned int ID);
private:
	Connection router;
};

/********************************************************************************************
* Class: cRouter
*
* Purpose: To define an object of type router
*
* Public Member Functions:
*		Inherits all functions from commonResources
*		void SetConnection(unsigned int ID, ObjectType object);
*			Sets the ID given as the object connected to, and the connection as wired or wireless with random speed and strength
*
* Methods:
*		None at this time
*
**********************************************************************************************/
class cRouter : public commonResources
{
public:
	cRouter();
	void DisplayStats();
	void SetConnection(unsigned int ID, ObjectType object);

private:
	Connection connectedDevices[MAX_CONNECTIONS];
	short int activeConnections;
};
