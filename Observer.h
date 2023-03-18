//
// Created by alberto on 16/03/23.
//

#ifndef LABPROGAG_OBSERVER_H
#define LABPROGAG_OBSERVER_H

class ListaSpesa;

// create design pattern Observer
class Observer {
public:

    //metodo per aggiornare la lista
    virtual void update(ListaSpesa* l) = 0;

};

#endif //LABPROGAG_OBSERVER_H
