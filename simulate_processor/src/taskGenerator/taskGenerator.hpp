#ifndef TASKGENERATOR_H
#define TASKGENERATOR_H

#include<iostream>
#include "../../../libcppsim-0.2.5/src/cppsim.hh"
#include "../../../libcppsim-0.2.5/src/rng.hh"

#include "../processor/processor.hpp"
#include "../task/task.hpp"

using namespace std;

class TaskGenerator: public process {
    private:
        int total_task_generated;
        int max_task;
        double arrival_time;
        rng<int> *task_prob;
        handle<Processor> *proc;

    public:
        TaskGenerator(string name, int mt, double arrival_time);

        int getMaxTask();
        void setProcessor(handle<Processor> *p);
        
    protected:
        void inner_body(void);
};

#endif