

#include <iostream>
#include <vector>
#include "vector.h"
#include "matrice.h"
using namespace std;

int main()
{
    /*
    vector v; // ctr fara param
    vector v1(5); // ctr cu param
    cout<<v1.get_size()<<endl;
    cout<<"Introduceti datele pentru vector - dimensiunea, apoi elementele: "; cin >> v1;
    cout << endl <<"Vectorul este: "; cout << v1;
    vector v3(v1); // ctr de copiere
    vector v2;
    v2=v1; // supraincarcarea operatorului "=" pt vector
    cout <<"Vectorul este: " << v2;*/

    /*matrice_oarecare m1;
    cout<<"Introduceti matricea - dimensiunea, apoi elem: "; cin >> m1;
    cout<<"Matricea este: \n"; cout<<m1;

    matrice_oarecare m2;
    m2=m1;
    cout<<"Matricea 2 este\n" << m2;
    if (m2.f()==1)
        cout<<"Matricea este trunghiulara\n";
    else
        cout<<"Matricea nu este triunghiulara\n";*/

    //matrice_patratica m3, m4, m5;
    //cout<<"Introduceti matricea patratica - dimensiunea, apoi elem: ";cin>>m3;
    //cout<<"Matricea este: \n"; cout<<m3;
    //m4=m3;
    //cout<<m4;
    //cin>>m5;
    //cout<<m5;

    int n;
    cout<<"Numarul de matrice oarecare este:";
    cin>>n;
    matrice_oarecare m1;

    std::vector <matrice_oarecare> mo;

    while (n)
    {
        cin>>m1;
        mo.push_back(m1);
        n--;
    }

    for (int i=0;i<mo.size();i++)
    {   cout<<"Matrice oarecare "<<i<<endl;
        cout<<mo[i]<<endl;
        if (mo[i].f()==1)
            cout<<"Matricea "<<i<<" este triunghiulara"<<endl;
        else
            cout<<"Matricea "<<i<<" nu este triunghiulara"<<endl;
    }

    cout<<"Numarul de matrice patratice este:";
    cin>>n;
    std::vector <matrice_patratica> mp;
    matrice_patratica m2;
    while (n)
    {
        cin>>m2;
        mp.push_back(m2);
        n--;
    }

    for (int i=0;i<mp.size();i++)
    {   cout<<"Matrice patratica "<<i<<endl;
        cout<<mp[i]<<endl;
    }
}

