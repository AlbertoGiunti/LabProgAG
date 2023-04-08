//
// Created by alberto on 16/03/23.
//

#ifndef LABPROGAG_SUBJECT_H
#define LABPROGAG_SUBJECT_H
#include <iostream>
#include <list>
#include "Observer.h"

//subject dell'observer di tipo push
class Subject {
public:

    //metodo per aggiungere un observer alla lista degli observer
    virtual void attach(Observer *o) = 0;

    //metodo per rimuovere un observer dalla lista degli observer
    virtual void detach(Observer *o) = 0;

    //metodo per notificare gli observer
    virtual void notify() = 0;


    virtual ~Subject() = default;
};

#endif //LABPROGAG_SUBJECT_H
