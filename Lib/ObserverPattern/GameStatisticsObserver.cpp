#include <iostream>
#include <iomanip>
#include "GameStatisticsObserver.h"
#include "../../player/Player.h"

void GameStatisticsObserver::Update()
{
  //this is the definition for the update method for the game GameStatisticsObserver class
  //essentially for each player in the game, we should display some stats about them

  int columnWidth = 25; //the width of each column in the table
  node<Player*>* curr = Player::players -> getHead(); //this is the head of the list of players

  //this part is the table header row
  std::cout << std::left << std::setw(columnWidth) << "PLAYER" << std::right << std::setw(columnWidth);
  std::cout << std::left << std::setw(columnWidth) << "HEALTH POINTS";
  std::cout << std::left << std::setw(columnWidth) << "VICTORY POINTS";
  std::cout << std::left << std::setw(columnWidth) << "ENERGY CUBES";
  std::cout << std::left << std::setw(columnWidth) << "CURRENT ZONE" << std::endl;
  std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;

  while(curr != NULL)
  {
    //while we still have players to treat keep going
    //we should show where they are, how many victory points they have, their current health, their energy cube total
    //their name

    std::cout << std::left << std::setw(columnWidth) << curr -> getData() -> getName() << std::right << std::setw(columnWidth);
    std::cout << std::left << std::setw(columnWidth) << curr -> getData() -> getHealth();
    std::cout << std::left << std::setw(columnWidth) << curr -> getData() -> getVictoryPoints();
    std::cout << std::left << std::setw(columnWidth) << curr -> getData() -> getEnergy();
    //finally we need to output their current location
    int currentZone = curr -> getData() -> getZone();
    Graph<std::string>* map = MapLoader::getMap();

    std::cout << std::setw(columnWidth) << map -> getVertex(currentZone) -> getName() << std::endl;
    curr = curr -> getNext();
  }

  std::cout << std::endl;


}