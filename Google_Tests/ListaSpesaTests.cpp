//
// Created by alberto on 3/25/23.
//

#include "gtest/gtest.h"
#include "../ListaSpesa.h"
#include "../Utente.h"


//test addProdotto
TEST(ListaSpesa, addProdotto) {
    ListaSpesa ls("ListaProva");
    TipoProdotto tp("TipoProva");
    ls.addProdotto(tp,6);

    //controllo che il prodotto sia stato aggiunto alla lista con il nome e la quantità corretta
    ASSERT_EQ(1, ls.getProdotti().size());
    ASSERT_EQ("TipoProva", ls.getProdotti().front()->getNomeTipo());
    ASSERT_EQ(false, ls.getProdotti().front()->isComprato());
    ASSERT_EQ(6, ls.getProdotti().front()->getQuantita());
    ASSERT_EQ(6, ls.getTotaleProdotti());
    ASSERT_EQ(0, ls.getTotaleProdottiComprati());
    ASSERT_EQ(6, ls.getTotaleProdottiNonComprati());
}

//test modifyProdotto con il prodotto già presente nella lista
TEST(ListaSpesa, modifyProdottoPresente) {
    ListaSpesa ls("ListaProva");
    TipoProdotto tp1("TipoProva1");
    TipoProdotto tp2("TipoProva2");
    ls.addProdotto(tp1,9);
    ls.addProdotto(tp2,3);
    ls.modifyProdotto(tp1, 2);

    //controllo che il prodotto sia stato modificato correttamente
    ASSERT_EQ(2, ls.getProdotti().size());
    ASSERT_EQ("TipoProva1", ls.getProdotti().front()->getNomeTipo());
    ASSERT_EQ(2, ls.getProdotti().front()->getQuantita());
    ASSERT_EQ(5, ls.getTotaleProdotti());
    ASSERT_EQ(0, ls.getTotaleProdottiComprati());
    ASSERT_EQ(5, ls.getTotaleProdottiNonComprati());
}

//test modifyProdotto con il prodotto non presente nella lista
TEST(ListaSpesa, modifyProdottoNonPresente) {
    ListaSpesa ls("ListaProva");
    TipoProdotto tp1("TipoProva1");
    TipoProdotto tp2("TipoProva2");
    ls.addProdotto(tp1,9);
    EXPECT_ANY_THROW(ls.modifyProdotto(tp2, 2));

    //controllo che la lista non sia stata modificata
    ASSERT_EQ(1, ls.getProdotti().size());
    ASSERT_EQ("TipoProva1", ls.getProdotti().front()->getNomeTipo());
    ASSERT_EQ(9, ls.getProdotti().front()->getQuantita());
}

//test modifyProdotto di un prodotto già comprato
TEST(ListaSpesa, modifyProdottoComprato) {
    ListaSpesa ls("ListaProva");
    TipoProdotto tp1("TipoProva1");
    TipoProdotto tp2("TipoProva2");
    ls.addProdotto(tp1,9);
    ls.buyProdotto(tp1);
    EXPECT_ANY_THROW(ls.modifyProdotto(tp2, 2));

    //controllo che la lista non sia stata modificata
    ASSERT_EQ(1, ls.getProdotti().size());
    ASSERT_EQ("TipoProva1", ls.getProdotti().front()->getNomeTipo());
    ASSERT_EQ(9, ls.getProdotti().front()->getQuantita());
}



//test removeProdotto
TEST(ListaSpesa, removeProdotto) {
    ListaSpesa ls("ListaProva");
    TipoProdotto tp1("TipoProva1");
    TipoProdotto tp2("TipoProva2");
    ls.addProdotto(tp1,8);
    ls.addProdotto(tp2, 3);
    ls.removeProdotto(tp2);

    //controllo che il prodotto sia stato rimosso correttamente
    ASSERT_EQ(1, ls.getProdotti().size());
    ASSERT_EQ("TipoProva1", ls.getProdotti().front()->getNomeTipo());
    ASSERT_EQ(8, ls.getProdotti().front()->getQuantita());
    ASSERT_EQ(8, ls.getTotaleProdotti());
    ASSERT_EQ(0, ls.getTotaleProdottiComprati());
    ASSERT_EQ(8, ls.getTotaleProdottiNonComprati());
}

