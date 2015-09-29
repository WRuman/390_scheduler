/**
* William Ruman 2015 -- Truman State University
* A simulator for several algorithms which are used by
* operating system CPU schedulers. Includes simulations of FCFS, SRTF, and
* Round-robin.
*/

#include <iostream>
#include "fileparsing.hpp"
#include "machine.hpp"
#include "process.hpp"
#include "fcfs.cpp"
#include "srtf.cpp"
#include "roundRobin.cpp"
#include <vector>

int main(int argc, char* argv[]) {
    // No file name given
    if (argc < 2) {
        std::cout << "You need to specify an input file name" << std::endl;
        return -10;
    }
    // Make 3 copies of the process list
    std::vector<Process> processes = wr::getFileData(argv[1]);
    std::vector<Process> procCopy1(processes);
    std::vector<Process> procCopy2(processes);
    // Make 3 virtual machines and give them schedulers
    Machine vm1(processes);
    Machine vm2(procCopy1);
    Machine vm3(procCopy2);
    FCFS fcfsAlg;
    SRTF srtfAlg;
    RR rrAlg;
    vm1.setSchedulingAlgorithm(&fcfsAlg);
    vm2.setSchedulingAlgorithm(&srtfAlg);
    vm3.setSchedulingAlgorithm(&rrAlg);
    // Start the machines
    vm1.start();
    vm2.start();
    vm3.start();
    return 0;
}
