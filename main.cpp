#include <iostream>
#include "Utente.h"
#include "Prodotto.h"
#include "ListaSpesa.h"

int main() {

    Utente* u1 = new Utente("Mattia");
    Utente* u2 = new Utente("Giovanni");
    Utente* u3 = new Utente("Alberto");

    TipoProdotto pasta("Pasta");
    TipoProdotto olio("Olio");
    TipoProdotto formaggio("Formaggio");
    TipoProdotto mela("Mela");
    TipoProdotto uova("Uova");
    TipoProdotto latte("Latte");
    TipoProdotto pane("Pane");
    TipoProdotto zucchero("Zucchero");
    TipoProdotto acqua("Acqua");
    TipoProdotto farina("Farina");
    TipoProdotto burro("Burro");


    ListaSpesa* l1 = new ListaSpesa("Lista 1");
    ListaSpesa* l2 = new ListaSpesa("Lista 2");
    ListaSpesa* l3 = new ListaSpesa("Lista 3");
    ListaSpesa* l4 = new ListaSpesa("Lista 4");
    ListaSpesa* l5 = new ListaSpesa("Lista 5");

    u1->addListaSpesa(l1);
    u1->addListaSpesa(l2);


    u2->addListaSpesa(l1);
    u2->addListaSpesa(l3);
    u2->addListaSpesa(l4);


    u3->addListaSpesa(l1);
    u3->addListaSpesa(l4);
    u3->addListaSpesa(l5);

    l1->addProdotto(pasta, 2);
    l1->addProdotto(olio,1);

    l2->addProdotto(mela,3);
    l2->addProdotto(uova,12);
    l2->addProdotto(latte,7);

    l3->addProdotto(pane, 1);
    l3->addProdotto(zucchero, 2);
    l3->addProdotto(acqua,6);
    l3->addProdotto(formaggio,3);

    l4->addProdotto(farina,2);
    l4->addProdotto(burro,5);
    l4->addProdotto(formaggio,4);

    l5->addProdotto(pasta,4);
    l5->addProdotto(olio,2);
    l5->addProdotto(formaggio,6);
    l5->addProdotto(mela,20);


    l2->modifyProdotto(acqua, 3);
    l2->modifyProdotto(burro, 0);
    l5->buyProdotto(mela);

    //prova dell'observer

    l1->removeProdotto(pasta);
    l1->modifyProdotto(olio, 0);

    //fine prova

    u1->listsState();
    u2->listsState();
    u3->listsState();

    return 0;
}