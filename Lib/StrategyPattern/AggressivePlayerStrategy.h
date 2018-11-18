#ifndef AGGRESSIVEPLAYERSTRATEGY_H
#define AGGRESSIVEPLAYERSTRATEGY_H

#include "Strategy.h"
//#include "Player.h"
//#include "CardDeck.h"
#include "../../Player/Player.h"
#include "../../Deck/CardDeck.h"

class AggressivePlayerStrategy : public Strategy {
	public:
		void execute(Player* playerData, CardDeck* cardDeck);
};
#endif