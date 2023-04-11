//
// Created by alberto on 16/03/23.
//

#include "Prodotto.h"


//costruttore del prodotto che controlla che il nome sia diverso da una stringa vuota e la quantità sia maggiore di 0
Prodotto::Prodotto(const TipoProdotto &t, int q): tipo(t), quantita(q), comprato(false) {
    if(q > 0){
        quantita = q;
    }
    else{
        throw std::runtime_error("Quantità non valida");
    }
    comprato=false;
}

//metodo per ottenere il tipo del prodotto
const std::string Prodotto::getNomeTipo() const {
    return tipo.getNome();
}


//metodo per ottenere la quantità del prodotto
int Prodotto::getQuantita() const {
    return quantita;
}

//metodo per modificare la quantità del prodotto che accetta solo valori positivi e maggiori di 0
void Prodotto::setQuantita(int q) {
    if(quantita > 0){
        Prodotto::quantita = q;
    }
    else{
        throw std::runtime_error("Quantità non valida");
    }
}

//metodo per verificare se il prodotto è stato comprato
bool Prodotto::isComprato() const {
    return comprato;
}

//metodo per modificare lo stato del prodotto
void Prodotto::setComprato(bool c) {
    Prodotto::comprato = c;
}
