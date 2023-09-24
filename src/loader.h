#include "pcb.h"
#include <fstream>
#include <vector>
#include <format>

#ifndef __LOADER__H__
#define __LOADER__H__

/**
 * @brief Loader class for datafiles
 * 
 */
class Loader {
    std::ifstream datafile;
    
    public:
        Loader(std::string datafile_location) throw(std::ifstream::failure);
        ~Loader();

        std::vector<pcb> get_processes() throw(PcbParseException);
    
};

class PcbParseException : public std::exception {
    public:
        PcbParseException(std::string line) : line(line) {};
        ~PcbParseException() throw() {};
        const char* what() const throw() { 
            return std::format("Error parsing PCB from line: {}", this->line).c_str(); 
        };
    private:
        std::string line;
};

#endif  //!__LOADER__H__