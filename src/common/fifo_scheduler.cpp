#include "scheduler.h"
#include <optional>

FifoScheduler::FifoScheduler() {
    this->processes = std::vector<pcb>();
}

FifoScheduler::~FifoScheduler() {}

void FifoScheduler::add_process(pcb process) {
    this->processes.push_back(process);
}

std::optional<pcb> FifoScheduler::get_next_process() {
    if (this->processes.size() == 0) {
        return std::nullopt;
    }
    pcb next_process = this->processes[0];
    this->processes.erase(this->processes.begin());
    return next_process;
}

std::optional<osp2023::time_type> FifoScheduler::get_max_runtime() {
    return std::nullopt;
}