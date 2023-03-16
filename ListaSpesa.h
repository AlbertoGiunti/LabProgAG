//
// Created by alberto on 16/03/23.
//

#ifndef LABPROGAG_LISTASPESA_H
#define LABPROGAG_LISTASPESA_H
#include <iostream>
#include <list>
#include "Prodotto.h"
#include <gtest/gtest.h>


class ListaSpesa {
public:
    explicit ListaSpesa(const std::string &nomeLista);

    void addProdotto(Prodotto &p);

    void modifyProdotto(Prodotto &p, int q);

    virtual ~ListaSpesa();

private:
    std::string nomeLista;
    std::list<Prodotto> prodotti;
};




#endif //LABPROGAG_LISTASPESA_H
