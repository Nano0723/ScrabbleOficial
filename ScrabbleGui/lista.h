#ifndef LISTA_H
#define LISTA_H
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
 
#include "nodo.h"
#include "nodo.cpp"
 
using namespace std;

template<class T>

class Lista
{
public:
    Lista();
    ~Lista();
    void add(T* data_);
private:
    Nodo<T> *m_head;
    int n_num_nodos;
};

#endif // LISTA_H
