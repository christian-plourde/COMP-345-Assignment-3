//this is a test of the game statistics observer
#include "../../Player/Player.h"
#include "../../Lib/ObserverPattern/GameStatisticsObserver.h"
#include <iostream>

int main()
{
  MapLoader::loadMap();
  Player* p1 = new Player();

  GameStatisticsObserver* go = new GameStatisticsObserver();
  p1 -> attach(go);
  p1 -> setZone(8);
  p1 -> notify();

  delete p1;
  delete go;
  return 0;
}