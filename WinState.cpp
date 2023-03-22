//
// Created by Lucas on 3/19/2023.
//

#include "WinState.h"


WinState::WinState(Hand& hand) : hand{&hand} {
    this->hand->orderByValue();
    for (std::unique_ptr<Card> &card: hand.cards) {
        cardValues.push_back(card->getValue());
    }
}

int WinState::determineOrderedWinState() {
    hand->orderByValue();
    if (checkFlush()) {
        if (checkStraight()) {
            if (hand->cards[0]->getValue() == 10) {
                return royalFlush;
            } else {
                return straightFlush;
            }
        } else {
            return flush;
        }
    }
    if (checkStraight()) {
        return straight;
    }
    return lose;
}

bool WinState::checkStraight() {
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


int WinState::getState() {
    int orderedState = determineOrderedWinState();
    int multiplesState = determineMultiplesWinState();
    if (orderedState > multiplesState) {
        return orderedState;
    }
    else {
        return multiplesState;
    }
}

int WinState::getPairIndex(int startingIndex) {
    auto it = std::adjacent_find(cardValues.begin() + startingIndex, cardValues.end());
    if (it == cardValues.end()) {
        return -1;
    }
    return std::distance(cardValues.begin(), it);
}

int WinState::determineMultiplesWinState() {
    hand->orderByValue();

    int firstPairIndex = getPairIndex(0);
    if (firstPairIndex > -1) {
        std::rotate(cardValues.begin(), cardValues.begin() + firstPairIndex, cardValues.end());

        // checks if at least 3 in row
        if (cardValues[1] == cardValues[2]) {
            // checks if 4 in row
            if (cardValues[2] == cardValues[3]) {
                return fourKind;
            }
            else {
                // if only 3 in row, checks if last two cards are a different pair for full house
                if (cardValues[3] == cardValues[4]) {
                    return fullHouse;
                }
                    // if last two cards not a pair, we know it's three of a kind
                else {
                    return threeKind;
                }
            }
        }
        //confirmed it's just two in a row
        else {
            int secondPairIndex = getPairIndex(2);
            // check if another pair exists beyond the first pair
            if (secondPairIndex > -1) {
                //we know that index of start of second pair could either be index pos [2] or [3]
                //check if in index pos [2]
                if (secondPairIndex == 2) {
                    //now we know there's a possibility of a full house. wont be three of a kind, because
                    //a pair exists at index pos [1] and [2]
                    if (cardValues[3] == cardValues[4]) {
                        return fullHouse;
                    }
                    else {
                        return twoPair;
                    }
                }
                    // now check for two pair
                else if (secondPairIndex == 3) {
                    if (cardValues[3] == cardValues[4]) {
                        return twoPair;
                    }
                }
            }
                //since no other pairs found, finally check to see if first pair is jacks or better
            else if (cardValues[0] > 10) {
                return pairJacksUp;
            }
        }
    }
    return lose;
}

