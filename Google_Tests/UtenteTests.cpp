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

    // controllo che l'utente sia stato aggiunto alla lista degli osservatori della lista
    ASSERT_EQ(1, ls.getObservers().size());
    ASSERT_TRUE(ls.isObserved(&u));

    // controllo che la lista sia stata aggiunta alla lista degli utenti
    ASSERT_EQ(1, u.getListaSpesa().size());
    ASSERT_EQ("ListaProva1", u.getListaSpesa().front()->getNomeLista());
}

//test removeListaSpesa
TEST(Utente, removeListaSpesa) {
    Utente u("Alberto");
    ListaSpesa ls("ListaProva");
    u.addListaSpesa(&ls);
    u.removeListaSpesa(&ls);

    // controllo che l'utente sia stato rimosso dalla lista degli osservatori della lista
    ASSERT_EQ(0, ls.getObservers().size());

    // controllo che la lista sia stata rimossa dalla lista degli utenti
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

    // controllo che la lista sia stata aggiornata
    ASSERT_FALSE(ls1.isObserved(&u));
    ASSERT_EQ(1, u.getListaSpesa().size());
}