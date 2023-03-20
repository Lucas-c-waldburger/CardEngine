//
// Created by Lucas on 3/19/2023.
//

#ifndef CARDENGINE_DECK_H
#define CARDENGINE_DECK_H
#include "CardGroup.h"

class Deck : public CardGroup {
public:
    Deck(int maxSize);
    void populate();


};


#endif //CARDENGINE_DECK_H
