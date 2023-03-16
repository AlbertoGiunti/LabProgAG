//
// Created by alberto on 16/03/23.
//

#include "ListaSpesa.h"


//Costruttore della lista della spesa
ListaSpesa::ListaSpesa(const std::string &nomeLista) : nomeLista(nomeLista) {}

//Metodo che aggiunge elementi in coda alla lista della spesa
void ListaSpesa::addProdotto(Prodotto *p) {
    prodotti.push_back(p);
}

//Metodo che modifica un prodotto della lista della spesa, se la nuova quantità del prodotto (q) è 0 cancella il prodotto dalla lista, se la lista è vuota cancella la lista.
void ListaSpesa::modifyProdotto(Prodotto *p, int q) {
    bool modificato = false;
    for(auto it = prodotti.begin(); it != prodotti.end() && !modificato; it++){
        if((*it)->getNome() ==  p->getNome()){
            if(q == 0){
                this->removeProdotto(p);
            }
            else
                p->setQuantita(q);
            modificato = true;
            std::cout<<"Modifica effettuata" << std::endl;
        }
        else
            std::cout<<"L'elemento che vuoi modificare non è presente nella lista" << std::endl;
    }
    //se prodotti è vuoto, cancella la lista
    if(prodotti.empty()){
        delete this;
    }
}

//Metodo per rimuovere un prodotto
void ListaSpesa::removeProdotto(Prodotto *p) {
    prodotti.remove(p);
    if(prodotti.size() == 0)
        delete this;
}

//Distruttore della lista della spesa
ListaSpesa::~ListaSpesa() {

}

