#ifndef CLIENT_H
#define CLIENT_H

//#include <string>

namespace supermarket {

class Client
{

 public:
    Client(int atime);
    bool smart();
    bool money();
    int items();
    int value();
    int arrivalTime();

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
