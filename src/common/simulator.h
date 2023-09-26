#include "scheduler.h"
#include <vector>

#ifndef __SIMULATOR__H__
#define __SIMULATOR__H__

// Runs a simulation using the given scheduler and returns the results
std::vector<pcb> run_simulation(Scheduler* scheduler, std::vector<pcb> processes);

#endif  //!__SIMULATOR__H__
