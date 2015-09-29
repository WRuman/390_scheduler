/**
* William Ruman 2015 -- Truman State University
* Implementation of the First come, first served scheduling algorithm
*/

#include "algorithm.hpp"
#include <list>
#include "process.hpp"
#include <iostream>
#include <climits>

class RR : public Algorithm {

public:

    RR() {
        executing = NULL;
        name = "RR (Q = 1)";
    }

    void scheduleNext(std::list<Process*>& readyQueue, unsigned int tick) {
        // No work to do
        if (readyQueue.empty()) {
            executing = NULL;
            return;
        }
        // If there's nothing that was executing before (first run),
        // Grab the first process in the ready queue
        if (executing == NULL) {
            queueLoc = readyQueue.begin();
        }
        executing = *queueLoc;
        // Run the next scheduled process and increment wait times
        executing->run();
        incrWait(readyQueue, executing);
        // If executing process is done, remove it from the ready queue
        // safely
        if (executing->isDone()) {
            removeFromQueue(readyQueue, executing);
        }
        // Round robin, 'rotate' the queue
        else {
            rotateQueue(readyQueue);
        }
        return;

    }

private:

    std::list<Process*>::iterator queueLoc;
    // Ensure what's removed from the ready queue is isn't pointed
    // to after it's removed by rotating queueLoc beforehand
    void removeFromQueue(std::list<Process*>& readyQueue, Process* item) {
        if (item == (*queueLoc)) {
            rotateQueue(readyQueue);
        }
        readyQueue.remove(item);
    }
    // Treat the queue like it's circular, making sure not to run off
    // the end or iterate through an empty queue
    void rotateQueue(std::list<Process*>& readyQueue) {
        if (readyQueue.empty()) {
            executing = NULL;
            return;
        }
        if (*queueLoc == readyQueue.back()) {
            queueLoc = readyQueue.begin();
        }
        else {
            queueLoc++;
        }
    }
    // Regular wait increment, all processes in queue wait except
    // the executing one (exception)
    void incrWait(std::list<Process*>& readyQueue, Process* exception){
        for (std::list<Process*>::iterator i = readyQueue.begin(); i != readyQueue.end(); ++i) {
            if ((*i) != exception) {
                (*i)->wait();
            }
        }
    }

};
