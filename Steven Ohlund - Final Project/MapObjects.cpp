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

double MemorySizeVal(MemorySize size)
{
	int i_size = static_cast<int>(size);
	return pow(2.0, i_size);
}

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
MemorySize cComputer::GetHDSize()
{
	return HDD_Space;
}


// Protected
void cComputer::SetHDSize(MemorySize size)
{
	HDD_Space = size;
}
void cComputer::SetHDFill(double fill)
{
	if (MemorySizeVal(HDD_Space) > fill)
	{
		cout << "Error: SetHDFill Overflow.";
	}
	else
	{

	}
}

// Private
cComputer::cComputer()  // Initializer
{
	SetID();
	SetRAM(static_cast<MemorySize>((rand() % 6) + 9));
	SetCPU(static_cast<CPUSpeed>((rand() % 5) + 4), rand()%4);
	SetHDSize(static_cast<MemorySize>((rand() % 14) + 30));
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


