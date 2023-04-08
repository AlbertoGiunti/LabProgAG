//
// Created by alberto on 16/03/23.
//

#include "ListaSpesa.h"


//costruttore della lista della spesa
ListaSpesa::ListaSpesa(const std::string &nomeLista) : nomeLista(nomeLista) {
    totaleProdotti = 0;
    totaleProdottiComprati = 0;
    totaleProdottiNonComprati = 0;
}

//implementazione metodo per ottenere il nome della lista della spesa
const std::string ListaSpesa::getNomeLista() const {
    return nomeLista;
}

//implementazione metodo getObservers
const std::list<Observer *> ListaSpesa::getObservers() const {
    return observers;
}

//implementazione metodo per vedere se un utente sta osservando la lista della spesa
bool ListaSpesa::isObserved(Observer *o) {
    bool trovato = false;
    for(auto it = observers.begin(); it != observers.end() && !trovato; it++){
        if((*it) == o){
            trovato = true;
        }
    }
    return trovato;
}

//implementazione metodo che aggiunge elementi in coda alla lista della spesa
void ListaSpesa::addProdotto(TipoProdotto &tp, int q) {
    Prodotto *p = new Prodotto(&tp, q);
    totaleProdotti += q;
    totaleProdottiNonComprati += q;
    prodotti.push_back(p);
    notify();
}

//implementazione metodo che modifica un prodotto della lista della spesa, se la nuova quantità del prodotto (q) è 0 cancella il prodotto dalla lista, se la lista è vuota cancella la lista.
void ListaSpesa::modifyProdotto(TipoProdotto &tp, int q) {
    bool modificato = false;
    for(auto it = prodotti.begin(); it != prodotti.end() && !modificato; it++){
        if((*it)->getNomeTipo() == tp.getNome() && !(*it)->isComprato()){
            int c = (*it)->getQuantita();
            if(q == 0){
                totaleProdotti -= c;
                totaleProdottiNonComprati -= c;
                removeProdotto(tp);
            }
            else {
                totaleProdotti = totaleProdotti -c +q;
                totaleProdottiNonComprati = totaleProdottiNonComprati -c +q;
                (*it)->setQuantita(q);
            }
            modificato = true;
            notify();
        }
    }
    if(!modificato){
        throw std::runtime_error("Prodotto non presente nella lista");
    }
}

//implementazione metodo per rimuovere un prodotto
void ListaSpesa::removeProdotto(TipoProdotto &tp) {
    bool trovato = false;
    for(auto it = prodotti.begin(); it != prodotti.end() && !trovato; it++){
        if((*it)->getNomeTipo() == tp.getNome()){
            totaleProdotti -= (*it)->getQuantita();
            if(!(*it)->isComprato()){
                totaleProdottiNonComprati -= (*it)->getQuantita();
            }
            prodotti.remove(*it);
            trovato = true;
            notify();
        }
    }
    if(!trovato){
        throw std::runtime_error("Prodotto non presente nella lista");
    }
    if(prodotti.empty()){
        completata = true;
        notify();
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
    for(auto it = observers.begin(); it != observers.end(); ) {
        auto tt= it;
        it++;
        (*tt)->update(this);
    }
}


//implementazione metodo per stampare la lista della spesa
void ListaSpesa::showListState() const{
    std::cout << "Lista della spesa: " << nomeLista <<std::endl;
    std::cout << "Elenco prodotti da comprare: " << std::endl;
    for(auto it = prodotti.begin(); it != prodotti.end(); it++){
        if(!(*it)->isComprato()){
            std::cout << (*it)->getNomeTipo() << " " << (*it)->getQuantita() << std::endl;
        }
    }
    std::cout << "Numero di prodotti nella lista: " << totaleProdotti << std::endl;
    std::cout << "Numero prodotti da comprare: " << totaleProdottiNonComprati << std::endl;
    std::cout << "Numero prodotti comprati: " << totaleProdottiComprati << std::endl;
}

//implementazione metodo per comprare un prodotto
void ListaSpesa::buyProdotto(TipoProdotto &tp) {
    bool trovato = false;
    for(auto it = prodotti.begin(); it != prodotti.end() && !trovato; it++){
        if((*it)->getNomeTipo() == tp.getNome()){
            if((*it)->isComprato()){
                throw std::runtime_error("Prodotto già comprato");
            }
            else {
                (*it)->setComprato(true);
                totaleProdottiComprati += (*it)->getQuantita();
                totaleProdottiNonComprati -= (*it)->getQuantita();
            }
            trovato = true;
            notify();
        }
    }
    if(!trovato){
        throw std::runtime_error("Prodotto non presente nella lista");
    }
}

bool ListaSpesa::isCompletata() const {
    return completata;
}

void ListaSpesa::setCompletata(bool c) {
    ListaSpesa::completata = c;
}

int ListaSpesa::getTotaleProdotti() const {
    return totaleProdotti;
}

void ListaSpesa::setTotaleProdotti(int totaleProdotti) {
    ListaSpesa::totaleProdotti = totaleProdotti;
}

int ListaSpesa::getTotaleProdottiComprati() const {
    return totaleProdottiComprati;
}

void ListaSpesa::setTotaleProdottiComprati(int totaleProdottiComprati) {
    ListaSpesa::totaleProdottiComprati = totaleProdottiComprati;
}

int ListaSpesa::getTotaleProdottiNonComprati() const {
    return totaleProdottiNonComprati;
}

void ListaSpesa::setTotaleProdottiNonComprati(int totaleProdottiNonComprati) {
    ListaSpesa::totaleProdottiNonComprati = totaleProdottiNonComprati;
}

//Distruttore della lista della spesa
ListaSpesa::~ListaSpesa() {
    std::cout << "Lista della spesa: " << nomeLista << " eliminata" << std::endl;
}

const std::list<Prodotto *> &ListaSpesa::getProdotti() const {
    return prodotti;
}



