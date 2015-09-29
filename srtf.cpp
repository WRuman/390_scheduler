/**
* William Ruman 2015 -- Truman State University
* Implementation of the shortest remaining time first
* scheduling algorithm (preemptive)
*/

#include "algorithm.hpp"
#include <list>
#include "process.hpp"
#include <iostream>
#include <climits>

class SRTF : public Algorithm {

public:
    SRTF() {
        executing = NULL;
        name = "SRTF";
    }

    void scheduleNext(std::list<Process*>& readyQueue, unsigned int tick) {
        // No work to do
        if (readyQueue.empty()) {
            return;
        }
        
        unsigned int low = UINT_MAX;
        Process* lowProc;
        // Check for process with shortest execution time remaining
        for (std::list<Process*>::iterator i = readyQueue.begin(); i != readyQueue.end(); ++i) {
            // If this process has less remaining time than the 
            // previous low remaining time, it is scheduled
            if ((*i)->getRemainingTime() < low) {
                low = (*i)->getRemainingTime();
                executing = (*i);
                lowProc = (*i);
            }
            // If a process matches the current shortest remaining 
            // execution time, break the tie with fcfs
            if ((*i)->getRemainingTime() == low) {
                if (lowProc->getArrivalTime() < (*i)->getArrivalTime()){
                    executing = lowProc;
                }
                else {
                    executing = (*i);
                }
            }
        }
        // Run the selected process a tick and increment wait times
        executing->run();
        incrWait(readyQueue, executing);
        // If the process finished, we can remove it from the ready queue
        if (executing->isDone()) {
            readyQueue.remove(executing);
        }
        return;

    }

private:
    void incrWait(std::list<Process*>& readyQueue, Process* exception){
        for (std::list<Process*>::iterator i = readyQueue.begin(); i != readyQueue.end(); ++i) {
            if ((*i) != exception) {
                (*i)->wait();
            }
        }
    }

};
