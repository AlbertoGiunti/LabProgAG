//
// Created by alberto on 08/04/23.
//

#ifndef LABPROGAG_TIPOPRODOTTO_H
#define LABPROGAG_TIPOPRODOTTO_H

#include <iostream>

class TipoProdotto {
public:
    //costruttore del tipo di prodotto
    TipoProdotto(const std::string nome);

    //metodo per ottenere il nome del tipo di prodotto
    const std::string getNome() const;

private:
    std::string nome;
};


#endif //LABPROGAG_TIPOPRODOTTO_H
