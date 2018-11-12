
#ifndef GAME_STATISTICS_OBSERVER_H
#define GAME_STATISTICS_OBSERVER_H

#include "Observer.h"

//this is the observer for the game statistics that will be observing the player, which extends the subject class
class GameStatisticsObserver : public Observer
{
  void Update(); //this is from the observer class, in which it was pure virtual
};

#endif