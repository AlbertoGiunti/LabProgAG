//
// Created by alberto on 16/03/23.
//

#ifndef LABPROGAG_UTENTE_H
#define LABPROGAG_UTENTE_H
#include <iostream>
#include <list>
#include "ListaSpesa.h"


class Utente {
public:
    explicit Utente(const std::string &nomeUtente);
    //metodo per aggiungere una lista alla lista delle liste
    void addListaSpesa(ListaSpesa *l);



private:
    std::string nomeUtente;
    std::list<ListaSpesa*> liste;
};


#endif //LABPROGAG_UTENTE_H
