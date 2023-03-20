//
// Created by Lucas on 3/19/2023.
//

#include "WinState.h"

WinState::WinState(Hand& hand) {
    this->hand = &hand;
}


bool WinState::isStraight() {
    hand->orderByValue();
    for (int i = 0; i < hand->getCurrentSize() - 1; i++) {
        if (hand->cards[i]->getValue() != hand->cards[i + 1]->getValue() - 1) {
            return false;
        }
    }
    return true;
}

bool WinState::isFlush() {
    for (int i = 0; i < hand->getCurrentSize() - 1; i++) {
        if (hand->cards[i]->getSuit() != hand->cards[i + 1]->getSuit()) {
            return false;
        }
    }
    return true;
}

bool WinState::isStraightFlush() {
    if (this->isStraight() && this->isFlush()) {
        return true;
    }
    return false;
}

bool WinState::isRoyalFlush() {
    if ((this->isStraightFlush()) && (hand->cards[0]->getValue() == 10)) {
        return true;
    }
    return false;
}

