/*****************************************************************
* Author: Steven Ohlund
* File Name: MapObjects.cpp
* Date Created: 11.2.15
* Modifications: 
******************************************************************
* This File creates and declares the objects that will be used
* in StarMapGen.cpp
*
*
*****************************************************************/

#include "MapObjects.h"

enum MemorySize {MB1, MB2, MB4, MB8, MB16, MB32,MB64, MB128, mMB256, MB512, MB1024, GB2, GB3, GB4, GB6, GB8, GB10, GB12, GB16, GB32, GB64, GB128, GB256, GB512, TB1 };
enum CPUSpeed {MHz400, MHz600, MHz800, MHz1000, MHz1200, MHz1500, MHz1800, MHz2000};
const int MAX_CONNECTIONS = 8;

struct Connection
{
	unsigned int *connectedID;
	bool wired;
	unsigned char signalStrength;     // using values 1-100 for % strength
	int signalSpeed;
};

class commonResources
{
public:
	void TurnPowerOn();
	void turnPowerOff();

protected:

private:
	bool PowerOn;
	unsigned int UniqueID;
	MemorySize RAM;
	CPUSpeed CPU;
	unsigned short CPU_Cores;

};

class cComputer : public commonResources
{
	unsigned long long int HDD_Space;
	unsigned long long int HDD_Filled;
	Connection router;
};

class cPhone : public commonResources
{
	Connection router;
};

class cRouter : public commonResources
{
	Connection connectedDevices[MAX_CONNECTIONS];
};

//////////////////////////////////////
//         commonResources			//
//       Function Definitions		//
//////////////////////////////////////
void commonResources::TurnPowerOn()
{
	PowerOn = true;
}
void commonResources::turnPowerOff()
{
	PowerOn = false;
}