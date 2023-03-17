//
// Created by alberto on 16/03/23.
//

#ifndef LABPROGAG_UTENTE_H
#define LABPROGAG_UTENTE_H
#include <iostream>
#include <list>
#include "ListaSpesa.h"
#include "Observer.h"


class Utente: public Observer{
public:

    //costruttore dell'utente
    explicit Utente(const std::string &nomeUtente);

    //metodo per aggiungere una lista alla lista delle liste
    void addListaSpesa(ListaSpesa *l);

    //metodo per rimuovere una lista dalla lista delle liste
    void removeListaSpesa(ListaSpesa *l);

    //funzione update per l'observer
    void update(ListaSpesa* l) override;

private:
    std::string nomeUtente;
    std::list<ListaSpesa*> liste;
};


#endif //LABPROGAG_UTENTE_H
