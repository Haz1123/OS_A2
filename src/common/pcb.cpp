#include "pcb.h"
#include "types.h"
#include <math.h>
pcb::pcb(osp2023::id_type id, osp2023::time_type total_time) {
    this->id = id;
    this->total_time = total_time;
    this->time_used = 0;
    this->total_wait_time = 0;
    this->first_response_time = osp2023::time_not_set;
    this->final_response_time = osp2023::time_not_set;
    this->last_time_on_cpu = 0; 
}

osp2023::time_type pcb::run_process(osp2023::time_type current_time, osp2023::time_type time_slice) {
    if(this->first_response_time == osp2023::time_not_set) {
        this->first_response_time = current_time;
    }
    this->total_wait_time += current_time - this->last_time_on_cpu;
    this->last_time_on_cpu = current_time;
    int current_time_used = std::min(this->total_time - this->time_used, time_slice);

    this->time_used+=current_time_used;

    if(this->time_used == this->total_time) {
        this->final_response_time = current_time + current_time_used;
    }

    return current_time + current_time_used;
}

osp2023::time_type pcb::get_id() {
    return this->id;
}
