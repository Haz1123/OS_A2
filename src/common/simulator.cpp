#include "scheduler.h"

std::vector<pcb> run_simulation(Scheduler* scheduler, std::vector<pcb> processes) {

    // Load processes into scheduler
    for(pcb process : processes) {
        scheduler->add_process(process);
    }

    // Run simulation
    osp2023::time_type current_time = 0;
    std::optional<pcb> next_process;
    std::vector<pcb> finished_processes = std::vector<pcb>();
    std::optional<osp2023::time_type> max_runtime = scheduler->get_max_runtime();
    while(true) {
        next_process = scheduler->get_next_process();
        if(next_process.has_value()) {
            if(max_runtime.has_value()) {
                current_time = next_process.value().run_process(current_time, max_runtime.value());
            } else {
                current_time = next_process.value().run_process(current_time, next_process.value().get_total_time());
            }
            if ( next_process.value().is_finished() ){
                finished_processes.push_back(next_process.value());
            } else {
                scheduler->add_process(next_process.value());
            }
        } else {
            break;
        }
    }

    // Return results
    return finished_processes;
}