//
// Created by alberto on 16/03/23.
//

#include "Prodotto.h"

//costruttore del prodotto

Prodotto::Prodotto(const std::string nome, int quantita) {
    Prodotto::nome = nome;
    Prodotto::quantita = quantita;
}

//metodo per ottenere il nome del prodotto
const std::string Prodotto::getNome() const {
    return nome;
}

//metodo per ottenere la quantità del prodotto
int Prodotto::getQuantita() const {
    return quantita;
}

//metodo per modificare la quantità del prodotto
void Prodotto::setQuantita(int quantita) {
    Prodotto::quantita = quantita;
}

//distruttore del prodotto
Prodotto::~Prodotto() {
    std::cout << "Prodotto " << nome << " distrutto" << std::endl;
}
