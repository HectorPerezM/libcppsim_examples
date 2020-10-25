#include "processor.hpp"

Processor::Processor(string name, int id) : process(name) {
    this->processorId = id;
    this->busy = false;
    this->service_time = 0.0;
}

int Processor::getId() { return this->processorId; }
bool Processor::getState() { return this->busy; }
double Processor::getServiceTime() { return this->service_time; }
list<Task*> Processor::getTaskQueue() { return this->task_queue; }
Task* Processor::getTask() { return this->task; }

void Processor::addTask(Task *t) {
    this->task_queue.push_front(t);
}

void Processor::inner_body() {
    while(true) {
        if(this->task_queue.empty()) {
            cout << "Queue is empty." << endl;
            passivate();
        }

        task = this->task_queue.front(); 
        this->task_queue.pop_front();

        this->busy = true;
        cout << "In processor..." << endl;
        cout << "Task is: " << endl;
        cout << "   -type: " << task->getType() << endl;
        cout << "   -chance: " << task->getChance() << endl;
        cout << "   -Time Service: " << task->getTimeService() << endl;

        hold(task->getTimeService());
        this->service_time += task->getTimeService();
        this->total_task += 1;
        cout << "   -- evt time" << this->evTime() << endl;
        this->busy = false;
    }
}