/**
* William Ruman 2015 -- Truman State University
* Implementation of the machine class, which manages the ready queue and takes
* outputs from the provided scheduling algorithm
*/

#include "machine.hpp"
#include <list>
#include "process.hpp"
#include <vector>
#include <iostream>
#include "algorithm.hpp"


Machine::Machine() {
    tick = 0;
}

Machine::Machine(std::vector<Process>& pList) {
    tick = 0;
    processList = pList;
}

unsigned int Machine::getTime() {
    return tick;
}

// Given the time, place processes in the ready queue that have
// arrived at that time
void Machine::loadReadyQueueForTick(unsigned int tick) {
    for (std::vector<Process>::iterator i = processList.begin(); i != processList.end(); ++i) {
        if (i->getArrivalTime() == tick) {
            readyQueue.push_back(&(*i));
        }
    }
}

// Print machine statistics, like avg waits and turnarounds
void Machine::printStats() {
    double avgWaitTime;
    double avgTurnaroundTime;

    unsigned int waitSum = 0;
    unsigned int turnSum = 0;
        
    for (std::vector<Process>::iterator i = processList.begin(); i != processList.end(); ++i) {
        turnSum += i->getTurnaroundTime();
        waitSum += i->getWaitTime();
    }

    avgTurnaroundTime = double(turnSum) / processList.size();
    avgWaitTime = double(waitSum) / processList.size();

    std::cout << "Average waiting time = " << avgWaitTime << std::endl;
    std::cout << "Average turnaround time = " << avgTurnaroundTime << std::endl << std::endl;
}

// Print scheduler info, process info, and call printstats
void Machine::printResults() {
    std::cout << "Algorithm: *** " << schedulingAlgorithm->name << " ***" << std::endl;
    std::cout << "Process    Arrival    Departure    On CPU    Turnaround Time    Waiting Time" << std::endl;
    for (std::vector<Process>::iterator i = processList.begin(); i != processList.end(); ++i) {
        i->printRow();
    }
    std::cout << std::endl;
    this->printStats();
}

// Check process list to determine if all processes have completed
bool Machine::allProcessesComplete() {
    for (std::vector<Process>::iterator i = processList.begin(); i != processList.end(); ++i) {
        if (!(i->isDone())) {
            return false;
        }
    }
    return true;
}

// Begin the machine's event loop, which exits when all processes are
// done and increments the clock tick
void Machine::start() {

    while (!allProcessesComplete()) {
        this->loadReadyQueueForTick(tick);
        schedulingAlgorithm->scheduleNext(readyQueue, tick);
        ++tick;
    }
    this->printResults();
}

void Machine::setSchedulingAlgorithm(Algorithm* selected) {
    schedulingAlgorithm = selected;
}
