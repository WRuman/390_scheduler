/**
* William Ruman 2015 -- Truman State University
* Implementation of file parsing functions and data structure construction
* functions for fileparsing.hpp
*/

#include "fileparsing.hpp"
#include "process.hpp"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>

namespace wr {
    std::vector<Process> getFileData(char* filename) {

        std::ifstream input(filename);

        std::vector<Process> processes;
        unsigned int curProcess = 0;
        unsigned int curArrivalTime;
        unsigned int curExecTime;

        // Ensure file is open
        if (input.is_open()) {
            // Run loop for every line in the file
            // Fill variables from each line in the file
            while (input >> curArrivalTime >> curExecTime) {
                // Add processes to process list
                processes.push_back(Process(curProcess, curArrivalTime, curExecTime));
                curProcess++;
            }
            // Close the file
            input.close();
            return processes;
        }
        // File not found
        else {
            std::cout << "Unable to open designated file: File not found" << std::endl;
            exit(-20);
        }
    }
}


