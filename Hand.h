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
    Hand(int maxSize, Deck& deck, DiscardPile& discardPile, int value1, int value2, int value3, int value4, int value5,
         int suit1, int suit2, int suit3, int suit4, int suit5);

    Deck* parentDeck;
    DiscardPile* parentDiscardPile;

    void draw(int numCards = 1);
    void drawSpecific(int value, int suit);
    void drawTilFull();
    void discard(int value, int suit);
    void discardRand(int numCards = 1);
    void discardAll();
    void replaceInPlace(int value, int suit);

};


#endif //CARDENGINE_HAND_H
