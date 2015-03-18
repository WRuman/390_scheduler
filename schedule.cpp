/**
 * William Ruman 2015 -- Truman State University
 * A simulator for several algorithms which are used by
 * operating system CPU schedulers. Includes simulations of FCFS, SJF, and
 * Round-robin. 
 */

#include <iostream>

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cout << "You need to specify an input file name" << std::endl;
        return -10;
    }
    return 0;
}