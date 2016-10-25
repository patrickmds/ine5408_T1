#include "Cashier.h"

namespace supermarket {

    Cashier::Cashier(std::string name, int efficiency, int salary)
    {
        name_ = name;
        salary_ = salary;
        efficiency_ = efficiency;
    }

    Cashier::Cashier()
    {
        name_ = "Nome";
        salary_ = 0;
        efficiency_ = 1;
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

    void Cashier::checkClientExit(int time){
        if(clients.empty())
            return;
        else if(time == clients.front().exitTime()){
            ++totalClients_;
            totalIncome_ += clients.front().totalSpentMoney();
            // TO DO calcular tempo medio da fila
            clients.dequeue();
        }
    }

    void Cashier::print(){
	std::cout << "Name: " << name_ << " - Efficiency: " << efficiency_ << " - Salary: " << salary_ << " \n";
    }

} /* namespace supermarket */
