#pragma once
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib> 
#include <ctime>   
#include <iostream>
#include <random>


class MemoryEater
{
private:

	static std::vector<int*> allocatedMemory;
	static int sizeOfAllocatedMemory;
	static bool eating;


public:

	MemoryEater() = delete;
	static const char* getMbOfAllocatedMemory();
	static bool toLeak;
	static void ReleaseAllMemory();
	static void ReleaseSomeMemory(int i);
	static void EatMemory();
	static void StartEatingMemory();
};

