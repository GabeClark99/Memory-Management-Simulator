#ifndef MEMALLOCSIM_HPP
#define MEMALLOCSIM_HPP

#include "Frame.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

class MemAllocSim
{
	private:
		int faults; // keep a running counter of number of page faults
		vector<int> pagesToAdd;
		vector<Frame> framesVec; // contains the current state of the frames
		int frameIndexOfOldestPage;
		string pagesString; // ex: "7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1"
		string framesString; // ex: "1 2 3 4" OR "24 37 42"
		
	public:
		MemAllocSim();
		~MemAllocSim(); // clear any dynamically allocated memory
		
		string GetPagesString();
		string GetFramesString();
		void SetPagesString(string pagesString); // input pages string of variable length
		void SetFramesString(string framesString); // input multiple (variable) frame IDs
		void ConvertPagesString();
		void ConvertFramesString();
		int GetNumFrames();
		Frame GetFrameAtPosition(int position);
		int GetNumPagesToAdd();
		void InsertNextPage(); // check if a fault would occur, evict a page, insert a page
		bool WouldFault(int page); // identify if adding a new frame would cause a page fault
		void UpdateFrameIndexOfOldestPage();
		string GetPagesInMemory(); // show what pages are in what frames
		int GetFaults();
};

#endif
