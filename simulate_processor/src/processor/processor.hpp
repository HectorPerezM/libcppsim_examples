#ifndef PROCESSOR_H
#define PROCESSOR_H

#include<iostream>
#include "../task/task.hpp"
#include "../../../libcppsim-0.2.5/src/cppsim.hh"

using namespace std;

class Processor: public process {
    private:
        int processorId;
        bool busy;
        list<Task*> task_queue;
        Task *task;
        double service_time;
        double total_task;
        int task_queue_size;

    public:
        Processor(string name, int id);

        int getId();
        bool getState();
        double getServiceTime();
        void addTask(Task *t);
        list<Task*> getTaskQueue();
        Task* getTask();

    protected:
        void inner_body(void);
};

#endif