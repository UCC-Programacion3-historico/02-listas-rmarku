#ifndef CIRCLIST_H
#define CIRCLIST_H

#include "../Lista/Nodo.h"


class CircList {
private:
    Nodo<T> *puntero;

public:
    CircList();

    CircList(const CircList<T> &li);

    ~CircList();

    bool esVacia();

    int getTamanio();

    void insertar(T dato);

    void remover();

    void avanzar();

    T getDato();

    void reemplazar(T dato);

    void vaciar();
};


CircList::CircList() {
    puntero = NULL;
}

CircList::~CircList() {
    vaciar();
}

bool CircList::esVacia() {
    return puntero == NULL;
}

void CircList::insertar(T dato) {
    if (NULL == puntero) {
        puntero = new Nodo(dato);
        puntero->setNext(puntero);
        return;
    }

    // puntero->setNext(new Nodo(dato, puntero->getNext()));
    Nodo *tmp = new Nodo(dato, puntero->getNext());
    puntero->setNext(tmp);
    puntero = puntero->getNext();
}

void CircList::avanzar() {
    if (puntero != NULL)
        puntero = puntero->getNext();
}

void CircList::remover() {
    Nodo *aux = puntero;

    if (NULL == puntero)
        return;

    while (aux->getNext() != puntero) {
        aux = aux->getNext();
    }

    if (aux == puntero) {
        delete puntero;
        puntero = NULL;
        return;
    }

    aux->setNext(puntero->getNext());
    delete puntero;
    puntero = aux->getNext();
}

T CircList::getDato() {
    if (puntero == NULL)
        throw 1;

    return puntero->getDato();
}

int CircList::getTamanio() {
    Nodo *aux = puntero;
    int tamanio = 1;

    if (NULL == puntero)
        return 0;

    while (aux->getNext() != puntero) {
        tamanio++;
        aux = aux->getNext();
    }
    return tamanio;
}


void CircList::reemplazar(T dato) {
    if (puntero == NULL)
        throw 1;

    return puntero->setDato(dato);
}

void CircList::vaciar() {
    while (!esVacia()) {
        remover();
    }
}

#endif //CIRCLIST_H
