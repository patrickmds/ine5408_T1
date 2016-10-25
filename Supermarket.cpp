#include "Supermarket.h"

namespace supermarket {

    Supermarket::Supermarket(std::string name,
                             int averageClientArrival,
                             int simulationTime):
        averageClientArrival_{averageClientArrival},
        simulationTime_{simulationTime*3600}
    {
        name_ = name;
    }

    void Supermarket::addCashier(std::string name, int efficiency, int salary) {
        //auto cashier = Cashier(name, efficiency, salary);
        //Cashier newCashier{name, efficiency, salary};
        //cashiers_.push_front(cashier);
    }

    void Supermarket::addCashier(Cashier c){
        cashiers_.push_front(c);
    }

    void Supermarket::printCashiers(){
        for(int i = 0; i < cashiers_.size(); ++i){
            cashiers_.at(i).print();
        }
    }

    int Supermarket::currentClock(){
        return clock_;
    }

    void Supermarket::currentClock(int value){
        clock_ = value;
    }

    int Supermarket::totalClock(){
        return simulationTime_;
    }

} /* namespace supermarket */
