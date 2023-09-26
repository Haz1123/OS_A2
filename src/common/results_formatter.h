#include <vector>
#include <fstream>
#include <functional>
#include "pcb.h"

#ifndef __SAVE_RESULTS__H__
#define __SAVE_RESULTS__H__

void print_results(std::vector<pcb> processes) {
    std::cout << "--- Process Results ---" << std::endl;
    std::cout << "Process ID, Burst Time, Turnaround Time, Waiting Time, Response Time" << std::endl;
    for(pcb process : processes) {
        std::cout << process.get_id() << ", " << process.get_total_time() << ", " << process.get_final_response_time() << ", " << process.get_total_wait_time() << ", " << process.get_first_response_time() << std::endl;
    }

    std::cout << "--- Average Results ---" << std::endl;
    double average_turnaround = 0;
    double average_wait = 0;
    double average_response = 0;
    for(pcb process : processes) {
        average_turnaround += process.get_final_response_time();
        average_wait += process.get_total_wait_time();
        average_response += process.get_first_response_time();
    }
    average_turnaround /= processes.size();
    average_wait /= processes.size();
    average_response /= processes.size();
    std::cout << "Average Turnaround Time: " << average_turnaround << std::endl;
    std::cout << "Average Waiting Time: " << average_wait << std::endl;
    std::cout << "Average Response Time: " << average_response << std::endl;
}

#endif  //!__SAVE_RESULTS__H__