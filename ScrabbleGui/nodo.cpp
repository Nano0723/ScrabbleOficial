#include "nodo.h"
#include <QDebug>

template<class T>
Nodo<T>::Nodo()
{
    data = NULL;
    next = NULL;
}

template<class T>
Nodo<T>::Nodo(T data_){
    data = data_;
    next = NULL;
}
template<class T>
void Nodo<T>::delete_all(){
    if(next){
        next->delete_all();
    }
    delete this;
}
template<class T>
void Nodo<T>::print(){
    qDebug() << data;
}
template<class T>
Nodo<T>::~Nodo(){}
