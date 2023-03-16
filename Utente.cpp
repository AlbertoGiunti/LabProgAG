//
// Created by alberto on 16/03/23.
//

#include "Utente.h"
#include <iostream>
#include <list>
#include "ListaSpesa.h"

Utente::Utente(const std::string &nomeUtente) {

}

void Utente::addListaSpesa(ListaSpesa *l) {
    liste.push_back(l);
}
