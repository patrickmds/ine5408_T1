#include "Cashier.h"

namespace supermarket {

using namespace std;

    Cashier::Cashier(const string &name, int efficiency, int salary):
        name_{name},
        efficiency_{efficiency},
        salary_{salary}
    {}

    void Cashier::update()
    {
        // diminui um segundo do tempo TODO
    }

} /* namespace supermarket */
