#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include <string>

namespace supermarket {

class Supermarket
{

 public:
    Supermarket(const std::string &name,
                int averageClientArrival,
                int simulationTime);
    void simulate();
    void addCashier(const string &name, int efficiency, int salary) {

 private:
    CircularList<Cashier> cashiers_;
    std::string name_;
    int simulationTime_;
    int averageClientArrival_;
    int clock_ {0};
    int lostClients_ {0};
    double lostMoney_ {0};
};

}  /* namespace supermarket */

#endif
