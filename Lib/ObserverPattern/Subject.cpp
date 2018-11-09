//this file contains the implementation for all of the methods defined in the Subject.h file
#include "Subject.h"

Subject::Subject()
{
  //default constructor
  //we should create a new linked list to strore the observers
  observerList = new SinglyLinkedList<Observer*>;
}

Subject::~Subject()
{
  //destructor
  //we need to make sure, that when the subject is deleted, that we delete its list of observers
  delete observerList;
}

void Subject::attach(Observer* o)
{
  //when an observer is attached to the subject
  //we should add it to the list

  //create a new node to add to the list
  node<Observer*>* n = new node<Observer*>;
  n -> setData(o); //set the data in the node to the passed observer
  observerList -> add(n); //add the new node to the list of observers

}

void Subject::detach(Observer* o)
{
  //when detaching, we need to remove the node that has the observer that we passed in the function from the list
  //to do this, we need to go down the list and find the node that is holding that observer, and then remove that node

  //curr is the node that we will use to go down the list so we should begin at the head
  node<Observer*>* curr = observerList -> getHead();

  //while we have not reached the end of the list
  while(curr != NULL)
  {
    //for each node in the list, we should compare the data in the node to the passed observer and if they are the same
    //then we should break

    if(curr -> getData() == o)
    {
      break;
    }

    //move down the list
    curr = curr -> getNext();
  }

  //now we either have found the node with the observer we want to detach or not.

  //if we haven't, then this means that we went all the way down the list and curr should now be pointing to null
  //therefore only if curr is not null should we remove the node from the list

  if(curr != NULL)
  {
    observerList -> remove(curr);
  }

}

void Subject::notify()
{
  //this method will inform each observer that it has to update its state
  //therefore for each observer in our list, we should call its update method

  //begin at the head of the list
  node<Observer*>* curr = observerList -> getHead();

  //for each node in the list, we need to call an update on the data in that node
  while(curr != NULL)
  {
    curr -> getData() -> Update();
    //move to the next node
    curr = curr -> getNext();
  }
}
