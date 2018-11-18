#include "HumanPlayerStrategy.h"

void HumanPlayerStrategy::execute(Player* playerData, CardDeck* cardDeck) {
	cout << "HUMAN PLAYER EXECUTE()" << endl;
	node<Player*>* curr = Player::players->getHead();				// same list of players, but used for additional traversals while inside game loop
	node<Player*>* temp = curr;
	bool playersInManhatten = false;								// check for whether any players are in any manhatten zones
	// 1. Roll the Dice (up to 3 times)
	playerData->rollDice();
	// 2. Resolve the Dice
	playerData->resolveDice();
	// CHECK IF PLAYER DIED WHILE RESOLVING THE DICE
	if (playerData->getHealth() == 0)
		return;
	// 3. Move (generally optional, sometimes mandatory)
	if (playerData) {
		// CHECK IF PLAYER IS ALREADY IN MANHATTEN
		// IF SO MOVE PLAYER UP TO NEXT ZONE
		int playerZone = playerData->getZone();
		if (playerZone == 1)
			playerData->setZone(2);
		else if (playerZone == 2)
			playerData->setZone(3);
		else if (playerZone == 4)
			playerData->setZone(5);
		else if (playerZone == 5)
			playerData->setZone(6);
		else if (playerZone != 3 || playerZone != 6) {
			// PLAYER IS NOT IN MANHATTEN
			// FIRST CHECK IF MANHATTEN HAS ANY PLAYERS IN IT
			playersInManhatten = false;
			curr = Player::players->getHead();
			while (curr) {
				playerZone = curr->getData()->getZone();
				if (playerZone <= 6) {
					playersInManhatten = true;
					break;
				}
				curr = curr->getNext();
			}
			// IF NO PLAYERS IN MANHATTEN, MOVE PLAYER THERE
			if (!playersInManhatten) {
				std::cout << "No one in Manhatten, you must move there." << std::endl;
				if (Player::getPlayerCount() < 5)
					playerData->setZone(1);
				else
					playerData->setZone(4);
			}
			else {
				// AT LEAST ONE PLAYER IN MANHATTEN, GIVE PLAYER CHOICE AS TO WHERE TO MOVE
				if (playerData->getZone() >= 7) {
					bool badInput = true;
					string answer;
					std::cout << "There is already one monster in Manhatten." << std::endl;
					std::cout << "Would you like to move(M) from or stay(S) in " << MapLoader::getMap()->getVertex(playerData->getZone())->getName() << "? (M/S): ";
					while (badInput) {
						try {
							std::cin >> answer;
							if (!(answer == "M" || answer == "S")) {
								throw answer;
							}
							badInput = false;
						}
						catch (string s) {
							std::cout << "The answer " << s << " is not valid. Please enter either M or S: ";
						}
					}
					if (answer == "M")
						playerData->move();
				}
			}

		}

		// DEAL WITH ATTACK DICE
		// PLAYER IS NOT IN MANHATTEN, ALLOW MANHATTEN PLAYERS TO MOVE OUT
		bool attack = false;
		bool traversed = false;
		playerZone = playerData->getZone();
		if (playerZone >= 7) {
			std::cout << "\n\nAllowing Manhatten players that were attacked to leave Manhattan\n";
			for (int i = 0; i < 6; i++) {
				if (playerData->getDice()->getResult()[i] == Attack) {
					attack = true;
					curr = Player::players->getHead();
					temp = curr;
					while (curr) {
						playerZone = curr->getData()->getZone();
						if (playerZone <= 6) {
							if (curr->getData()->getName() == "Aggressive CPU" || curr->getData()->getName() == "Moderate CPU") {
								curr->getData()->cpuMove();
							}
							else {
								if (curr->getData()->getHealth() == 0) {
									curr = curr->getNext();
									traversed = true;
									playerData->removePlayer(temp->getData()->getCharacter());
									temp = curr;
								}
								else {
									std::cout << "There is already one monster in Manhatten." << std::endl;
									std::cout << "Player " << curr->getData()->getName() << " you may move\n";
									bool badInput = true;
									string answer;
									std::cout << "Would you like to move(M) from or stay(S) in " << MapLoader::getMap()->getVertex(curr->getData()->getZone())->getName() << "? (M/S): ";
									while (badInput) {
										try {
											std::cin >> answer;
											if (!(answer == "M" || answer == "S")) {
												throw answer;
											}
											badInput = false;
										}
										catch (string s) {
											std::cout << "The answer " << s << " is not valid. Please enter either M or S: ";
										}
									}
									if (answer == "M")
										curr->getData()->move();
								}
							}
						}
						if(!traversed)
							curr = curr->getNext();
						traversed = false;
					}
				}
				if (attack)
					break;
			}
			std::cout << "\n\nBack to " << playerData->getName() << "'s turn\n";
		}


		// 4. Buy Cards (optional)
		playerData->buyCards(cardDeck);
		// 5. End Turn
	}
}