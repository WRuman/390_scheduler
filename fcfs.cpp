/**
* William Ruman 2015 -- Truman State University
* Implementation of the First come, first served scheduling algorithm
*/

#include "algorithm.hpp"
#include <list>
#include "process.hpp"
#include <iostream>
#include <climits>

class FCFS : public Algorithm {

public:
    FCFS() {
        executing = NULL;
        name = "FCFS";
    }

    void scheduleNext(std::list<Process*>& readyQueue, unsigned int tick) {
        // No work to do
        if (readyQueue.empty()) {
            return;
        }
        // The executing process is not finished, so let it run
        // another tick and increment the wait time on all other
        // processes
        if (executing != NULL && !(executing->isDone())) {
            executing->run();
            incrWait(readyQueue, executing);
            return;
        }
        else {
            // Executing process is done, remove it from the ready
            // queue and reset executing process
            if (executing != NULL && executing->isDone()) {
                readyQueue.remove(executing);
                if (readyQueue.empty()) {
                    return;
                }
                executing = NULL;
            }
            // Find process with lowest arrival time in the 
            // ready queue
            unsigned int low = UINT_MAX;
            for (std::list<Process*>::iterator i = readyQueue.begin(); i != readyQueue.end(); ++i) {
                if ((*i)->getArrivalTime() < low) {
                    low = (*i)->getArrivalTime();
                    executing = (*i);
                }
            }
            // Let process run a tick, increment wait on all others
            executing->run();
            incrWait(readyQueue, executing);
            return;
        }
    }
private:
    // Increment wait time for each process except the 
    // executing one (exception)
    void incrWait(std::list<Process*>& readyQueue, Process* exception){
        for (std::list<Process*>::iterator i = readyQueue.begin(); i != readyQueue.end(); ++i) {
            if ((*i) != exception) {
                (*i)->wait();
            }
        }
    }
    
};
