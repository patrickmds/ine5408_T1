#include "Cashier.h"
#include <string>
#include <cstring>

namespace supermarket {

    Cashier::Cashier(char name[], int efficiency, int salary)
    {
        strcpy(name_, name);
        salary_ = salary;
        efficiency_ = efficiency;
    }

    Cashier::Cashier()
    {
    }

    void Cashier::process(int money)
    {
        if(!money){
            switch(efficiency_){
                case 1:
                    totalTimeInQueue_ += 10;
                    break;
                case 2:
                    totalTimeInQueue_ += 25;
                    break;
                case 3:
                    totalTimeInQueue_ += 60;
                    break;
            }
        }
    }

    int Cashier::queueTime()
    {
        return totalTimeInQueue_;
    }

} /* namespace supermarket */
