#ifndef GAME_PHASE_OBSERVER_H
#define GAME_PHASE_OBSERVER_H

#include "Observer.h"
#include "Subject.h"

//this class is in charge of observing changes to the game phase, for example, when a player rolls, or moves, etc.
//for this reason, there is another constructor that allows it to observer a specific subject
class GamePhaseObserver : public Observer
{
  public:
    GamePhaseObserver(Subject*); //the special constructor that allows the observer to be attributed to a specific subject
    void Update(); //the update method from the base class, where it was pure virtual

  private:
    Subject* subject; //the subject that the observer is observing
};

#endif