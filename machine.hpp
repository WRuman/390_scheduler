/**
* William Ruman 2015 -- Truman State University
* Header for the machine class, which issues 'ticks' and dictates
* simulation state, as well as maintaining ready queues
*/

#ifndef __WR_MACHINE_HPP_INCLUDED__
#define __WR_MACHINE_HPP_INCLUDED__

#include "algorithm.hpp"
#include <list>
#include <vector>
#include "process.hpp"

class Machine {
public:
    Machine();
    Machine(std::vector<Process> &);
    unsigned int getTime();
    void start();
    void setSchedulingAlgorithm(Algorithm*);
private:
    unsigned int tick;
    Algorithm* schedulingAlgorithm;
    std::list<Process*> readyQueue;
    std::vector<Process> processList;
    void loadReadyQueueForTick(unsigned int);
    bool allProcessesComplete();
    void printResults();
    void printStats();
};


#endif //__WR_MACHINE_HPP_INCLUDED__
