#include "processor.hpp"

Processor::Processor(string n) {
    this->name = n;
}

void Processor::sendName() {
    cout << "sendName: " << this->name << endl;
}