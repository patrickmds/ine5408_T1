#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include <cstring>
#include "Cashier.h"
#include "CircularList.h"

namespace supermarket {

class Supermarket
{

 public:
    Supermarket(char name[],
                int averageClientArrival,
                int simulationTime);
    void simulate();
    void addCashier(char name[], int efficiency, int salary);

 private:
    CircularList<Cashier> cashiers_;
    int simulationTime_;
    int averageClientArrival_;
    char name_[50];
    int clock_ {0};
    int lostClients_ {0};
    double lostMoney_ {0};
};

}  /* namespace supermarket */

#endif
