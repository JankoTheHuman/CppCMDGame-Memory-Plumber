#pragma once
class InitProgram
{
private:
	InitProgram();

	// Delete copy constructor and assignment operator to prevent copying
	InitProgram(const InitProgram&) = delete;
	InitProgram& operator=(const InitProgram&) = delete;
public:

	static InitProgram& getInstance();
};

