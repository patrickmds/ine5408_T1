#ifndef CASHIER_H
#define CASHIER_H

#include <cstring>
#include "Queue.h"
#include "Client.h"

namespace supermarket {

using std::string;

class Cashier{

 public:
    Cashier(char name[], int efficiency, int salary);
    Cashier();
    LinkedQueue<Client> clients;
    int efficiency_;
    int salary_;
    int totalClients_ {0};
    int clientsInQueue_ {0};
    int totalTimeInQueue_ {0};
    double totalIncome_ {0};
    char name_[];
    void process(int money);
    int queueTime();
    void print();
};

}

#endif
