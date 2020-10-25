
#include <iostream>
#include "util/util.hpp"
#include "processor/processor.hpp"
#include "taskGenerator/taskGenerator.hpp"
#include "monitor/monitor.hpp"
#include "../../libcppsim-0.2.5/src/cppsim.hh"

using namespace std;

class System: public process {
    private:
        string name;
        handle<Processor> processor;
        handle<TaskGenerator> task_generator;
        handle<Monitor> monitor;
        double total_time;
        
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

    /* Creates the processor */
    this->processor = new Processor("1", 1);

    /* Assing a processor to this task generator */
    this->task_generator->setProcessor(&this->processor);

    /* Monitor */
    this->monitor = new Monitor("Monitor", &this->processor, 4, "monitor_data.csv");
    this->monitor->activate();

    /* Activates the processor */
    // this->processor->activate();
    

    cout << "Start simulation." << endl;
    //Simulation will run for 5 seconds.
    hold(700);
    cout << "End simulation." << endl;

    /* Deactivates monitor */
    this->monitor->stop = true;
    /* Save data */
    this->monitor->saveToCsv();

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
