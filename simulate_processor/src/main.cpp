
#include <iostream>
#include "util/util.hpp"
#include "../../libcppsim-0.2.5/src/cppsim.hh"

using namespace std;

class System: public process {
    private:
        string name;
        
    public:
        System(string _name) : process(_name) {
            name = _name;
        }
    
    protected:
        void inner_body(void);

};

void System::inner_body(void) {
    cout << "Inner_body System" << endl;
    cout << this->name << endl;
}

int main(void)
{
    cout << "Main ... " << endl;
    Util util("THIS IS A TEST");

    util.sendName();

    
    
    /*
        Se crea una instancia de la simulacion
        se inicia la simulación, 
        con un nuevo (sequencing set) sqsPrio (balanced search trees)
    */
    simulation::instance()->begin_simulation(new sqsPrio());


    handle<System> sys( new System("TEST"));
    sys->activate();

    simulation::instance()->run();
    simulation::instance()->end_simulation();
}
