//
// Created by Lucas on 3/19/2023.
//

#include "Hand.h"

Hand::Hand(int maxSize, Deck& deck, DiscardPile& discardPile) : CardGroup(maxSize) {
    this->parentDeck = &deck;
    this->parentDiscardPile = &discardPile;
    drawTilFull();
}

void Hand::draw(int numCards) {
    for (int i = 0; i < numCards; i ++) {
        this->cards.emplace_back(std::move(parentDeck->cards.back()));
        parentDeck->cards.erase(parentDeck->cards.end());
    }
}

void Hand::drawTilFull() {
    for (int i = getCurrentSize(); i < getStartingSize(); i ++) {
        this->cards.emplace_back(std::move(parentDeck->cards.back()));
        parentDeck->cards.erase(parentDeck->cards.end());
    }
}

