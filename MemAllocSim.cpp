#include "MemAllocSim.hpp"
#include "Frame.hpp"

#include <sstream> // used for converting frame and page strings

using std::string;
using std::vector;

MemAllocSim::MemAllocSim()
{
	this->faults = 0;
	this->frameIndexOfOldestPage = 0;
	this->framesString = "";
	this->pagesString = "";
}

string MemAllocSim::GetPagesString() { return this->pagesString; }

string MemAllocSim::GetFramesString() { return this->framesString; }

void MemAllocSim::SetPagesString(string pagesString) { this->pagesString = pagesString; return; }

void MemAllocSim::SetFramesString(string framesString) { this->framesString = framesString; return; }

void MemAllocSim::ConvertPagesString()
{
	std::stringstream ss(this->pagesString);
	
	int page;
	while(ss >> page)
	{
		this->pagesToAdd.push_back(page);
	}
}

void MemAllocSim::ConvertFramesString()
{
	std::stringstream ss(this->framesString);

	int frameId;
	while(ss >> frameId)
	{
		Frame frame(frameId);
		this->framesVec.push_back(frame);
	}
}

int MemAllocSim::GetNumFrames() { return this->framesVec.size(); }

Frame MemAllocSim::GetFrameAtPosition(int position) { return this->framesVec.at(position); }

int MemAllocSim::GetNumPagesToAdd() { return this->pagesToAdd.size(); }

void MemAllocSim::InsertNextPage()
{
	int nextPage = this->pagesToAdd.at(0);
	this->pagesToAdd.erase(pagesToAdd.begin());
	
	if(this->WouldFault(nextPage))
	{
		this->faults++;
		this->framesVec.at(this->frameIndexOfOldestPage).SetStoredPage(nextPage);
		this->UpdateFrameIndexOfOldestPage();
	}
	// else the page is already loaded into memory and no page fault will occur
}

bool MemAllocSim::WouldFault(int page)
{
	for(unsigned int i = 0; i < framesVec.size(); ++i) // search the current frames to see if the page is already loaded into memory
	{
		if(framesVec.at(i).GetStoredPage() == page)
		{
			return false;
		} 

	}
	return true;
}

void MemAllocSim::UpdateFrameIndexOfOldestPage()
{
	if(this->frameIndexOfOldestPage == (this->framesVec.size() - 1) ) // if the current oldest page is at the end of the vector
	{
		this->frameIndexOfOldestPage = 0;
	}
	else
	{
		this->frameIndexOfOldestPage++;
	}
}

string MemAllocSim::GetPagesInMemory()
{
	string format = "\t";
	for(unsigned int i = 0; i < this->framesVec.size(); ++i)
	{
		format += std::to_string( this->framesVec.at(i).GetStoredPage() );
		format += "\t";
	}
	
	return format;
}

int MemAllocSim::GetFaults() {return this->faults;}




