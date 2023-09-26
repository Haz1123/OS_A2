#include <vector>
#include <deque>
#include <optional>
#include "pcb.h"
#ifndef __SCHEDULER__H__
#define __SCHEDULER__H__

class Scheduler {
    public:
        virtual ~Scheduler() {};
        // Adds a process to the queue.
        virtual void add_process(pcb process) = 0;
        // Returns the next process to run, or none if there are no more processes to run
        virtual std::optional<pcb> get_next_process() = 0;
        // Get the maximum runtime of the process.
        virtual std::optional<osp2023::time_type> get_max_runtime() = 0;
};

class FifoScheduler : public Scheduler {
    public:
        FifoScheduler();
        ~FifoScheduler();
        void add_process(pcb process);
        std::optional<pcb> get_next_process();
        std::optional<osp2023::time_type> get_max_runtime();
    private:
        std::vector<pcb> processes;
};

class ShortestJobFirstScheduler: public Scheduler {
    public:
        ShortestJobFirstScheduler();
        ~ShortestJobFirstScheduler();
        void add_process(pcb process);
        std::optional<pcb> get_next_process();
        std::optional<osp2023::time_type> get_max_runtime();
    private:
        std::vector<pcb> processes;
};


class RoundRobinScheduler: public Scheduler {
    public:
        RoundRobinScheduler(osp2023::time_type quantum);
        ~RoundRobinScheduler();
        void add_process(pcb process);
        std::optional<pcb> get_next_process();
        std::optional<osp2023::time_type> get_max_runtime();
    private:
        std::deque<pcb> ready_queue;
        osp2023::time_type quantum;
};

#endif  //!__SCHEDULER__H__