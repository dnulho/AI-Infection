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

int commonResources::IDcounter = 0x2;

//////////////////////////////////////
//         commonResources			//
//       Function Definitions		//
//////////////////////////////////////
// Public
commonResources::commonResources()
{

}
void commonResources::TurnPowerOn()
{
	PowerOn = true;
}
void commonResources::TurnPowerOff()
{
	PowerOn = false;
}
int commonResources::GetID()
{
	return UniqueID;
}

// Protected
void commonResources::SetID()
{
	UniqueID = IDcounter;
	IDcounter++;
}
void commonResources::SetRAM(MemorySize ram)
{
	RAM = ram;
}
void commonResources::SetCPU(CPUSpeed CPU_Speed, unsigned char Cores)
{
	CPU = CPU_Speed;
	CPU_Cores = Cores;
}

// Private


//////////////////////////////////////
//            cComputer				//
//       Function Definitions		//
//////////////////////////////////////
// Public

// Protected

// Private
cComputer::cComputer()  // Initializer
{
	SetID();

}

//////////////////////////////////////
//              cPhone				//
//       Function Definitions		//
//////////////////////////////////////
// Public
cPhone::cPhone()
{
	SetID();
}
// Protected

// Private


//////////////////////////////////////
//              cRouter				//
//       Function Definitions		//
//////////////////////////////////////
// Public
cRouter::cRouter()
{
	SetID();
}
// Protected

// Private


