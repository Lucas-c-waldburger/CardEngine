//
// Created by Lucas on 3/19/2023.
//

#ifndef CARDENGINE_WINSTATE_H
#define CARDENGINE_WINSTATE_H
#include "Hand.h"

class WinState {
public:
    WinState(Hand& hand);

    Hand* hand;

    bool isRoyalFlush();
    bool isStraightFlush();
    bool isFourKind;
    bool isFullHouse;
    bool isFlush();
    bool isStraight();
    bool isThreeKind;
    bool isTwoPair;
    bool isPairJacks;

private:

};


#endif //CARDENGINE_WINSTATE_H
