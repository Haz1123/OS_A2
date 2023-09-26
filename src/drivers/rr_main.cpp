#include <iostream>
#include <deque>
#include "../common/loader.h"
#include "../common/pcb.h"
#include "../common/simulator.h"
#include "../common/results_formatter.h"

const std::string program_usage = "Program usage: rr [quantum] [datafile]";

int main(int argc, char** argv) {

    // Check arguments
    if(argc != 3) {
        std::cout << program_usage << std::endl;
        exit(1);
    }

    std::vector<pcb> process_list;

    Loader loader = Loader(argv[2]);
    process_list = loader.get_processes();

    int quantum = 0;

    try {
        quantum = std::stoi(argv[1]);
    } catch(std::invalid_argument const& e) {
        std::cout << "Error parsing quantum:" << e.what() << std::endl;
        exit(1);
    } catch(std::out_of_range const& e) {
        std::cout << "Error parsing quantum:" << e.what() << std::endl;
        exit(1);
    }

    // Run simulation
    Scheduler* scheduler = new RoundRobinScheduler(quantum);
    std::vector<pcb> results = run_simulation(scheduler, process_list);

    // Print results
    print_results(results);

    return 0;

}