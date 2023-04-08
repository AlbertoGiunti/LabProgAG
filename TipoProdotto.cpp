//
// Created by alberto on 08/04/23.
//

#include "TipoProdotto.h"
#include <iostream>

//costruttore del tipo di prodotto che controlla che il nome sia diverso da una stringa vuota
TipoProdotto::TipoProdotto(const std::string n)  {
    if(!n.empty()){
        nome = n;
    }
    else{
        throw std::runtime_error("Nome non valido");
    }
}

//metodo per ottenere il nome del tipo di prodotto
const std::string TipoProdotto::getNome() const {
    return nome;
}
