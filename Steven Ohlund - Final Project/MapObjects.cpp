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
bool commonResources::IsPowerOn()
{
	return PowerOn;
}
int commonResources::GetID()
{
	return UniqueID;
}
void commonResources::DisplayStats()
{
	cout << "Current RAM: " << RAM << "\n"
		<< "Current CPU Speed: " << CPUvalues[CPU] << "\n"
		<< "Current CPU Cores: " << CPU_Cores << "\n";
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
	return HDD_Size;
}
void cComputer::DisplayStats()
{
	cout << "Current Object ID: " << GetID() << "\n"
		<< "Current Object Type: Computer\n";
	if (IsPowerOn()) { cout << "Computer is currently on\n"; }
	else { cout << "Computer is currently off\n"; }
	cout << "Current Hard Drive Capacity: " << MemorySizeVal(HDD_Size) << "\n"
		<< "Current Hard Drive space used: " << HDD_Filled << endl;
	commonResources::DisplayStats();
}


// Protected
void cComputer::SetHDSize(MemorySize size)
{
	HDD_Size = size;
}
void cComputer::SetHDFill(double fill)
{
	if (MemorySizeVal(HDD_Size) > fill)
	{
		cout << "Error: SetHDFill Overflow.";
	}
	else
	{
		HDD_Filled = fill;
	}
}

// Private
cComputer::cComputer()  // Initializer
{
	SetID();
	TurnPowerOn();
	SetRAM(static_cast<MemorySize>((rand() % 6) + 28));
	SetCPU(static_cast<CPUSpeed>((rand() % 5) + 4), rand()%4);
	SetHDSize(static_cast<MemorySize>((rand() % 14) + 30));
	SetHDFill(MemorySizeVal(HDD_Size) );
}

//////////////////////////////////////
//              cPhone				//
//       Function Definitions		//
//////////////////////////////////////
// Public
cPhone::cPhone()
{
	SetID();
	TurnPowerOn();
	SetRAM(static_cast<MemorySize>((rand() % 6) + 26));
	SetCPU(static_cast<CPUSpeed>(rand() % 8), rand() % 2);
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
	TurnPowerOn();
	SetRAM(static_cast<MemorySize>((rand() % 8) + 22));
	SetCPU(static_cast<CPUSpeed>(rand() % 6), rand() % 2);
}
// Protected

// Private


