#ifndef CASHIER_H
#define CASHIER_H

#include <string>

namespace supermarket {

using std::string;

class Cashier{

 public:
    Cashier::Cashier(const string &name, int efficiency, int salary);
 private:
    linkedQueue<Client> clientsQueue;
    const string name_;
    int efficiency_;
    int salary_;
    int totalClients_ {0};
    int totalTimeInQueue_ {0};
    double totalIncome_ {0};
}

}
