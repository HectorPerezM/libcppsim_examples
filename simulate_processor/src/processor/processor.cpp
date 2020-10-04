#include "processor.hpp"

Processor::Processor(string name, int id) : process(name) {
    this->processorId = id;
    this->busy = false;
    this->service_time = 0.0;
}

int Processor::getId() { return this->processorId; }
bool Processor::getState() { return this->busy; }
double Processor::getServiceTime() { return this->service_time; }

void Processor::addTask(Task *t) {
    cout << "Adding task..." << endl;
    cout << "Task is: " << endl;
    cout << "   -type: " << t->getType() << endl;
    cout << "   -chance: " << t->getChance() << endl;
    cout << "   -Time Service: " << t->getTimeService() << endl;
    
    this->task_queue.push_front(t);
}

void Processor::inner_body() {
    //cout << "Inner_body Processor..." << endl;
    //cout << "Im the processor: " << this->getId() << endl;
    //cout << "My current state is: " << this->getState() << endl;

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
        this->busy = false;
    }
    
}