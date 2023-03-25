//
// Created by alberto on 3/25/23.
//

#include "gtest/gtest.h"
#include "../Prodotto.h"


//test del costruttore
TEST(Prodotto, costruttore) {
    Prodotto p("pasta", 10);
    ASSERT_EQ("pasta", p.getNome());
    ASSERT_EQ(10, p.getQuantita());
}

//test del metodo getNome
TEST(Prodotto, getNome) {
    Prodotto p("pasta", 10);
    ASSERT_EQ("pasta", p.getNome());
}

//test del metodo getQuantita
TEST(Prodotto, getQuantita) {
    Prodotto p("pasta", 10);
    ASSERT_EQ(10, p.getQuantita());
}

//test del metodo setQuantita
TEST(Prodotto, setQuantita) {
    Prodotto p("pasta", 10);
    p.setQuantita(20);
    ASSERT_EQ(20, p.getQuantita());
}

