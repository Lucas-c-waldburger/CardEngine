//
// Created by Lucas on 3/19/2023.
//

#ifndef CARDENGINE_WINSTATE_H
#define CARDENGINE_WINSTATE_H
#include "Hand.h"
#include <iostream>
#include <vector>
#include <memory>


enum WinStateNames {
    royalFlush = 8,
    straightFlush = 7,
    fourKind = 6,
    fullHouse = 5,
    flush = 4,
    straight = 3,
    threeKind = 2,
    twoPair = 1,
    pairJacksUp = 0,
    lose = -1,
};

class WinState {
public:
    WinState() = default;
    explicit WinState(Hand& hand);

    Hand* hand;

    bool checkFlush();
    bool checkStraight();

    int getPairIndex(int startingIndex);
    int determineMultiplesWinState();
    int determineOrderedWinState();
    int getState();

private:
    std::vector<int> cardValues;

};


#endif //CARDENGINE_WINSTATE_H
