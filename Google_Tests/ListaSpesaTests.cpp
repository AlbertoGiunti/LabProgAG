//
// Created by alberto on 3/25/23.
//

#include "gtest/gtest.h"
#include "../ListaSpesa.h"
#include "../Utente.h"

//test costruttore
TEST(ListaSpesa, costruttore) {
    ListaSpesa l("ListaProva");

    //test del nome
    ASSERT_EQ("ListaProva", l.getNomeLista());
}

//test getNomeLista
TEST(ListaSpesa, getNomeLista) {
    ListaSpesa l("ListaProva");

    //test del nome
    ASSERT_EQ("ListaProva", l.getNomeLista());
}

//test addProdotto
TEST(ListaSpesa, addProdotto) {
    ListaSpesa ls("ListaProva");
    Prodotto p("ProdProva", 1);
    ls.addProdotto(&p);

    //controllo che il prodotto sia stato aggiunto alla lista con il nome e la quantità corretta
    ASSERT_EQ(1, ls.getProdotti().size());
    ASSERT_EQ("ProdProva", ls.getProdotti().front()->getNome());  //front() ritorna il primo elemento della lista
    ASSERT_EQ(1, ls.getProdotti().front()->getQuantita());
}

//test modifyProdotto con il prodotto già presente nella lista
TEST(ListaSpesa, modifyProdottoPresente) {
    ListaSpesa ls("ListaProva");
    Prodotto p1("ProdProva1", 1);
    Prodotto p2("ProdProva2", 2);
    ls.addProdotto(&p1);
    ls.addProdotto(&p2);
    ls.modifyProdotto(&p1, 2);

    //controllo che il prodotto sia stato modificato correttamente
    ASSERT_EQ(2, ls.getProdotti().size());
    ASSERT_EQ("ProdProva1", ls.getProdotti().front()->getNome());
    ASSERT_EQ(2, ls.getProdotti().front()->getQuantita());
}

//test modifyProdotto con il prodotto non presente nella lista
TEST(ListaSpesa, modifyProdottoNonPresente) {
    ListaSpesa ls("ListaProva");
    Prodotto p1("ProdProva1", 1);
    Prodotto p2("ProdProva2", 2);
    ls.addProdotto(&p1);
    ls.modifyProdotto(&p2, 2);

    // controllo che il prodotto già presente sia rimasto invariato
    ASSERT_EQ(1, ls.getProdotti().size());
    ASSERT_EQ("ProdProva1", ls.getProdotti().front()->getNome());
    ASSERT_EQ(1, ls.getProdotti().front()->getQuantita());
}

//test modifyProdotto con la quantità uguale a 0
TEST(ListaSpesa, modifyProdottoQuantitaZero) {
    ListaSpesa ls("ListaProva");
    Prodotto p1("ProdProva1", 1);
    Prodotto p2("ProdProva2", 2);
    ls.addProdotto(&p1);
    ls.addProdotto(&p2);
    ls.modifyProdotto(&p1, 0);

    //controllo che il prodotto sia stato rimosso correttamente
    ASSERT_EQ(1, ls.getProdotti().size());
    ASSERT_EQ("ProdProva2", ls.getProdotti().front()->getNome());
    ASSERT_EQ(2, ls.getProdotti().front()->getQuantita());
}

//test removeProdotto
TEST(ListaSpesa, removeProdotto) {
    ListaSpesa ls("ListaProva");
    Prodotto p1("ProdProva1", 1);
    Prodotto p2("ProdProva2", 2);
    ls.addProdotto(&p1);
    ls.addProdotto(&p2);
    ls.removeProdotto(&p2);

    //controllo che il prodotto sia stato rimosso correttamente
    ASSERT_EQ(2, ls.getProdotti().size());
    ASSERT_EQ("ProdProva1", ls.getProdotti().front()->getNome());
}

//test attach
TEST(ListaSpesa, attach) {
    ListaSpesa ls("ListaProva");
    Prodotto p("ProdProva", 1);
    ls.addProdotto(&p);
    Utente *o = new Utente("UtenteProva");
    ls.attach(o);

    //controllo che l'utente sia stato attaccato correttamente
    ASSERT_EQ(1, ls.getObservers().size());
    ASSERT_TRUE(ls.getObservers().front() == o);
}

//test detach
TEST(ListaSpesa, detach) {
    ListaSpesa ls("ListaProva");
    Prodotto p("ProdProva", 1);
    ls.addProdotto(&p);
    Utente *o = new Utente("UtenteProva");
    ls.attach(o);
    ls.detach(o);

    //controllo che l'utente sia stato staccato correttamente
    ASSERT_EQ(0, ls.getObservers().size());
}


