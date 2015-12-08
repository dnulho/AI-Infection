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

const char* ObjectValue[] = { "Computer", "Phone", "Router" };

const char* MemValues[] = {
	"B1", "B2", "B4", "B8", "B16", "B32", "B64", "B128", "B256", "B512", "KB1", "KB2", "KB4", "KB8", "KB16", "KB32", "KB64",
	"KB128", "KB256", "KB512", "MB1", "MB2", "MB4", "MB8", "MB16", "MB32", "MB64", "MB128", "MB256", "MB512", "GB1",
	"GB2", "GB4", "GB8", "GB16", "GB32", "GB64", "GB128", "GB256", "GB512", "TB1", "TB2", "TB4", "TB8",
	"TB16", "TB32", "TB64", "TB128", "TB256", "TB512", "PB1"
};

const char* CPUvalues[] = { "MHz400", "MHz600", "MHz800", "MHz1000", "MHz1200", "MHz1500", "MHz1800", "MHz2000" };

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
MemorySize commonResources::GetRAM()
{
	return commonResources::RAM;
}
CPUSpeed commonResources::GetCPU()
{
	return CPU;
}
unsigned char commonResources::GetCPUCores()
{
	return CPU_Cores;
}

ObjectType commonResources::GetObject()
{
	return object;
}


// Protected
unsigned int commonResources::GetNewID()
{
	return commonResources::IDcounter++;
}
void commonResources::SetID(unsigned int ID)
{
	UniqueID = ID;
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

void commonResources::SetObject()
{
	switch (rand() % 3)
	{
	case 0:
		object = Computer;
		break;
	case 1:
		object = Phone;
		break;
	case 2:
		object = Router;
		break;
	default:
		cout << "Error: SetObject() broke.";
	}
}
void commonResources::SetObject(ObjectType type)
{
	object = type;
}
// Private


//////////////////////////////////////
//            cComputer				//
//       Function Definitions		//
//////////////////////////////////////
// Public
cComputer::cComputer()  // Initializer
{
	SetID(GetNewID());
	TurnPowerOn();
	SetObject(Computer);
	SetRAM(static_cast<MemorySize>((rand() % 6) + 28));
	SetCPU(static_cast<CPUSpeed>((rand() % 4) + 4), rand() % 4);
	SetHDSize(static_cast<MemorySize>((rand() % 14) + 30));
	SetHDFill(MemorySizeVal(HDD_Size) / (rand() % 100 + 1));
	SetConnection(GetNewID());
}
MemorySize cComputer::GetHDSize()
{
	return HDD_Size;
}
void cComputer::DisplayStats()
{
	cout << "Current Object ID: " << GetID() << "\n"
		<< "Current Object Type: Computer\n";
	if (IsPowerOn()) { cout << "Computer is currently: On\n"; }
	else { cout << "Computer is currently: Off\n"; }
	cout << "Current Hard Drive Capacity: " << MemValues[HDD_Size] << "\n"
		<< "Current Hard Drive space used: " << std::setprecision(3) << MemorySizeVal(HDD_Size) / HDD_Filled << "\n"
		<< "Current RAM: " << MemValues[GetRAM()] << "\n"
		<< "Current CPU Speed: " << CPUvalues[GetCPU()] << "\n"
		<< "Current CPU Cores: " << static_cast<int>(GetCPUCores()) << "\n"
		<< "Connected to router: " << router.connectedID << "\n";
}


// Protected
void cComputer::SetHDSize(MemorySize size)
{
	HDD_Size = size;
}
void cComputer::SetHDFill(double fill)
{
	if (MemorySizeVal(HDD_Size) < fill)
	{
		cout << "Error: SetHDFill Overflow.";
		HDD_Filled = 0;
	}
	else
	{
		HDD_Filled = fill;
	}
}
void cComputer::SetConnection(unsigned int ID)
{
	router.connectedID = ID;
	router.wired = true;
	router.signalStrength = rand() % 100 + 1;
	router.signalSpeed = rand() % 20 + 1;
}
// Private


//////////////////////////////////////
//              cPhone				//
//       Function Definitions		//
//////////////////////////////////////
// Public
cPhone::cPhone()
{
//	SetID();
	TurnPowerOn();
	SetObject(Phone);
	SetRAM(static_cast<MemorySize>((rand() % 6) + 26));
	SetCPU(static_cast<CPUSpeed>(rand() % 8), rand() % 2);
}
void cPhone::DisplayStats()
{
	cout << "Current Object ID: " << GetID() << "\n"
		<< "Current Object Type: Phone\n";
	if (IsPowerOn()) { cout << "Phone is currently: On\n"; }
	else { cout << "Phone is currently: Off\n"; }
	cout << "Current RAM: " << MemValues[GetRAM()] << "\n"
		<< "Current CPU Speed: " << CPUvalues[GetCPU()] << "\n"
		<< "Current CPU Cores: " << static_cast<int>(GetCPUCores()) << "\n";
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
//	SetID();
	TurnPowerOn();
	SetObject(Router);
	SetRAM(static_cast<MemorySize>((rand() % 8) + 22));
	SetCPU(static_cast<CPUSpeed>(rand() % 6), rand() % 2);
}
void cRouter::DisplayStats()
{
	cout << "Current Object ID: " << GetID() << "\n"
		<< "Current Object Type: Router\n";
	if (IsPowerOn()) { cout << "Router is currently: On\n"; }
	else { cout << "Router is currently: Off\n"; }
	cout << "Current RAM: " << MemValues[GetRAM()] << "\n"
		<< "Current CPU Speed: " << CPUvalues[GetCPU()] << "\n"
		<< "Current CPU Cores: " << static_cast<int>(GetCPUCores()) << "\n";
}
// Protected

// Private


