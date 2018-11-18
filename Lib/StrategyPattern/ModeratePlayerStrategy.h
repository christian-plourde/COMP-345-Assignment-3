#ifndef MODERATEPLAYERSTRATEGY_H
#define MODERATEPLAYERSTRATEGY_H

#include "Strategy.h"
//#include "Player.h"
//#include "CardDeck.h"
#include "../../Player/Player.h"
#include "../../Deck/CardDeck.h"

class ModeratePlayerStrategy : public Strategy {
public:
	void execute(Player* playerData, CardDeck* cardDeck);
};
#endif