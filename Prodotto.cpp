//
// Created by alberto on 16/03/23.
//

#include "Prodotto.h"

Prodotto::Prodotto(const std::string &nome, const std::string &categoria, int quantita):
        nome(nome), categoria(categoria), quantita(quantita) {}

const std::string &Prodotto::getNome() const {
    return nome;
}

int Prodotto::getQuantita() const {
    return quantita;
}

void Prodotto::setQuantita(int quantita) {
    Prodotto::quantita = quantita;
}

Prodotto::~Prodotto() {

}