#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>
class Player;
class CardDeck;
using namespace std;


class Strategy {
	public:
		virtual void execute(Player* playerData, CardDeck* cardDeck) = 0;
};
#endif