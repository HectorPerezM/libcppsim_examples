
#include <iostream>
#include "util/util.hpp"
#include "processor/processor.hpp"
#include "taskGenerator/taskGenerator.hpp"
#include "../../libcppsim-0.2.5/src/cppsim.hh"

using namespace std;

class System: public process {
    private:
        string name;
        handle<Processor> processor;
        handle<TaskGenerator> task_generator;
        
    public:
        System(string _name) : process(_name) {
            name = _name;
        }
    
    protected:
        void inner_body(void);

};

void System::inner_body(void) {
    cout << "   In System" << endl;

    /* Task Generator */
    this->task_generator = new TaskGenerator("Task Generator", 100, 2.0);
    this->task_generator->activate();

    cout << "Before creating the processor" << endl;
    /* Creates the processor */
    this->processor = new Processor("1", 1);

    /* Assing a processor to this task generator */
    this->task_generator->setProcessor(&this->processor);

    /* Activates the processor */
    this->processor->activate();

    cout << "Start simulation." << endl;
    //Simulation will run for 5 seconds.
    hold(5000000000000000000);
    cout << "End simulation." << endl;


    cout << "Processor service time: " << this->processor->getServiceTime() << endl;

    //Terminates the simulation
    end_simulation();
}

int main(void)
{
    cout << "MAIN " << endl;    
    
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
