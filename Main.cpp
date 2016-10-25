#include <iostream>
#include <cstdint>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "Cashier.h"
#include "Supermarket.h"

int main(int argc, char **argv)
{
    char readline[50];
    // Supermarket infos
    char smName[50];
    int smSimulationTime, smClientArrival, smCashiersNum;
    // Cashier infos
    char cName[50];
    int cEffi, cSal;
    

    std::ifstream file("file.dat");

    file.getline(readline, 50);
    strcpy(smName, readline);
    file.getline(readline, 50);
    smSimulationTime = atoi(readline);
    file.getline(readline, 50);
    smClientArrival = atoi(readline);
    file.getline(readline, 50);
    smCashiersNum = atoi(readline);

    printf("Nome: %s, Simu: %d, Client: %d\n", smName, smSimulationTime, smClientArrival);

    auto superm = supermarket::Supermarket(smName, smSimulationTime, smClientArrival);

    for(int i = 0; i < smCashiersNum; ++i){
        file.getline(readline, 50);
        strcpy(cName, readline);
        file.getline(readline, 50);
        cEffi = atoi(readline);
        file.getline(readline, 50);
        cSal = atoi(readline);
        //superm.addCashier(cName, cEffi, cSal);
        //auto cashier = supermarket::Cashier(cName, cEffi, cSal);
        
    }

    //superm.printCashiers();

    return 0;
}
