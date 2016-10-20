#include "Cashier.h"
#include <string>
#include <cstring>

namespace supermarket {

using namespace std;

    Cashier::Cashier(char name[], int efficiency, int salary)
    {
        strcpy(name_, name);
        salary_ = salary;
        efficiency_ = efficiency;
    }

    /*void Cashier::update()
    {
        // diminui um segundo do tempo TODO
    }*/

} /* namespace supermarket */
