//
// Created by alberto on 16/03/23.
//

#ifndef LABPROGAG_PRODOTTO_H
#define LABPROGAG_PRODOTTO_H
#include <iostream>
#include "TipoProdotto.h"


class Prodotto {
public:
    //costruttore del prodotto
    Prodotto(TipoProdotto* tipo, int quantita);

    //metodo per ottenere il nome del prodotto
    const std::string getNomeTipo() const;

    //metodo per ottenere la quantità del prodotto
    int getQuantita() const;

    //metodo per modificare la quantità del prodotto
    void setQuantita(int quantita);

    //metodo per verificare se il prodotto è stato comprato
    bool isComprato() const;

    //metod per modificare lo stato del prodotto
    void setComprato(bool c);

private:
    TipoProdotto* tipo;
    int quantita;
    bool comprato;
};



#endif //LABPROGAG_PRODOTTO_H
