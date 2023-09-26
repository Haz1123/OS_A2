#include "scheduler.h"
#include "types.h"

RoundRobinScheduler::RoundRobinScheduler(osp2023::time_type quantum) {
    this->ready_queue = std::deque<pcb>();
    this->quantum = quantum;
}

RoundRobinScheduler::~RoundRobinScheduler() {}

void RoundRobinScheduler::add_process(pcb process) {
    this->ready_queue.push_back(process);
}

std::optional<pcb> RoundRobinScheduler::get_next_process() {
    if (this->ready_queue.size() == 0) {
        return std::nullopt;
    }
    pcb next_process = this->ready_queue.front();
    this->ready_queue.pop_front();
    return next_process;
}

std::optional<osp2023::time_type> RoundRobinScheduler::get_max_runtime() {
    return this->quantum;
}