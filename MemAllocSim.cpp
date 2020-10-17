#include "MemAllocSim.hpp"
#include "Frame.hpp"

#include <sstream> // used for converting frame and page strings
		#include <iostream>
using std::string;
using std::vector;

MemAllocSim::MemAllocSim()
{
	this->faults = 0;
	this->frameIndexOfOldestPage = 0;
	this->framesString = "";
	this->pagesString = "";
}

// deallocates memory for Frame* memory array
MemAllocSim::~MemAllocSim()
{
	//delete this->memory;
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
//std::cout << "\tpushing " << page << " onto pagesToAdd." << std::endl;
	}	
//std::cout << "\tDone pushing onto pagesToAdd." << std::endl;
}

void MemAllocSim::ConvertFramesString()
{
	std::stringstream ss(this->framesString);

	int frameId;
	while(ss >> frameId)
	{
		Frame frame(frameId);
		this->framesVec.push_back(frame);
//std::cout << "\tAdded " << frame.GetId() << " to the vector." << std::endl;
	}
//std::cout << "\tDone Adding Frames" << std::endl;
}

int MemAllocSim::GetNumFrames() { return this->framesVec.size(); }

Frame MemAllocSim::GetFrameAtPosition(int position) { return this->framesVec.at(position); }

int MemAllocSim::GetNumPagesToAdd() { return this->pagesToAdd.size(); }

void MemAllocSim::InsertNextPage()
{
	int nextPage = this->pagesToAdd.at(0);
//std::cout << "\tnextPage set to " << this->pagesToAdd.at(0) << std::endl;
	this->pagesToAdd.erase(pagesToAdd.begin());
//std::cout << "\tErased page from pagesToAdd vector" << std::endl;
	
	if(this->WouldFault(nextPage))
	{
//std::cout << "\tPage fault occured" << std::endl;
		this->faults++;
//std::cout << "\tPage fault count is now " << this->faults << std::endl;
		this->framesVec.at(this->frameIndexOfOldestPage).SetStoredPage(nextPage);
//std::cout << "\tFrame at index " << this->frameIndexOfOldestPage << " had its storedPage set to " << nextPage << std::endl;
		this->UpdateFrameIndexOfOldestPage();
//std::cout << "\tframeIndexOfOldestPage updated to " << this->frameIndexOfOldestPage << std::endl;
	}
	// else the page is already loaded into memory and no page fault will occur
}

bool MemAllocSim::WouldFault(int page)
{
//std::cout << "\tSearching for " << page << " in framesVec" << std::endl;
	for(int i = 0; i < framesVec.size(); ++i) // search the current frames to see if the page is already loaded into memory
	{
		if(framesVec.at(i).GetStoredPage() == page)
		{
//std::cout << "\tFound " << page << " at index " << i << std::endl;
			return false;
		} 

	}
//std::cout << "\tDid not find " << page << std::endl;
	return true;
}

void MemAllocSim::UpdateFrameIndexOfOldestPage()
{
//std::cout << "\tAT TOP OF UpdateFrameIndexOfOldestPage()" << std::endl;
	if(this->frameIndexOfOldestPage == (this->framesVec.size() - 1) ) // if the current oldest page is at the end of the vector
	{
//std::cout << "\tframeIndexOfOldestPage is " << this->frameIndexOfOldestPage << " and is at the end of framesVec" << std::endl;
		this->frameIndexOfOldestPage = 0;
	}
	else
	{
//std::cout << "\tframeIndexOfOldestPage is " << this->frameIndexOfOldestPage << " and is not at the end of framesVec" << std::endl;
		this->frameIndexOfOldestPage++;
	}
}

string MemAllocSim::GetPagesInMemory()
{
	string format = "\t";
	for(int i = 0; i < this->framesVec.size(); ++i)
	{
//std::cout << "\tthis->framesVec.at(" << i <<").GetStoredPage: " << this->framesVec.at(i).GetStoredPage() << std::endl;
		format += std::to_string( this->framesVec.at(i).GetStoredPage() );
		format += "\t";
	}
	
	return format;
}

int MemAllocSim::GetFaults() {return this->faults;}




