#include "log.hpp"

Log::Log(int _id, int proc_id, bool proc_state, int pql, int mtpt) {
    this->id = _id;
    this->processor_id = proc_id;
    this->processor_state = proc_state;
    this->processor_queue_length = pql;
    this->mean_time_per_task = mtpt;
}

int Log::getId() { return this->id; }
int Log::getProcessorId() { return  this->processor_id; }
bool Log::getProcessorState() { return this->processor_state; }
int Log::getProcessorQueueLength() { return this->processor_queue_length; }
int Log::getMeanTimePerTask() { return this->mean_time_per_task; }

void Log::show() {
    cout << "Log: " << endl;
    cout << "   - id: " << this->id << endl;
    cout << "   - processor_id: " << this->processor_id << endl;
    cout << "   - processor_state: " << this->processor_state << endl;
    cout << "   - processor_queue_length: " << this->processor_queue_length << endl;
    cout << "   - mean_time_per_task: " << this->mean_time_per_task << endl;
    cout << "-------------------------------------------" << endl;
}