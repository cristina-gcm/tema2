//
// Created by crist on 4/22/2020.
//

#ifndef TEMA2_DIMENSIUNE_H
#define TEMA2_DIMENSIUNE_H
#include <iostream>
using namespace std;

class dimensiune: public exception {
public: const char* what() {
        return "Dimensiunea trebuie sa fie numar intreg pozitiv\n";
    }
};


#endif //TEMA2_DIMENSIUNE_H
