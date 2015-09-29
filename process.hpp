/**
* William Ruman 2015 -- Truman State University
* A class representing a running process, containing book-keeping information
* about arrival time and total execution time.
*/

#ifndef __WR_PROCESS_HPP_INCLUDED
#define __WR_PROCESS_HPP_INCLUDED


class Process {
private:
    unsigned int processNumber;
    unsigned int cpuTime;
    unsigned int arrivalTime;
    unsigned int executionTime;
    unsigned int waitingTime;
    unsigned int departureTime;
    unsigned int turnaroundTime;
    bool done;
public:
    Process();
    Process(unsigned int, unsigned int, unsigned int);
    void print();
    unsigned int getRemainingTime();
    unsigned int getArrivalTime();
    unsigned int getWaitTime();
    unsigned int getTurnaroundTime();
    void printRow();
    bool isDone();
    void wait();
    void run();
};

#endif //__WR_PROCESS_HPP_INCLUDED
