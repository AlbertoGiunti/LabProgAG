//
// Created by alberto on 3/25/23.
//

#include "gtest/gtest.h"
#include "../Utente.h"

//test costruttore
TEST(Utente, costruttore) {
    Utente u("Alberto");
    ASSERT_EQ("Alberto", u.getNomeUtente());
}

//test addListaSpesa
TEST(Utente, addListaSpesa) {
    Utente u("Alberto");
    ListaSpesa ls("ListaProva1");
    u.addListaSpesa(&ls);
    ASSERT_EQ(1, u.getListaSpesa().size());
    ASSERT_EQ("ListaProva1", u.getListaSpesa().front()->getNomeLista());
}

//test removeListaSpesa
TEST(Utente, removeListaSpesa) {
    Utente u("Alberto");
    ListaSpesa ls("ListaProva");
    u.addListaSpesa(&ls);
    ASSERT_EQ("Alberto", ls.getObservers().getNomeUtente());
    u.removeListaSpesa(&ls);
    ASSERT_EQ(0, ls.getObservers().size());
    ASSERT_EQ(0, u.getListaSpesa().size());
}

//test update
TEST(Utente, update) {
    Utente u("Alberto");
    ListaSpesa ls1("ListaProva1");
    ListaSpesa ls2("ListaProva2");
    Prodotto p1("ProdProva1", 1);
    Prodotto p2("ProdProva2", 2);
    ls1.addProdotto(&p1);
    ls2.addProdotto(&p2);
    u.addListaSpesa(&ls1);
    u.addListaSpesa(&ls2);
    u.update(&ls1);
    ASSERT_EQ(2, u.getListaSpesa().front()->getProdotti().front()->getQuantita());
}