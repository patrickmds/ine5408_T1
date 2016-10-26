#include <iostream>
#include <cstdint>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "Cashier.h"
#include "Supermarket.h"

int main(int argc, char **argv)
{
    std::string readline;
    // Supermarket infos
    std::string smName;
    int smSimulationTime, smClientArrival, smCashiersNum;
    // Cashier infos
    std::string cName;
    int cEffi, cSal;


    std::ifstream file("file.dat");
    if(!file.is_open()){
        printf("DEU RUIM\n");
        return 1;
    }


    std::getline(file, smName);
    std::getline(file, readline);
    smSimulationTime = stoi(readline);
    std::getline(file, readline);
    smClientArrival = stoi(readline);
    std::getline(file, readline);
    smCashiersNum = stoi(readline);

    std::cout << "Nome supermercado: " << smName << " - Simulacao Tempo: " << smSimulationTime << " - Clientes: " << smClientArrival << " \n";

    auto superm = supermarket::Supermarket(smName, smSimulationTime, smClientArrival);

    //supermarket::Cashier *ptrCashier;
    //ptrCashier = new supermarket::Cashier[smCashiersNum];

    for(int i = 0; i < smCashiersNum; ++i){
        std::getline(file, cName);
        std::getline(file, readline);
        cEffi = stoi(readline);
        std::getline(file, readline);
        cSal = stoi(readline);

        supermarket::Cashier c(cName, cEffi, cSal);
        //ptrCashier[i] = c;
        superm.addCashier(c);

    }

    superm.printCashiers();
    int clientArrivalAux = 0;
    int auxcounter = 0;
    // Simulation start
    while(superm.currentClock() < superm.totalClock()){
        // Client In
        if(clientArrivalAux == smClientArrival-1){
            // Create Client
            superm.cashiers_.at(0).addClient(supermarket::Client(superm.currentClock()));
            ++auxcounter;
            clientArrivalAux = 0;
        }else{
            ++clientArrivalAux;
        }

        // Client Out
        for(int i = 0; i < superm.cashiers_.size(); ++i){
            superm.cashiers_.at(i).checkClientExit(superm.currentClock());
        }


        superm.currentClock(superm.currentClock()+1);
    }

    std::cout << "Total clients atendidos: " << superm.cashiers_.at(0).totalClients_ << "\n";
    std::cout << "Total clients recebidos: " << auxcounter << "\n";

    return 0;
}
