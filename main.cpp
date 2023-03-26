#include <iostream>
#include "Utente.h"
#include "Prodotto.h"
#include "ListaSpesa.h"

int main() {
    Prodotto pasta("Pasta", 1);
    Prodotto olio("Olio", 1);
    Prodotto formaggio("Formaggio", 2);
    Prodotto mela("Mela", 6);
    Prodotto uova("Uova", 12);
    Prodotto latte("Latte", 1);
    Prodotto pane("Pane", 1);
    Prodotto zucchero("Zucchero", 3);
    Prodotto acqua("Acqua", 3);
    Prodotto farina("Farina", 4);
    Prodotto burro("Burro", 2);


    ListaSpesa* l1 = new ListaSpesa("Lista 1");
    ListaSpesa* l2 = new ListaSpesa("Lista 2");
    ListaSpesa* l3 = new ListaSpesa("Lista 3");
    ListaSpesa* l4 = new ListaSpesa("Lista 4");
    ListaSpesa* l5 = new ListaSpesa("Lista 5");

    l1->addProdotto(&pasta);
    l1->addProdotto(&olio);
    l1->showListaSpesa();

    l2->addProdotto(&mela);
    l2->addProdotto(&uova);
    l2->addProdotto(&latte);
    l2->showListaSpesa();

    l3->addProdotto(&pane);
    l3->addProdotto(&zucchero);
    l3->addProdotto(&acqua);
    l3->addProdotto(&formaggio);
    l3->showListaSpesa();

    l4->addProdotto(&farina);
    l4->addProdotto(&burro);
    l4->addProdotto(&formaggio);
    l4->addProdotto(&mela);
    l4->showListaSpesa();

    l5->addProdotto(&pasta);
    l5->addProdotto(&olio);
    l5->addProdotto(&formaggio);
    l5->addProdotto(&mela);
    l5->addProdotto(&uova);
    l5->addProdotto(&latte);
    l5->addProdotto(&pane);
    l5->showListaSpesa();

    Utente* u1 = new Utente("Mattia");
    Utente* u2 = new Utente("Giovanni");
    Utente* u3 = new Utente("Alberto");

    u1->addListaSpesa(l1);
    u1->addListaSpesa(l2);
    u1->showListe();

    u2->addListaSpesa(l1);
    u2->addListaSpesa(l3);
    u2->addListaSpesa(l4);
    u2->showListe();

    u3->addListaSpesa(l1);
    u3->addListaSpesa(l4);
    u3->addListaSpesa(l5);
    u3->showListe();

    l2->modifyProdotto(&acqua, 3);
    l2->modifyProdotto(&burro, 0);

    //prova dell'observer

    l1->removeProdotto(&pasta);
    l1->modifyProdotto(&olio, 0);

    u1->showListe();
    u2->showListe();
    u3->showListe();
    //fine prova

    //Prima di terminare il programma, distruggo tutti gli oggetti

    return 0;
}