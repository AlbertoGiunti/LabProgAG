//
// Created by alberto on 16/03/23.
//

#include "Utente.h"
#include <iostream>
#include "ListaSpesa.h"

//implementazione del costruttore dell'utente
Utente::Utente(const std::string &nomeUtente): nomeUtente(nomeUtente) {}

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
    l->detach(this);
    this->removeListaSpesa(l);
    std::cout << "REMOVE " << this->nomeUtente << "  " << l->getNomeLista() << std::endl;
}

//implementazione del metodo showListe
void Utente::showListe() {
    std::cout << "Elenco liste" << this->nomeUtente << ":" << std::endl;
    for (auto i = liste.begin(); i != liste.end(); i++) {
        std::cout << (*i)->getNomeLista() << std::endl;
    }
}

//implementazione del distruttore dell'utente
Utente::~Utente() {
}
