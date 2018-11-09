//this file contains an interface for the observer class

#ifndef OBSERVER_H
#define OBSERVER_H

class Observer
{
  public:
    ~Observer(); //destructor
    virtual void Update() = 0; //this function is a pure virtual function
    Observer(); //default constructor
};

#endif