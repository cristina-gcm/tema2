//
// Created by crist on 4/20/2020.
//

#ifndef TEMA2_VECTOR_H
#define TEMA2_VECTOR_H

#include <iostream>

class vector {
protected:
    int dim;
    int *a;

public:
    vector();
    vector(int);
    vector(const vector&);
    ~vector();
    friend std::istream & operator >> (std::istream &in, vector &v);
    friend std::ostream & operator << (std::ostream &out, vector &v);
    int get_size()
    {return dim;}
    int get_elem(int i)
    { return a[i];}
    int *get_vec()
    { int *v = new int[dim];
    for (int i=0;i<dim;i++)
        v[i]=a[i];
     return v;
    }
    void set_size(int i)
    {dim = i;
    a = new int[dim];}
    void set_vec(int *v)
    {
        for (int i=0;i<dim;i++)
            a[i]=v[i];
    }
    vector& operator =(const vector &other);
};


#endif //TEMA2_VECTOR_H