//test removeProdotto non presente nella lista
TEST(ListaSpesa, removeProdottoNonPresente) {
    ListaSpesa ls("ListaProva");
    TipoProdotto tp1("TipoProva1");
    TipoProdotto tp2("TipoProva2");
    ls.addProdotto(tp1,8);
    EXPECT_ANY_THROW(ls.removeProdotto(tp2));

    //controllo che la lista non sia stata modificata
    ASSERT_EQ(1, ls.getProdotti().size());
    ASSERT_EQ("TipoProva1", ls.getProdotti().front()->getNomeTipo());
    ASSERT_EQ(8, ls.getProdotti().front()->getQuantita());
    ASSERT_EQ(8, ls.getTotaleProdotti());
    ASSERT_EQ(0, ls.getTotaleProdottiComprati());
    ASSERT_EQ(8, ls.getTotaleProdottiNonComprati());
}

//test buyProdotto presente nella lista
TEST(ListaSpesa, buyProdotto) {
    ListaSpesa ls("ListaProva");
    TipoProdotto tp1("TipoProva1");
    TipoProdotto tp2("TipoProva2");
    ls.addProdotto(tp1,8);
    ls.addProdotto(tp2, 3);
    ls.buyProdotto(tp2);

    //controllo che il prodotto sia stato comprato correttamente
    ASSERT_EQ(2, ls.getProdotti().size());
    ASSERT_EQ(true, ls.getProdotti().back()->isComprato());
    ASSERT_EQ(11, ls.getTotaleProdotti());
    ASSERT_EQ(3, ls.getTotaleProdottiComprati());
    ASSERT_EQ(8, ls.getTotaleProdottiNonComprati());
}

//test buyProdotto non presente nella lista
TEST(ListaSpesa, buyProdottoNonPresente) {
    ListaSpesa ls("ListaProva");
    TipoProdotto tp1("TipoProva1");
    TipoProdotto tp2("TipoProva2");
    ls.addProdotto(tp1,8);
    EXPECT_ANY_THROW(ls.buyProdotto(tp2));

    //controllo che la lista non sia stata modificata
    ASSERT_EQ(1, ls.getProdotti().size());
    ASSERT_EQ("TipoProva1", ls.getProdotti().front()->getNomeTipo());
    ASSERT_EQ(8, ls.getProdotti().front()->getQuantita());
    ASSERT_EQ(8, ls.getTotaleProdotti());
    ASSERT_EQ(0, ls.getTotaleProdottiComprati());
    ASSERT_EQ(8, ls.getTotaleProdottiNonComprati());
}

//test attach
TEST(ListaSpesa, attach) {
    ListaSpesa ls("ListaProva");
    TipoProdotto tp("TipoProva");
    ls.addProdotto(tp,1);
    Utente *o = new Utente("UtenteProva");
    ls.attach(o);

    //controllo che l'utente sia stato attaccato correttamente
    ASSERT_EQ(1, ls.getObservers().size());
    ASSERT_TRUE(ls.getObservers().front() == o);
}

//test detach
TEST(ListaSpesa, detach) {
    ListaSpesa ls("ListaProva");
    TipoProdotto tp("TipoProva");
    ls.addProdotto(tp,1);
    Utente *o = new Utente("UtenteProva");
    ls.attach(o);
    ls.detach(o);

    //controllo che l'utente sia stato staccato correttamente
    ASSERT_EQ(0, ls.getObservers().size());
}

//test isObserving
TEST(ListaSpesa, isObserved) {
    ListaSpesa ls("ListaProva");
    TipoProdotto tp("TipoProva");
    ls.addProdotto(tp,1);
    Utente *o = new Utente("UtenteProva");
    ls.attach(o);

    //controllo che l'utente sia stato attaccato correttamente
    ASSERT_TRUE(ls.isObserved(o));
}

