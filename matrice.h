//
// Created by crist on 4/21/2020.
//

#ifndef TEMA2_MATRICE_H
#define TEMA2_MATRICE_H

#include "vector.h"

class matrice {
protected:
    vector *v;
public:
    matrice();
    matrice(int col);
    matrice(const matrice &other);
    ~matrice();
    virtual int f() = 0;
};

class matrice_oarecare: public matrice
{
private:
    int linii;
public:
    matrice_oarecare();
    matrice_oarecare(int l);
    matrice_oarecare(const matrice_oarecare &other);
    ~matrice_oarecare();
    int f();
    friend std::istream & operator >> (std::istream &in, matrice_oarecare &m);
    friend std::ostream & operator << (std::ostream &out, matrice_oarecare &m);
    matrice_oarecare& operator =(const matrice_oarecare &other);
};

class matrice_patratica: public matrice
{
private:
    int dim;
public:
    matrice_patratica();
    matrice_patratica(int dim);
    matrice_patratica(const matrice_patratica &other);
    ~matrice_patratica();
    int f();
    friend std::istream & operator >> (std::istream &in, matrice_patratica &m);
    friend std::ostream & operator << (std::ostream &out, matrice_patratica &m);
    matrice_patratica& operator =(const matrice_patratica &other);
    int** transformare();
    int determinant(int dim, int** m);
};


#endif //TEMA2_MATRICE_H
