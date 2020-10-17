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
//		Frame memory[]; // contains the current state of the frames
		vector<int> history;
		vector<int> framesToAdd;
		string framesString; // ex: "1 2 3 4" OR "24 37 42"
		string pagesString; // ex: "7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1"

	public:
		MemAllocSim();
		~MemAllocSim(); // clear any dynamically allocated memory

		string GetFramesString();
		string GetPagesString();
		void SetFramesString(string framesString); // input string of variable length
		void SetPagesString(string pagesString); // input multiple frame IDs of variable length

		void ConvertFramesString();
		void ConvertPagesString();
		string GetMemory(); // show what pages are in what frames
		bool WouldFault(string frameName); // identify if adding a new frame would cause a page fault
		void InsertNextPage(); // check if a fault would occur, evict a page, insert a page
};

#endif
