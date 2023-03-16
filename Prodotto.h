//
// Created by alberto on 16/03/23.
//

#ifndef LABPROGAG_PRODOTTO_H
#define LABPROGAG_PRODOTTO_H
#include <iostream>

class Prodotto {
public:
    Prodotto(const std::string &nome, const std::string &categoria, int quantita);

    const std::string &getNome() const;

    int getQuantita() const;

    void setQuantita(int quantita);

    virtual ~Prodotto();

private:
    std::string nome;
    std::string categoria;
    int quantita;

};



#endif //LABPROGAG_PRODOTTO_H
