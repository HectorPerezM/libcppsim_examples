#include "taskGenerator.hpp"

TaskGenerator::TaskGenerator(string name, int mt, double _arrival_time): process(name) {
    this->max_task = mt;
    this->total_task_generated = 0;
    this->arrival_time = _arrival_time;

    //TODO: Preguntar Vero si esta bien la uniforme, que trabaja con enteros u otra
    task_prob = new rngDiscUniform("Task Chance", 0, 100);
}

void TaskGenerator::setProcessor(handle<Processor> *p) {
    this->proc = p;
}


void TaskGenerator::inner_body() {
    while(true) {
        /* Stop when all task where generated */
        if(this->total_task_generated == this->max_task) {
            passivate();
        }

        /* Creates a new task */
        Task *t = new Task(task_prob->value());

        /* Processor recieves this created task */
        (*proc)->addTask(t);

        if((*proc)->idle() && !(*proc)->getState()) {
            (*proc)->activateAfter(current());
        }

        this->total_task_generated += 1;
        hold(this->arrival_time);
    }
}