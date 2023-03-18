//
// Created by alberto on 16/03/23.
//

#ifndef LABPROGAG_LISTASPESA_H
#define LABPROGAG_LISTASPESA_H
#include <iostream>
#include <list>
#include "Prodotto.h"
#include "Subject.h"
#include <gtest/gtest.h>


class ListaSpesa: public Subject {
public:

    //costruttore della lista della spesa
    explicit ListaSpesa(const std::string &nomeLista);

    //metodo per ottenere il nome della lista della spesa
    const std::string getNomeLista() const;

    //metodo per aggiungere un prodotto alla lista dei prodotti
    void addProdotto(Prodotto *p);

    //metodo per modificare la quantità di un prodotto
    void modifyProdotto(Prodotto *p, int q);

    //metodo per rimuovere un prodotto
    void removeProdotto(Prodotto *p);

    //metodo per stampare la lista della spesa
    void showListaSpesa();

    //implementazione del metodo attach
    void attach(Observer *o) override;

    //implementazione del metodo detach
    void detach(Observer *o) override;

    //implementazione del metodo notify
    void notify() override;

    //distruttore della lista della spesa
    virtual ~ListaSpesa();

private:
    std::string nomeLista;
    std::list<Prodotto*> prodotti;
    std::list<Observer*> observers;
};




#endif //LABPROGAG_LISTASPESA_H
