#include "pcb.h"
#include <fstream>
#include <vector>

#ifndef __LOADER__H__
#define __LOADER__H__

/**
 * @brief Loader class for datafiles
 * 
 */
class Loader {
    std::ifstream datafile;
    
    public:
        Loader(std::string datafile_location);
        ~Loader();

        std::vector<pcb> get_processes();
    
};

#endif  //!__LOADER__H__