//#include "Cashier.h"
#include "Client.h"
#include <time.h>
#include <stdlib.h>

namespace supermarket {

using namespace std;

    Client::Client(int atime):
        smart_{rand()%2 != 0},
        items_{rand()%99 + 2},
        arrivalTime_{atime}
    {
        srand(time(NULL));

        money_ = (rand()%101 > 80)?true:false;

        value_ = 0;
        for (int i = 0; i < items_; ++i) {
            value_ += rand()%90 + 1;
        }
    }

} /* namespace supermarket */
