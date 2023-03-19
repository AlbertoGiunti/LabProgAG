//
// Created by alberto on 16/03/23.
//

#include "ListaSpesa.h"


//costruttore della lista della spesa
ListaSpesa::ListaSpesa(const std::string &nomeLista) : nomeLista(nomeLista) {}

//implementazione metodo che aggiunge elementi in coda alla lista della spesa
void ListaSpesa::addProdotto(Prodotto *p) {
    prodotti.push_back(p);
}

//implementazione metodo che modifica un prodotto della lista della spesa, se la nuova quantità del prodotto (q) è 0 cancella il prodotto dalla lista, se la lista è vuota cancella la lista.
void ListaSpesa::modifyProdotto(Prodotto *p, int q) {
    bool modificato = false;
    for(auto it = prodotti.begin(); it != prodotti.end() && !modificato; it++){
        if((*it)->getNome() ==  p->getNome()){
            if(q == 0){
                this->removeProdotto(p);
            }
            else {
                p->setQuantita(q);
            }
            modificato = true;
            std::cout<<"Modifica effettuata" << std::endl;
        }
    }
    if(!modificato){
        std::cout<<"Prodotto non presente nella lista" << std::endl;
    }
}

//implementazione metodo per rimuovere un prodotto
void ListaSpesa::removeProdotto(Prodotto *p) {
    prodotti.remove(p);
    std::cout << "Prodotto " << p->getNome() << " rimosso" << std::endl;
    if(prodotti.empty()) {
        this->notify();
        delete this;
    }
}
//Implementazione del metodo attach
void ListaSpesa::attach(Observer *o) {
    observers.push_back(o);
}

//implementazione del metodo detach
void ListaSpesa::detach(Observer *o) {
    observers.remove(o);
}

//implementazione del metodo notify
void ListaSpesa::notify() {
    std::cout << "notify()" << std::endl;
    for(auto it = observers.begin(); it != observers.end(); ) {
        auto tt= it;
        it++;
        (*tt)->update(this);
    }
}


//implementazione metodo per stampare la lista della spesa
void ListaSpesa::showListaSpesa() {
    std::cout << "Lista della spesa: " << nomeLista <<std::endl;
    std::cout << "Elenco prodotti: " << std::endl;
    for(auto it = prodotti.begin(); it != prodotti.end(); it++){
        std::cout << (*it)->getNome() << " " << (*it)->getQuantita() << std::endl;
    }
}

//implementazione metodo per ottenere il nome della lista della spesa
const std::string ListaSpesa::getNomeLista() const {
    return nomeLista;
}

//Distruttore della lista della spesa
ListaSpesa::~ListaSpesa() {
    std::cout << "Lista della spesa: " << nomeLista << " eliminata" << std::endl;
}


