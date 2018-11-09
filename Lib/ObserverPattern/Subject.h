//this file contains the interface for the subject class, which will be responsible for notifying its observers

#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include "../../Graph/SinglyLinkedList.h" //the list of observer the subject has will be stored in our linked list

class Subject
{
  public:
    Subject(); //default constructor
    ~Subject(); //default destructor
    virtual void attach(Observer*); //a method to attach an observer to the subject
    virtual void detach(Observer*); //a method to detach an observer from the subject
    virtual void notify(); //a method to notify all of the observers of this subject of a state change

  private:
    SinglyLinkedList<Observer*>* observerList; //this is the list of the observers
};

#endif

