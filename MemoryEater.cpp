#include "MemoryEater.h"

using namespace std;

bool MemoryEater::toLeak = false;
int MemoryEater::sizeOfAllocatedMemory = 0;
vector<int*> MemoryEater::allocatedMemory;
bool MemoryEater::eating = false;


const char* MemoryEater::getMbOfAllocatedMemory()
{
	static string MB;
	MB = to_string(static_cast<int>(sizeOfAllocatedMemory / (1024.0 * 1024.0)));
	return  MB.c_str();
}

void MemoryEater::ReleaseAllMemory()
{
	for (int* memory : allocatedMemory) {
		delete[] memory;
	}
	allocatedMemory.clear();
	sizeOfAllocatedMemory = 0;
	toLeak = false;
	eating = false;

}

void MemoryEater::ReleaseSomeMemory(int numArraysToRemove)
{
	//provera da li numArraysToRemove ne prelazi broj zauzetih nizova
	numArraysToRemove = min(numArraysToRemove, static_cast<int>(allocatedMemory.size()));


	for (int i = 0; i < numArraysToRemove; i++) {
		sizeOfAllocatedMemory -= _msize(allocatedMemory[i]);
		delete[] allocatedMemory[i];

	}

	//obrisi pointere u vektoru za nizove koji su obrisani
	allocatedMemory.erase(allocatedMemory.begin(), allocatedMemory.begin() + numArraysToRemove);
}

void MemoryEater::EatMemory()
{


	int sizeMB = rand() % 5 + 1;
	int* memory = new int[sizeMB * 1024 * 1024 / sizeof(int)];
	sizeOfAllocatedMemory += _msize(memory);
	allocatedMemory.push_back(memory);

}

void MemoryEater::StartEatingMemory()
{
	if (eating) {
		return;
	}

	thread eatingThread([]() {
		while (toLeak) {
			eating = true;
			EatMemory();


			// random intervali za zvanje funkcije za alociranje memorije
			int sleepMilliseconds = rand() % 501 + 500; // Random number between 500 and 1000
			this_thread::sleep_for(chrono::milliseconds(sleepMilliseconds));
		}
		});

	// Detachuj tred tako da radi zasebno
	eatingThread.detach();
}
