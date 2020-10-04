#ifndef PROCESSOR_H
#define PROCESSOR_H

#include<iostream>
using namespace std;

class Processor {
    private:
        string name;
    public:
        Processor(string n);

        void sendName();

};

#endif