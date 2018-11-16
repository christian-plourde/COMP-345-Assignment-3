#include <iostream>
#include "GameStatisticsObserver.h"
#include "../../player/Player.h"

void GameStatisticsObserver::Update()
{
  //this is the definition for the update method for the game GameStatisticsObserver class
  //essentially for each player in the game, we should display some stats about them

  node<Player*>* curr = Player::players -> getHead(); //this is the head of the list of players

  while(curr != NULL)
  {
    //while we still have players to treat keep going
    //we should show where they are, how many victory points they have, their current health, their energy cube total
    //their name

    std::cout << "PLAYER: " << curr -> getData() -> getName() << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "HEALTH POINTS: " << curr -> getData() -> getHealth() << std::endl;
    std::cout << "VICTORY POINTS: " << curr -> getData() -> getVictoryPoints() << std::endl;
    std::cout << "ENERGY CUBES: " << curr -> getData() -> getEnergy() << std::endl;
    //finally we need to output their current location
    int currentZone = curr -> getData() -> getZone();
    Graph<std::string>* map = MapLoader::getMap();

    std::cout << "CURRENT ZONE: " << map -> getVertex(currentZone) -> getName() << std::endl;
    std::cout << std::endl;
    curr = curr -> getNext();
  }


}