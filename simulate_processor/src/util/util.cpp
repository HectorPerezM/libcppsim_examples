#include "util.hpp"

Util::Util(string n) {
    this->name = n;
}

void Util::sendName() {
    cout << "sendName: " << this->name << endl;
}