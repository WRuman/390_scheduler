/**
* William Ruman 2015 -- Truman State University
* Abstract algorithm class that all algorithms must implement in order to
* run on the scheduler
*/

#ifndef __WR_ALGORITHM_HPP_INCLUDED__
#define __WR_ALGORITHM_HPP_INCLUDED__


#include <list>
#include <string>
#include "process.hpp"


class Algorithm {
public:
    virtual void scheduleNext(std::list<Process*>&, unsigned int) = 0;
    std::string name;
protected:
    Process* executing;
};

#endif // __WR_ALGORITHM_HPP_INCLUDED__
