#include <vector>
#include "simulator.h"

ShortestJobFirstScheduler::ShortestJobFirstScheduler() {
    this->processes = std::vector<pcb>();
}

ShortestJobFirstScheduler::~ShortestJobFirstScheduler() {}

void ShortestJobFirstScheduler::add_process(pcb process) {
    this->processes.push_back(process);
    std::sort(this->processes.begin(), this->processes.end(), [](pcb a, pcb b) {
        return a.get_total_time() < b.get_total_time();
    });
}

std::optional<pcb> ShortestJobFirstScheduler::get_next_process() {
    if (this->processes.size() == 0) {
        return std::nullopt;
    }
    pcb next_process = this->processes[0];
    this->processes.erase(this->processes.begin());
    return next_process;
}

std::optional<osp2023::time_type> ShortestJobFirstScheduler::get_max_runtime() {
    return std::nullopt;
}