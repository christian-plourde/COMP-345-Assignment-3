#include "GamePhaseObserver.h"

//this file contains the implementation for the methods defined in the file included above

GamePhaseObserver::GamePhaseObserver(Subject* s)
{
  subject = s; //point our subject member to the passed subject
}

void GamePhaseObserver::Update()
{
  //this method will output a message that shows who's turn it is and what they are doing
  std::cout << "some message" << std::endl;
}