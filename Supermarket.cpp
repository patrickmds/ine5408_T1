#include "Supermarket.h"

namespace supermarket {

    Supermarket::Supermarket(char name[],
                             int averageClientArrival,
                             int simulationTime):
        averageClientArrival_{averageClientArrival},
        simulationTime_{simulationTime*3600}
    {
        strcpy(name_, name);
    }

    void Supermarket::simulate()
    {
        while(simulationTime_ > 0) {
            simulationTime_--;
        }
    }

    void Supermarket::addCashier(char name[], int efficiency, int salary) {
        //auto cashier = Cashier(name, efficiency, salary);
        //Cashier newCashier{name, efficiency, salary};
        //cashiers_.push_front(cashier);
    }

    void Supermarket::addCashier(Cashier c){
        c.print();
    }

    void Supermarket::printCashiers(){
        //for(int i = 0; i < cashiers_.size(); ++i){
            //cashiers_.at(i).print();
        //}
    }

} /* namespace supermarket */
