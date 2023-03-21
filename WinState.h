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
    lose = -1,
    royalFlush = 0,
    straightFlush = 1,
//    fourKind = 2,
//    fullHouse = 3,
    flush = 2,
    straight = 3,
//    threeKind = 6,
//    twoPair = 7,
//    pairJacksUp = 8
};

class WinState {
public:
    WinState(Hand& hand);

    Hand* hand;
    std::vector<int> cardValues;

    bool checkRoyalFlush();
    bool checkStraightFlush();
    bool checkFourKind();
    bool checkFullHouse();
    bool checkFlush();
    bool checkStraight();
    bool checkThreeKind();
    bool checkTwoPair();
    void checkPairJacksUp();


    int getState();



private:
    int numOfStates;
    std::vector<bool> states;

    bool isRoyalFlush;
    bool isStraightFlush;
    bool isFourKind;
    bool isFullHouse;
    bool isFlush;
    bool isStraight;
    bool isThreeKind;
    bool isTwoPair;
    bool isPairJacksUp;
};


#endif //CARDENGINE_WINSTATE_H
