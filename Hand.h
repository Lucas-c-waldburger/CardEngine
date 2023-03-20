//
// Created by Lucas on 3/19/2023.
//

#ifndef CARDENGINE_HAND_H
#define CARDENGINE_HAND_H
#include "Deck.h"
#include "DiscardPile.h"

class Hand : public CardGroup {
public:
    Hand(int maxSize, Deck& deck, DiscardPile& discardPile);

    Deck* parentDeck;
    DiscardPile* parentDiscardPile;

    void draw(int numCards);
    void drawTilFull();

};


#endif //CARDENGINE_HAND_H
