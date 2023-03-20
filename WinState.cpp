//
// Created by Lucas on 3/19/2023.
//

#include "WinState.h"

WinState::WinState(Hand& hand) {
    this->hand = &hand;
    numOfStates = 9;
//    isRoyalFlush = checkRoyalFlush();
//    isStraightFlush = checkStraightFlush();
//    isFourKind = checkFourKind();
//    isFullHouse = checkFullHouse();
//    isFlush = checkFlush();
//    isStraight = checkStraight();
//    isThreeKind = checkThreeKind();
//    isTwoPair = checkTwoPair();
//    isPairJacksUp = checkPairJacksUp();

    states.push_back(checkRoyalFlush());
    states.push_back(checkStraightFlush());
    states.push_back(checkFourKind());
    states.push_back(checkFullHouse());
    states.push_back(checkFlush());
    states.push_back(checkStraight());
    states.push_back(checkThreeKind());
    states.push_back(checkTwoPair());
    states.push_back(checkPairJacksUp());
}


bool WinState::checkStraight() {
    hand->orderByValue();
    for (int i = 0; i < hand->getCurrentSize() - 1; i++) {
        if (hand->cards[i]->getValue() != hand->cards[i + 1]->getValue() - 1) {
            return false;
        }
    }
    return true;
}

bool WinState::checkFlush() {
    for (int i = 0; i < hand->getCurrentSize() - 1; i++) {
        if (hand->cards[i]->getSuit() != hand->cards[i + 1]->getSuit()) {
            return false;
        }
    }
    return true;
}

bool WinState::checkStraightFlush() {
    if (this->isStraight && this->isFlush) {
        return true;
    }
    return false;
}

bool WinState::checkRoyalFlush() {
    if ((this->isStraightFlush) && (hand->cards[0]->getValue() == 10)) {
        return true;
    }
    return false;
}

int WinState::getState() {
    for (int i = 0; i < numOfStates; i++) {
        if (states[i]) {
            return i;
        }
    }
    return lose;
}

