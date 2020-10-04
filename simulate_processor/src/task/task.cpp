#include "task.hpp"

Task::Task(int _chance) {
    this->chance = _chance;
    
    /* Create task with it's own characteristics */
    if (0 <= this->chance && this->chance <= 33) {
        this->type = "A";
        this->time_service = 1;
    } else if (34 <= this->chance && this->chance <= 66) {
        this->type = "B";
        this->time_service = 5;
    } else {
        this->type = "C";
        this->time_service = 8;
    }
}

int Task::getChance() { return this->chance; }
string Task::getType() { return this->type; }
double Task::getTimeService() { return this->time_service; }