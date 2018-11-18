/*#include "../Dice/Dice.h"
#include "../Player/Player.h"
#include "../MapLoader/MapLoader.h"
#include "../Lib/GameSetupFunctions.h"*/
#include "Dice.h"
#include "Player.h"
#include "MapLoader.h"
#include "GameSetupFunctions.h"

#include <iostream>
#include <string>

int main()
{
	//welcome message
	std::cout << "------------------------------" << std::endl;
	std::cout << "|      KING OF NEW YORK      |" << std::endl;
	std::cout << "|    BY CHRISTIAN PLOURDE    |" << std::endl;
	std::cout << "|       AND JACK BURNS       |" << std::endl;
	std::cout << "------------------------------" << std::endl;

	//MapLoader::loadMap("D:\\Computer Science Assignments\\COMP 345 Assignments\\A2\\Maps");
	MapLoader::loadMap();
	std::cout << MapLoader::getMap()->toString() << std::endl;

	bool playerCountIsValid = false; // a boolean to store whether or not the playerCount is valid
	int playerCount; //the number of players that will be playing the game

	//first we need to determine how many players will be playing the game
	while (!playerCountIsValid)
	{
		//while the player count is still not valid, keep prompting the user
		try
		{
			playerCount = GameSetupFunctions::getNumberOfPlayers();
			playerCountIsValid = true;
		}

		//catch the number of players that was entered as thrown in function
		catch (int e)
		{
			std::cout << "The number of players should be between 2 and 6. Please try again." << std::endl;
		}

	}

	//now that we have set the number of players playing the game it is time to initialize their player characters
	GameSetupFunctions::initializePlayers(playerCount);

	//now let's set the order in which they will play
	GameSetupFunctions::setPlayerTurnOrder();

	GameSetupFunctions::setPlayerStartZones(); //set the zones where the players will begin

	std::cout << "Ready to begin the game!" << std::endl; //ready to start!

	TileDeck* deck = new TileDeck();								// creates a deck of tiles
	node<Player*>* playerNodes = Player::players->getHead();		// list of players to go through for game loop
	Player* playerData = playerNodes->getData();					// holds data about current player
	CardDeck* cardDeck = new CardDeck();							// creates a deck of cards
	
	
	const int WINNING_VICTORY_POINTS = 20;							// total number of victory points required for winning
	bool hasWon = false;											// flag for if any player has won

	// MAIN GAME LOOP
	// LOOP RUNS WHILE THERE ARE MORE THAN ONE PLAYERS IN THE GAME
	while (Player::players->getCount() > 1) {
		// CHECK IF ANY PLAYERS HAVE 20 VICTORY POINTS
		playerNodes = Player::players->getHead();
		while (playerNodes) {
			playerData = playerNodes->getData();
			if (playerData->getVictoryPoints() == WINNING_VICTORY_POINTS)
				hasWon = true;
			playerNodes = playerNodes->getNext();
		}
		if (hasWon)
			break;

		// NO WINNING PLAYER YET, KEEP PLAYING GAME
		playerNodes = Player::players->getHead();
		while (playerNodes) {
			playerData = playerNodes->getData();
			playerData->executeStrategy(playerData, cardDeck);
			if (playerData->getHealth() == 0)
				break;
			playerNodes = playerNodes->getNext();
		}
	}

	// WINNING DUE TO BEING ONLY PLAYER LEFT
	if (Player::players->getCount() == 1)
		std::cout << "CONGRATULATIONS!! " << Player::players->getHead()->getData()->getName() << " HAS WON!" << std::endl;
	else {
		// WINNING DUE TO GETTING 20 VICTORY POINTS
		// HAVE TO FIND THAT WINNER AND DISPLAY THEM
		playerNodes = Player::players->getHead();
		while (playerNodes) {
			playerData = playerNodes->getData();
			if (playerData->getVictoryPoints() == WINNING_VICTORY_POINTS) {
				std::cout << "CONGRATULATIONS!! " << playerData->getName() << " HAS WON!" << std::endl;
				break;
			}
			playerNodes = playerNodes->getNext();
		}
	}
	// CLEAN UP POINTERS
	delete deck;
	deck = NULL;
	playerNodes = NULL;
	delete playerData;
	playerData = NULL;
	delete cardDeck;
	cardDeck = NULL;
	std::system("pause");
	return 0;
}