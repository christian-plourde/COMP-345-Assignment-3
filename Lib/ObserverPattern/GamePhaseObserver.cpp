#include "GamePhaseObserver.h"
#include "../../Player/Player.h"

//this file contains the implementation for the methods defined in the file included above

GamePhaseObserver::GamePhaseObserver(Subject* s)
{
  subject = s; //point our subject member to the passed subject
}

void GamePhaseObserver::Update()
{
  //this method will output a message that shows who's turn it is and what they are doing
  //we need to downcast the subject to the player class to get its attributes
  std::cout << dynamic_cast<Player*>(subject) -> getName() << "'s turn." << std::endl;

  //now we need to determine which phase the player being observed is in
  switch(dynamic_cast<Player*>(subject) -> getPhase())
  {
    case Roll: std::cout << dynamic_cast<Player*>(subject) -> getName() << " is rolling." << std::endl;
               break;
    case Move: std::cout << dynamic_cast<Player*>(subject) -> getName() << " is moving." << std::endl;
               break;
    case Buy:  std::cout << dynamic_cast<Player*>(subject) -> getName() << " is buying cards." << std::endl;
               break;
  }


}