#include "MemAllocSim.hpp"

#include <sstream> // used for converting frame and page strings
		#include <iostream>
using std::string;
using std::vector;

MemAllocSim::MemAllocSim()
{
	this->faults = 0;
	this->framesString = "";
	this->pagesString = "";
}

MemAllocSim::~MemAllocSim()
{

}

void MemAllocSim::ConvertFramesString()
{
	std::stringstream ss(this->framesString);

	int frame;
	while(ss >> frame)
	{
		this->framesToAdd.push_back(frame);
std::cout << "\tAdded " << frame << " to the vector." << std::endl;
	}
std::cout << "\tDone Adding Frames" << std::endl;
}

string MemAllocSim::GetFramesString()
{
	return this->framesString;
}

string MemAllocSim::GetPagesString()
{
	return this->pagesString;
}

void MemAllocSim::SetFramesString(string framesString)
{
	this->framesString = framesString;
	return;
}

void MemAllocSim::SetPagesString(string pagesString)
{
	this->pagesString = pagesString;
	return;
}

string MemAllocSim::GetMemory()
{
	return "";
}

bool MemAllocSim::WouldFault(string frameName)
{
	return false;
}

void MemAllocSim::InsertNextPage()
{

}


