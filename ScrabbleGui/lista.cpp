#include "lista.h"
using namespace std;
template<class T>
Lista<T>::Lista()
{
    n_num_nodos = 0;
    m_head = NULL;
}

template<class T>
void Lista<T>::add(T* data_){
    Nodo<T> *nodo = new Nodo<T> (data_);
    Nodo<T> *temp = m_head;
    if(!m_head){
        m_head = nodo;
    }else{
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nodo;
    }
    n_num_nodos++;
}
