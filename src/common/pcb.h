#include <iostream>
#include "types.h"

#ifndef __PCB__H__  // tells the compiler to only include this file once
#define __PCB__H__

  // tells the compiler to only include this file once
              /**
 * the process control block - represents a process that needs to be executed in
 * our simulator. Please note the I used some custom types of osp2023::time_type
 * and osp2023::id_type. these are just aliases to long integers but they are
 * more meaningful type names, hinting at how they will be used. Please see
 * their definitions in types.h.
 **/
class pcb {
   public:
    pcb(osp2023::id_type id, osp2023::time_type total_time);
    // max and min duration for a process in our system.
    static constexpr osp2023::time_type MAX_DURATION = 100;
    static constexpr osp2023::time_type MIN_DURATION = 10;
    // Returns the new current time.
    osp2023::time_type run_process(osp2023::time_type current_time, osp2023::time_type time_slice);
    bool is_finished() { return this->time_used >= this->total_time; }

    osp2023::time_type get_id();
    osp2023::time_type get_total_time() { return this->total_time; }
    osp2023::time_type get_total_wait_time() { return this->total_wait_time; }
    osp2023::time_type get_first_response_time() { return this->first_response_time; }
    osp2023::time_type get_final_response_time() { return this->final_response_time; }

  private:
    // the unique process id
    osp2023::id_type id;
    // the total time that a process / job should run for
    osp2023::time_type total_time;
    // time used on this process.
    osp2023::time_type time_used;
    // Total time this process has spent waiting.
    osp2023::time_type total_wait_time;
    // what time was this process last on the cpu?
    osp2023::time_type last_time_on_cpu;
    // First response time.
    osp2023::time_type first_response_time;
    // Final response time.
    osp2023::time_type final_response_time;


};

#endif  //!__PCB__H__