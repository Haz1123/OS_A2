#include <iostream>
#include <deque>
#include "../common/loader.h"
#include "../common/pcb.h"
#include "../common/simulator.h"
#include "../common/results_formatter.h"

const std::string program_usage = "Program usage: fifo [datafile]";

int main(int argc, char** argv) {

    // Check arguments
    if(argc != 2) {
        std::cout << program_usage << std::endl;
        exit(1);
    }

    std::vector<pcb> process_list;

    Loader loader = Loader(argv[1]);
    process_list = loader.get_processes();

    Scheduler* scheduler = new FifoScheduler();
    // Run simulation
    std::vector<pcb> results = run_simulation(scheduler, process_list);

    // Print results
    print_results(results);

    return 0;
}