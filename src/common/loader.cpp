// Loads/parses data from input files

#include "loader.h"
#include "pcb.h"
#include <fstream>
#include <deque>

Loader::Loader(std::string datafile_location) {
    this->datafile.open(datafile_location);
    if(this->datafile.fail()) {
        std::cout << "Error opening datafile: " << datafile_location << std::endl;
        exit(1); // Early exit here to avoid complexity in mains
    }
}

Loader::~Loader() {
    this->datafile.close();
}

std::vector<pcb> Loader::get_processes() {
    std::vector<pcb> processes;
    std::string line;
    while(std::getline(this->datafile, line)) {
        try {
            int process_id = std::stoi(line.substr(0, line.find_first_of(",")));
            int burst_time = std::stoi(line.substr(line.find_first_of(",") + 1, line.length()));
            processes.push_back(pcb(process_id, burst_time));
        } catch(std::invalid_argument const& e) {
            std::cout << "Error parsing line:" + line + " cause:" << e.what() << std::endl;
            exit(1); // Early exit here to avoid complexity in mains
        } catch(std::out_of_range const& e) {
            std::cout << "Error parsing line:" + line + " cause:" << e.what() << std::endl;
            exit(1); // Early exit here to avoid complexity in mains
        }
    }
    return processes;
}

