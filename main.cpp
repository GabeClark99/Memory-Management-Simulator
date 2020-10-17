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
//pagesString = "7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1";
	m0.SetPagesString(pagesString);
	m0.ConvertPagesString();
	cout << "The reference string is: " << m0.GetPagesString() << endl;
	
	cout << endl;
	
	cout << "Please enter the frame numbers: ";
	getline(cin, frameString);
//frameString = "24 37 42";
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
//cout << "\tnumPagesToAdd: " << m0.GetNumPagesToAdd() << endl;
	cout << "----------------------------------------------------" << endl;
	
	
	
	for(int i = 0; m0.GetNumPagesToAdd() > 0; ++i)
	{
//cout << "\tSTART OF ITERATION " << i << endl;
		m0.InsertNextPage();
		cout << m0.GetPagesInMemory() << endl;
//cout << "\tEND OF ITERATION " << i << endl;
	}
	
	cout << "----------------------------------------------------" << endl;
	
	cout << "Number of page faults: " << m0.GetFaults() << endl;
	cout << endl;
	cout << "Thanks for using this program, dear Memory Manager!" << endl;
	
	//m0.InsertNextPage();
	//cout << m0.GetPagesInMemory() << endl;
	
	return 0;
}
