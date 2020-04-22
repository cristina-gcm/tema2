//
// Created by crist on 4/20/2020.
//

#include "vector.h"
#include <iostream>

vector::vector()
{
    dim=0;
    a=new int[0];
    //std::cout<<"constr\n";
}
vector::vector(int i)
{
    dim=i;
    a=new int[i];
    std::cout<<"constr param\n";
}
vector::vector(const vector& other)
{
            this->dim = other.dim;
            this->a = new int[other.dim];
        for (int i=0;i<this->get_size();i++)
            this->a[i] = other.a[i];
    std::cout<<"cpy\n";
}

std::istream &operator>> (std::istream &in, vector &v)
{

    in >> v.dim;
    v.a = new int[v.dim];
    for (int i=0; i<v.get_size();i++)
        in >> v.a[i];
    return in;
}
std::ostream &operator<< (std::ostream &out, vector &v)
{   out <<"dimensiunea - " << v.dim <<"; elementele - ";
    for (int i=0; i<v.get_size();i++)
        out << v.a[i] << ' ';
    return out;
}
vector::~vector()
{
    delete[] a;
    std::cout<<"l am ucis\n";
}

vector &vector::operator=( const vector &other) {
    if (this!=&other)
    {if (this->dim != other.dim)
        {delete[] this->a;
        this->a = nullptr;
        this->dim=0;
        this->dim = other.dim;
        this->a = new int[other.dim];}
        for (int i=0;i<this->dim;i++)
        this->a[i] = other.a[i];}
    return *this;

}
