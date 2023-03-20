//
// Created by Lucas on 3/19/2023.
//

#ifndef CARDENGINE_DISCARDPILE_H
#define CARDENGINE_DISCARDPILE_H
#include "Deck.h"

class DiscardPile : public CardGroup {
public:
    DiscardPile(int maxSize, Deck& deck);

    Deck* parentDeck;

    void shuffleBackIntoDeck();
};


#endif //CARDENGINE_DISCARDPILE_H
