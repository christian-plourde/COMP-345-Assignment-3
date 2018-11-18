#ifndef HUMANPLAYERSTRATEGY_H
#define HUMANPLAYERSTRATEGY_H

#include "Strategy.h"
//#include "Player.h"
//#include "CardDeck.h"
#include "../../Player/Player.h"
#include "../../Deck/CardDeck.h"

class HumanPlayerStrategy : public Strategy {
public:
	void execute(Player* playerData, CardDeck* cardDeck);
};
#endif