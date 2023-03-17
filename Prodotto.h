//
// Created by alberto on 16/03/23.
//

#ifndef LABPROGAG_PRODOTTO_H
#define LABPROGAG_PRODOTTO_H
#include <iostream>

class Prodotto {
public:
    //costruttore del prodotto
    Prodotto(const std::string nome, int quantita);
    //metodo per ottenere il nome del prodotto
    const std::string getNome() const;

    //metodo per ottenere la quantità del prodotto
    int getQuantita() const;

    //metodo per modificare la quantità del prodotto
    void setQuantita(int quantita);

    //distruttore del prodotto
    virtual ~Prodotto();

private:
    std::string nome;
    int quantita;
};



#endif //LABPROGAG_PRODOTTO_H
