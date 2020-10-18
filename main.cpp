// Gabriel Clark

#include "MemAllocSim.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	MemAllocSim m0;
	std::string pagesString;
	std::string frameString;

	cout << "Please enter the reference string separated by spaces: ";
	getline(cin, pagesString);
	m0.SetPagesString(pagesString);
	m0.ConvertPagesString();
	cout << "The reference string is: " << m0.GetPagesString() << endl;
	
	cout << endl;
	
	cout << "Please enter the frame numbers: ";
	getline(cin, frameString);
	m0.SetFramesString(frameString);
	m0.ConvertFramesString();
	cout << "The frame numbers are: " << m0.GetFramesString() << endl;
	
	cout << endl;
	
	cout << "Assignment of the frames by FIFO algorithm: " << endl;
	cout << "Frames:";
	for(int i = 0; i < m0.GetNumFrames(); ++i)
	{
		cout << "\t" << m0.GetFrameAtPosition(i).GetId();
	}
	cout << endl;
	cout << "----------------------------------------------------" << endl;
	
	
	
	for(int i = 0; m0.GetNumPagesToAdd() > 0; ++i)
	{
		m0.InsertNextPage();
		cout << m0.GetPagesInMemory() << endl;
	}
	
	cout << "----------------------------------------------------" << endl;
	
	cout << "Number of page faults: " << m0.GetFaults() << endl;
	cout << endl;
	cout << "Thanks for using this program, dear Memory Manager!" << endl;
	
	return 0;
}
