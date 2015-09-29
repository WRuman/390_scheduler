/**
* William Ruman 2015 -- Truman State University
* Functions for opening and parsing files to generate the necessary data
* structures for simulation.
*/

#ifndef __WR_FILEPARSE_HPP_INCLUDED
#define __WR_FILEPARSE_HPP_INCLUDED

#include <vector>
#include "process.hpp"

namespace wr {
    std::vector<Process> getFileData(char*);
}


#endif //__WR_FILEPARSE_HPP_INCLUDED
