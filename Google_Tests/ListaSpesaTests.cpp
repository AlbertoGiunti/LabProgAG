//
// Created by alberto on 3/25/23.
//

#include "gtest/gtest.h"
#include "../ListaSpesa.h"
#include "../Utente.h"

//test costruttore
TEST(ListaSpesa, costruttore) {
    ListaSpesa l("ListaProva");
    ASSERT_EQ("ListaProva", l.getNomeLista());
}

//test getNomeLista
TEST(ListaSpesa, getNomeLista) {
    ListaSpesa l("ListaProva");
    ASSERT_EQ("ListaProva", l.getNomeLista());
}

//test addProdotto
TEST(ListaSpesa, addProdotto) {
    ListaSpesa ls("ListaProva");
    Prodotto p("ProdProva", 1);
    ls.addProdotto(&p);
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
    ASSERT_EQ(1, ls.getObservers().size());
    ASSERT_EQ("UtenteProva", ls.getObservers().front()->getNomeUtente());
}

//test detach
TEST(ListaSpesa, detach) {
    ListaSpesa ls("ListaProva");
    Prodotto p("ProdProva", 1);
    ls.addProdotto(&p);
    Utente *o = new Utente("UtenteProva");
    ls.attach(o);
    ls.detach(o);
    ASSERT_EQ(0, ls.getObservers().size());
}


