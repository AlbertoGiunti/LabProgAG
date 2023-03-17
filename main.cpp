#include <iostream>
#include "Utente.h"
#include "Prodotto.h"
#include "ListaSpesa.h"

int main() {
    Prodotto pasta("Pasta", 1);
    Prodotto olio("Olio", 1);
    Prodotto mela("Mela", 6);
    Prodotto uova("Uova", 12);
    Prodotto latte("Latte", 1);
    Prodotto formaggio("Formaggio", 2);


    Utente* u1 = new Utente("Niccolò");
    Utente* u2 = new Utente("Giovanni");
    Utente* u3 = new Utente("Alberto");

    ListaSpesa* l1 = new ListaSpesa("Lista 1");
    ListaSpesa* l2 = new ListaSpesa("Lista 2");
    ListaSpesa* l3 = new ListaSpesa("Lista 3");

    return 0;
}
