//
// Created by alberto on 16/03/23.
//

#include "Utente.h"
#include <iostream>
#include "ListaSpesa.h"

//implementazione del costruttore dell'utente
Utente::Utente(const std::string &nomeUtente): nomeUtente(nomeUtente) {}

//implementazione del metodo per ottenere il nome dell'utente
const std::string Utente::getNomeUtente() const {
    return nomeUtente;
}

//implementazione del metodo per ottenere la lista delle liste
const std::list<ListaSpesa *> Utente::getListaSpesa() const {
    return liste;
}

//implementazione del metodo addListaSpesa
void Utente::addListaSpesa(ListaSpesa *l) {
    liste.push_back(l);
    l->attach(this);
}

//implementazione del metodo removeListaSpesa
void Utente::removeListaSpesa(ListaSpesa *l) {
    l->detach(this);
    liste.remove(l);
}

//implementazione del metodo update
void Utente::update(ListaSpesa *l) {
    if(l->isCompletata()) {
        this->removeListaSpesa(l);
        std::cout << "REMOVE " << this->nomeUtente << "  " << l->getNomeLista() << std::endl;
    }
    else{
        std::cout << "La lista " << l->getNomeLista() << "è stata modificata" << std::endl;
    }
}

//implementazione del distruttore dell'utente
Utente::~Utente() {
}

void Utente::listsState() {
    //quante liste devono essere completate
    int listToComplete = 0;
    for(auto it = liste.begin(); it != liste.end(); it++){
        if(!(*it)->isCompletata()){
            listToComplete++;
        }
        (*it)->showListState();
    }
    std::cout << "Lista da completare: " << listToComplete << std::endl;
}

