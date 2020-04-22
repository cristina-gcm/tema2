//
// Created by crist on 4/21/2020.
//

#include "matrice.h"
#include <math.h>
#include "dimensiune.h"

matrice::matrice()
{
    v = new vector();
    std::cout<<"ctr fara param matrice 1\n";
}

matrice::matrice(int col)
{
    v = new vector[col];
    std::cout<<"ctr cu param matrice 1\n";
}

matrice::matrice(const matrice &other)
{
    this->v = new vector(*other.v);
    std::cout<<"ctr de copiere matrice1\n";
}

matrice::~matrice()
{
    delete[] v;
}

matrice_oarecare::matrice_oarecare():matrice()
{
    linii=0;
}

matrice_oarecare::matrice_oarecare(int l)
{
    linii=l;
    v = new vector[l];
}

matrice_oarecare::matrice_oarecare(const matrice_oarecare &other)
{
    this->linii = other.linii;
    v = new vector[other.linii];
    for (int i=0;i<other.linii;i++)
    {v[i] = other.v[i];}
}
matrice_oarecare &matrice_oarecare:: operator =(const matrice_oarecare &other)
{
    if (v!= nullptr)
        for (int i=0;i<linii;i++)
            delete[] &v[i];
    this->linii = other.linii;

    v = new vector[other.linii];
    for (int i=0;i<other.linii;i++)
    {v[i] = other.v[i];}
    return *this;
}
std::istream & operator >> (std::istream &in, matrice_oarecare &m)
{
    cout<<"Numarul de linii este: ";
    in >> m.linii;
    m.v = new vector[m.linii];
    cout<<"Elementele sunt: ";
    for (int i=0; i<m.linii;i++)
    {   cout<<"Nr de elemente de pe linie, apoi valorile - ";
        in >> m.v[i];
    }
    return in;
}
std::ostream & operator << (std::ostream &out, matrice_oarecare &m)
{
    out << "Nr de linii este "<<m.linii<<"\n";
    for (int i=0;i<m.linii;i++)
    {
        out<<m.v[i]<<"\n";
    }
    return out;
}
int matrice_oarecare:: f()
{
    int i=1;
    int ok=1;
    if (!(v[0].get_size() == 1 || v[linii-1].get_size() == 1))
        return 0;
    while (i<linii && ok)
    {
        if (abs(v[i].get_size() - v[i-1].get_size()) == 1)
            i++;
        else
            ok=0;
    }
    return ok;
}
matrice_oarecare::~matrice_oarecare()
{ std::cout<<"Matrice oarecare stearsa\n";}

matrice_patratica::matrice_patratica():matrice()
{
    dim=0;
}

matrice_patratica::matrice_patratica(int d)
{
    dim=d;
    v = new vector[d];
}

matrice_patratica::matrice_patratica(const matrice_patratica &other)
{
    this->dim = other.dim;
    v = new vector[other.dim];
    for (int i=0;i<other.dim;i++)
    {v[i] = other.v[i];}
}
matrice_patratica::~matrice_patratica()
{ std::cout<<"Matrice patratica stearsa\n";}

std::istream & operator >> (std::istream &in, matrice_patratica &m)
{   try {
    cout<<"Dimensiunea matricei este:";
    in >> m.dim;
    if (m.dim <= 0)
        throw dimensiune();}
    catch(dimensiune e) {
        cout<<e.what();
        in >> m.dim;
        while (m.dim <= 0)
            in >> m.dim;
    }

    m.v = new vector[m.dim];
    for (int i=0; i<m.dim;i++)
    {   int *n = new int[m.dim];
        cout<<"Elementele:";
        m.v[i].set_size(m.dim);
        for (int j=0;j<m.dim;j++)
        {
            in >> n[j];
        }
        m.v[i].set_vec(n);
    }
    return in;
}
std::ostream & operator << (std::ostream &out, matrice_patratica &m)
{
    out << "Nr de linii este "<<m.dim<<"\n";
    for (int i=0;i<m.dim;i++)
    {
        out<<m.v[i]<<"\n";
    }
    int det = m.f();
    out << "Determinantul matricei este:" << det << "\n";
    return out;

}
matrice_patratica &matrice_patratica:: operator =(const matrice_patratica &other)
{
    if (v!= nullptr)
        for (int i=0;i<dim;i++)
            delete[] &v[i];
    this->dim = other.dim;

    v = new vector[other.dim];
    for (int i=0;i<other.dim;i++)
    {v[i] = other.v[i];}
    return *this;
}
int matrice_patratica::f()
{
    return determinant(this->dim, this->transformare());
}

int** matrice_patratica::transformare()
{   int **A;
    A = new int*[this->dim];
    for (int i=0;i<this->dim;i++)
        A[i] = new int[this->dim];
    for (int i=0;i<this->dim;i++)
        for (int j=0;j<this->dim;j++)
            A[i][j] = this->v[i].get_elem(j);
     return A;
}
int matrice_patratica::determinant(int dim, int **m) {
    int det = 0;
    if (dim == 2) {
        return m[0][0] * m[1][1] - m[0][1] * m[1][0];
    }
    for (int i = 0; i < dim; i++) {
        int x = 0, y = 0;
        int **B;
        B = new int *[dim - 1];
        for (int j = 0; j < dim - 1; j++)
            B[j] = new int[dim - 1];
        for (int j = 0; j < dim; j++)
            for (int k = 0; k < dim; k++)
                if (j != 0 && k != i) {
                    B[x][y] = m[j][k];
                    if (y < dim - 2)
                        y++;
                    else {
                        x++;
                        y = 0;
                    }
                }
        if (i%2==0)
            det = det + m[0][i] * determinant(dim - 1, B);
        else
            det = det - m[0][i] * determinant(dim-1, B);
    }
    return det;
}