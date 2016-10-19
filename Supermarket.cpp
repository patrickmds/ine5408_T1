#include "Cashier.h"
#include "Supermarket.h"

namespace supermarket {

using namespace std;

    Supermarket::Supermarket(const std::string &name,
                             int averageClientArrival,
                             int simulationTime):
        name_{name},
        averageClientArrival_{averageClientArrival},
        simulationTime_{simulationTime}
    {}

    void simulate()
    {
        while(simulationTime_ > 0) {
            simulationTime_--;
        }
    }

    void addCashier(const string &name, int efficiency, int salary) {
        Cashier newCashier{name, efficiency, salary};
        cashiers_.push(newCashier);
    }

} /* namespace supermarket */
