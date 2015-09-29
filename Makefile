CC=g++
CFLAGS=-Wall

all: 
	$(CC) $(CFLAGS) schedule.cpp fileparsing.cpp process.cpp machine.cpp fcfs.cpp srtf.cpp roundRobin.cpp  -o schedule

