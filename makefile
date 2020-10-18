project1.exe : main.o MemAllocSim.o Frame.o
	g++ main.o MemAllocSim.o Frame.o -o project1.exe

main.o : main.cpp MemAllocSim.hpp
	g++ -Wall -c main.cpp

MemAllocSim.o : MemAllocSim.cpp MemAllocSim.hpp Frame.hpp
	g++ -Wall -c MemAllocSim.cpp

Frame.o : Frame.cpp Frame.hpp
	g++ -Wall -c Frame.cpp

clean : 
	rm *.o project1.exe
