#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include <string>
#include <cstring>
#include "Cashier.h"
#include "CircularList.h"

namespace supermarket {

class Supermarket
{

 public:
    Supermarket(std::string name,
                int averageClientArrival,
                int simulationTime);
    void addCashier(std::string name, int efficiency, int salary);
    void addCashier(Cashier c);
    void printCashiers();


 private:
    CircularList<Cashier> cashiers_;
    int simulationTime_;
    int averageClientArrival_;
    std::string name_;
    int clock_ {0};
    int lostClients_ {0};
    double lostMoney_ {0};
};

}  /* namespace supermarket */

#endif
