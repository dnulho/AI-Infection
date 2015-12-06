#pragma once
#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::ios;



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
	unsigned int *connectedID;
	bool wired;
	unsigned char signalStrength;     // using values 1-100 for % strength
	int signalSpeed;
};

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

protected:
	void SetID();
	void SetRAM(MemorySize RAM);
	void SetCPU(CPUSpeed CPU_Speed, unsigned char Cores);

private:
	bool PowerOn;
	unsigned int UniqueID;
	MemorySize RAM;
	CPUSpeed CPU;
	unsigned char CPU_Cores;
	static int IDcounter;
};

class cComputer : public commonResources
{
public:
	cComputer();
	void DisplayStats();
 protected:
	MemorySize GetHDSize();
	void SetHDSize(MemorySize size);
	void SetHDFill(double fill);
private:
	MemorySize HDD_Size;
	double HDD_Filled;
	Connection router;
};

class cPhone : public commonResources
{
public:
	cPhone();
	void DisplayStats();
private:
	Connection router;
};

class cRouter : public commonResources
{
public:
	cRouter();
	void DisplayStats();
private:
	Connection connectedDevices[MAX_CONNECTIONS];
};
