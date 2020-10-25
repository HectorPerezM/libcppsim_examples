#include "monitor.hpp"

Monitor::Monitor(string name, handle<Processor> *p, int _delta, string fp) : process(name) {
    this->delta = _delta;
    this->processor_queue_length = 0;
    this->task_time = 0.0;
    this->total_task = 0;
    this->mean_time_per_task = 0.0;
    this->stop = false;
    this->proc = p;
    this->file_path = fp;
}

int Monitor::getProcessorQueueLength() { return this->processor_queue_length; }
void Monitor::setProcessorQueueLength(int size) { this->processor_queue_length = size; }

double Monitor::getMeanTimePerTask() { return this->mean_time_per_task; } 

double Monitor::getProcessorOcupation() { return this->processor_ocupation; } 

int Monitor::getDelta() { return this->delta; }


double Monitor::calculateTimePerTask(double _task_time, int _new_task) {
    this->task_time += _task_time;
    this->total_task += _new_task;

    return (this->task_time) / this->total_task;
}

void Monitor::saveToCsv() {
    std::ofstream csv;
    
    csv.open(this->file_path);
    
    for(size_t i = 0; i < this->logs.size(); ++i) {
        csv << this->logs[i]->getId() << "," 
            << this->logs[i]->getProcessorId() << "," 
            << this->logs[i]->getProcessorState() << "," 
            << this->logs[i]->getProcessorQueueLength() << "," 
            << this->logs[i]->getMeanTimePerTask() << endl;
    }
}

void Monitor::inner_body() {
    while(true) {
        if(this->stop) {
            cout << "Passivate Monitor" << endl;
            passivate();
        }

        hold(this->delta);

        if((*proc)->getTaskQueue().size() != 0) {
            int log_id = this->logs.size();
            double pql = (*proc)->getTaskQueue().size();
            double mtpt = this->calculateTimePerTask((*proc)->getTask()->getTimeService(), 1);

            Log *l = new Log(log_id, (*proc)->getId(), (*proc)->getState(), pql, mtpt);
            this->logs.push_back(l);

            /* Logs on terminal */
            // l->show();

        }
    }
}