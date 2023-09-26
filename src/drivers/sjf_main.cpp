#include <iostream>
#include <deque>
#include "../common/loader.h"
#include "../common/pcb.h"
#include "../common/simulator.h"
#include "../common/results_formatter.h"

const std::string program_usage = "Program usage: sjf [datafile]";

int main(int argc, char** argv) {

    // Check arguments
    if(argc != 2) {
        std::cout << program_usage << std::endl;
        exit(1);
    }

    Loader loader = Loader(argv[1]);
    std::vector<pcb> process_list = loader.get_processes();

    // Run simulation
    Scheduler* scheduler = new ShortestJobFirstScheduler();
    std::vector<pcb> results = run_simulation(scheduler, process_list);
    
    // Print results
    print_results(results);

    return 0;

}