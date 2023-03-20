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

void Hand::drawSpecific(int value, int suit) {
    int size = parentDeck->getCurrentSize();
    for (int i = 0; i < size; i ++) {
        if ((parentDeck->cards[i]->getValue() == value) && (parentDeck->cards[i]->getSuit() == suit)) {
            this->cards.emplace_back(std::move(parentDeck->cards[i]));
            parentDeck->cards.erase(this->cards.begin() + i);
            break;
        }
    }
}

void Hand::drawTilFull() {
    for (int i = getCurrentSize(); i < getStartingSize(); i ++) {
        this->cards.emplace_back(std::move(parentDeck->cards.back()));
        parentDeck->cards.erase(parentDeck->cards.end());
    }
}

void Hand::discard(int value, int suit) {
    int size = getCurrentSize();
    for (int i = 0; i < size; i ++) {
        if ((this->cards[i]->getValue() == value) && (this->cards[i]->getSuit() == suit)) {
            parentDiscardPile->cards.emplace_back(std::move(this->cards[i]));
            this->cards.erase(this->cards.begin() + i);
            break;
        }
    }
}

