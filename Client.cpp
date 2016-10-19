#include "Cashier.h"
#include "Client.h"

namespace supermarket {

using namespace std;

    Client::Client():
        smart_{smart()},
        creditCard_{creditCard()},
        items_{items()},
        value_{value()},
        arrivalTime_{arrivalTime()}
    {}

    bool smart()
    {
        int randSmartPercentage = rand()%100;

        return randSmartPercentage < 50;
    }

    bool creditCard()
    {
        int randCCPercentage = rand()%100;

        return randCCPercentage < 80;
    }

    int items()
    {
        int numItems = rand()%100;
        if (numItems < 2) {
            return 2;
        }
        return numItems;
    }

    int value()
    {
        int totalValue = 0;
        for (auto i = 0; i < items_; ++i) {
            totalValue += rand()%90;
        }
        return totalValue;
    }

} /* namespace supermarket */
