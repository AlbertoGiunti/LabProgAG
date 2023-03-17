//
// Created by alberto on 16/03/23.
//

#include "Utente.h"
#include <iostream>
#include "ListaSpesa.h"

//implementazione del costruttore dell'utente
Utente::Utente(const std::string &nomeUtente) {

}

//implementazione del metodo addListaSpesa
void Utente::addListaSpesa(ListaSpesa *l) {
    liste.push_back(l);
    l->attach(this);
}

//implementazione del metodo removeListaSpesa
void Utente::removeListaSpesa(ListaSpesa *l) {
    liste.remove(l);
}

//implementazione del metodo update
void Utente::update(ListaSpesa *l) {
    this->removeListaSpesa(l);
}

