#ifndef TASK_H
#define TASK_H

#include<iostream>

using namespace std;

class Task  {
    private:
        int chance;
        string type;
        double time_service;

    public:
        Task(int _chance);

        int getChance();
        string getType();
        double getTimeService();
};

#endif