#include "MemAllocSim.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	MemAllocSim m0;

	std::string framesString;
	getline(cin, framesString);

	m0.SetFramesString(framesString);
	m0.ConvertFramesString();


	return 0;
}
