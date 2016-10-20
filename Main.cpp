#include <iostream>
#include <cstdint>
#include <stdexcept>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc, char **argv)
{
    char readline[50];

    ifstream file("file.dat");

    file.getline(readline, 50);
    printf("LIDO: %s\n", readline);

    return 0;
}
