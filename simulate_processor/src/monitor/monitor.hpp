#ifndef MONITOR_H
#define MONITOR_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "../processor/processor.hpp"
#include "../log/log.hpp"
#include "../../../libcppsim-0.2.5/src/cppsim.hh"

using namespace std;

class Monitor: public process {
    private:
        int delta;
        string file_path;
        handle<Processor> *proc;
        vector<Log*> logs;

        int processor_queue_length;

        double task_time;
        int total_task;
        double mean_time_per_task;
        
        double processor_ocupation;
        
        
    public:
        bool stop;
        Monitor(string name, handle<Processor> *p, int _delta, string fp);
        
        int getProcessorQueueLength();
        void setProcessorQueueLength(int size);
        double getMeanTimePerTask();
        double getProcessorOcupation();
        int getDelta();
        double calculateTimePerTask(double _task_time, int _new_task);
        void saveToCsv();


    protected:
        void inner_body(void);
};

#endif