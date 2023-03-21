//
// Created by Lucas on 3/19/2023.
//

#include "CardGroup.h"

CardGroup::CardGroup(int startingSize) {
    this->startingSize = startingSize;
    this->currentSize = cards.size();

    mt.seed(rd());
    setDistrib(0, startingSize - 1);
}

int CardGroup::getRand() {
    return distrib(mt);
}

void CardGroup::setDistrib(int minNum, int maxNum) {
    distrib.param(std::uniform_int_distribution<int>::param_type(minNum, maxNum));
}

int CardGroup::getStartingSize() {
    return startingSize;
}

void CardGroup::setStartingSize(int size) {
    this->startingSize = size;
}


int CardGroup::getCurrentSize(bool update) {
    if (update) {
        updateCurrentSize();
    }
    return currentSize;
}

void CardGroup::updateCurrentSize() {
    this->currentSize = cards.size();
}

void CardGroup::shuffle() {
    int maxNum = getCurrentSize() - 1;
    for (int i = 0; i < maxNum; i++) {
        setDistrib(i + 1, maxNum);
        int randIndex = getRand();
        std::swap(cards[i], cards[randIndex]);
    }
}

void CardGroup::orderBySuit() {
    for (int i = 0; i < getCurrentSize(); i++) {
        for (int c = 0; c < getCurrentSize() - 1; c++) {
            if (cards[c]->getSuit() > cards[c + 1]->getSuit()) {
                std::swap(cards[c], cards[c + 1]);
            }
        }
    }
}


void CardGroup::orderByValue() {
    for (int i = 0; i < getCurrentSize(); i++) {
        for (int c = 0; c < getCurrentSize() - 1; c++) {
            if (cards[c]->getValue() > cards[c + 1]->getValue()) {
                std::swap(cards[c], cards[c + 1]);
            }
        }
    }
}

void CardGroup::print() {
    int size = getCurrentSize();
    for (int i = 0; i < size; i++) {
        std::cout << *cards[i] << '\n';
    }
}