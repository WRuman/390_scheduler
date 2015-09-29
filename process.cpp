/**
* William Ruman 2015 -- Truman State University
* Implementation of the process class defined in process.hpp
*/
#include "process.hpp"
#include <iostream>
#include <iomanip>
#include <cstdio>


Process::Process() {
    this->processNumber = 0;
    this->arrivalTime = 0;
    this->executionTime = 0;
    this->cpuTime = 0;
    this->waitingTime = 0;
    this->departureTime = 0;
    this->turnaroundTime = 0;
    this->done = false;
}

Process::Process(unsigned int pNum, unsigned int arriveT, unsigned int execT) {
    this->processNumber = pNum;
    this->arrivalTime = arriveT;
    this->executionTime = execT;
    this->cpuTime = 0;
    this->waitingTime = 0;
    this->departureTime = 0;
    this->turnaroundTime = 0;
    this->done = false;
}

// Diagnostic information for the process
void Process::print() {
    std::cout << "Process " << processNumber << " at " << this << std::endl;
}
// Pretty print process statistics with set column widths
void Process::printRow(){
    std::cout << std::setw(7) << processNumber << std::setw(11)
    << arrivalTime << std::setw(13) << departureTime
    << std::setw(10) << cpuTime << std::setw(19)
    << turnaroundTime << std::setw(16) << waitingTime << std::endl;
}

// Return how long the process still needs to run
unsigned int Process::getRemainingTime() {
    return executionTime - cpuTime;
}

unsigned int Process::getTurnaroundTime() {
    return turnaroundTime;
}

unsigned int Process::getWaitTime() {
    return waitingTime;
}

bool Process::isDone() {
    return done;
}
// Do nothing, incr wait time
void Process::wait() {
    waitingTime++;
}
// Do "work" and check if all work has been done.
// When all work has been done, do final calculations 
// for process stats and set done to 'true'
void Process::run() {
    cpuTime++;
    if (cpuTime >= executionTime) {
        done = true;
        departureTime = arrivalTime + executionTime + waitingTime;
        turnaroundTime = departureTime - arrivalTime;
    }
}

unsigned int Process::getArrivalTime() {
    return arrivalTime;
}
