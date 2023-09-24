// Loads/parses data from input files

#include "loader.h"
#include "pcb.h"
#include <fstream>
#include <vector>

Loader::Loader(std::string datafile_location) throw(std::ifstream::failure) {
    this->datafile.exceptions(std::ifstream::badbit);
    this->datafile.open(datafile_location);
};

Loader::~Loader() {
    this->datafile.close();
}

std::vector<pcb> Loader::get_processes() throw(PcbParseException) {
    std::vector<pcb> processes;
    std::string line;
    while(std::getline(this->datafile, line)) {
        try {
            int process_id = std::stoi(line.substr(0, line.find_first_of(",")));
            int burst_time = std::stoi(line.substr(line.find_first_of(",") + 1, line.length()));
            processes.push_back(pcb(process_id, burst_time));
        } catch(std::invalid_argument e) {
            throw PcbParseException(line);
        } catch(std::out_of_range e) {
            throw PcbParseException(line);
        }
    }
    return processes;
}

