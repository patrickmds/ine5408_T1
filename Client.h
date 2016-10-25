#ifndef CLIENT_H
#define CLIENT_H

#include <ctime>
#include <cstdlib>

namespace supermarket {

class Client
{

 public:
    Client() = default;
    Client(int atime);
    void exitTime(int value);
    int exitTime();
    int totalSpentMoney();

 private:
    bool smart_;
    bool money_;
    int items_ {};
    int value_ {};
    int arrivalTime_ {};
    int exitTime_;
};

}  /* namespace supermarket */

#endif
