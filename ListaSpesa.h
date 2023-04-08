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

    //metodo per ottenere la lista degli observer
    const std::list<Observer *> getObservers() const;

    //metodo per verificare su un utente sta osservano o meno questa lista
    bool isObserved(Observer *o);

    //metodo per aggiungere un prodotto alla lista dei prodotti
    void addProdotto(TipoProdotto &tp, int q);

    //metodo per modificare la quantità di un prodotto
    void modifyProdotto(TipoProdotto &tp, int q);

    //metodo per acquistare un prodotto
    void buyProdotto(TipoProdotto &tp);

    //metodo per rimuovere un prodotto
    void removeProdotto(TipoProdotto &tp);

    //metodo per stampare la lista della spesa
    void showListState() const;

    const std::list<Prodotto *> &getProdotti() const;

    int getTotaleProdotti() const;

    void setTotaleProdotti(int totaleProdotti);

    int getTotaleProdottiComprati() const;

    void setTotaleProdottiComprati(int totaleProdottiComprati);

    int getTotaleProdottiNonComprati() const;

    void setTotaleProdottiNonComprati(int totaleProdottiNonComprati);

    //implementazione del metodo attach
    void attach(Observer *o) override;

    //implementazione del metodo detach
    void detach(Observer *o) override;

    //metodo per sapere se la lista è stata completata
    bool isCompletata() const;

    //metodo per settare la lista come completata
    void setCompletata(bool c);

    //implementazione del metodo notify
    void notify() override;

    //distruttore della lista della spesa
    virtual ~ListaSpesa();

private:
    std::string nomeLista;
    std::list<Prodotto *> prodotti;
    std::list<Observer*> observers;
    int totaleProdotti;
    int totaleProdottiComprati;
    int totaleProdottiNonComprati;
    bool completata;
};





#endif //LABPROGAG_LISTASPESA_H
