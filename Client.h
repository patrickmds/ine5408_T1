#ifndef CLIENT_H
#define CLIENT_H

#include <string>

namespace supermarket {

class Client
{

 public:
    Client();
    bool smart();
    bool creditCard();
    int items();
    int value();
    int arrivalTime();

 private:
    bool smart_;
    bool creditCard_;
    int items_ {};
    int value_ {};
    int arrivalTime_ {};
};

}  /* namespace supermarket */

#endif
