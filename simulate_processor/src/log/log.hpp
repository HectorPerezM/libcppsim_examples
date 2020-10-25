#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>

using namespace std;

class Log  {
    private:
        int id;
        int processor_id;
        bool processor_state; 
        int processor_queue_length;
        double mean_time_per_task;


    public:
        Log(int _id, int proc_id, bool proc_state, int pql, int mtpt);
        int getId();
        int getProcessorId();
        bool getProcessorState();
        int getProcessorQueueLength();
        int getMeanTimePerTask();
        void show();
};

#endif