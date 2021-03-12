#include <stdlib.h>

#include <ctime>
#include <iostream>
#include <string>

#include "snowman.hpp"

const int SM_BUILDER_LENGTH = 8;

int main() {
    srand(time(0));
    for (size_t i = 0; i < 10; i++) {
        int sm = rand() % 4 + 1;
        for (size_t i = 1; i < SM_BUILDER_LENGTH; i++) {
            sm *= 10;
            sm += rand() % 4 + 1;
        }
        cout << sm << ariel::snowman(sm) << endl << endl;
    }
    return 0;
}