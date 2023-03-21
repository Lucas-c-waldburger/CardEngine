//
// Created by Lucas on 3/19/2023.
//

#include "Hand.h"

Hand::Hand(int maxSize, Deck& deck, DiscardPile& discardPile) : CardGroup(maxSize) {
    this->parentDeck = &deck;
    this->parentDiscardPile = &discardPile;
    drawTilFull();
}

Hand::Hand(int maxSize, Deck& deck, DiscardPile& discardPile, int value1, int value2, int value3, int value4, int value5,
           int suit1, int suit2, int suit3, int suit4, int suit5) : CardGroup(maxSize) {
    this->parentDeck = &deck;
    this->parentDiscardPile = &discardPile;
    drawSpecific(value1, suit1);
    drawSpecific(value2, suit2);
    drawSpecific(value3, suit3);
    drawSpecific(value4, suit4);
    drawSpecific(value5, suit5);

}


void Hand::draw(int numCards) {
    for (int i = 0; i < numCards; i++) {
        this->cards.emplace_back(std::move(parentDeck->cards.back()));
        parentDeck->cards.pop_back();
    }
}

void Hand::drawSpecific(int value, int suit) {
    int size = parentDeck->getCurrentSize();
    for (int i = 0; i < size; i++) {
        if ((parentDeck->cards[i]->getValue() == value) && (parentDeck->cards[i]->getSuit() == suit)) {
            std::rotate(parentDeck->cards.begin(), parentDeck->cards.begin() + (i + 1), parentDeck->cards.end());
            this->cards.emplace_back(std::move(parentDeck->cards.back()));
            parentDeck->cards.pop_back();
            std::rotate(parentDeck->cards.begin(), parentDeck->cards.begin() + (parentDeck->getCurrentSize() - i), parentDeck->cards.end());
            break;
        }
    }
}

void Hand::drawTilFull() {
    for (int i = getCurrentSize(); i < getStartingSize(); i++) {
        this->cards.emplace_back(std::move(parentDeck->cards.back()));
        parentDeck->cards.pop_back();
    }
}

void Hand::discard(int value, int suit) {
    int size = getCurrentSize();
    for (int i = 0; i < size; i++) {
        if ((this->cards[i]->getValue() == value) && (this->cards[i]->getSuit() == suit)) {
            std::rotate(this->cards.begin(), this->cards.begin() + (i + 1), this->cards.end());
            parentDiscardPile->cards.emplace_back(std::move(this->cards.back()));
            this->cards.pop_back();
            std::rotate(this->cards.begin(), this->cards.begin() + (getCurrentSize() - i), this->cards.end());
            break;
        }
    }
}

void Hand::discardRand(int numCards) {
    for (int i = 0; i < numCards; i++) {
        setDistrib(0, getCurrentSize() - 1);
        int randNum = getRand();

        std::rotate(this->cards.begin(), this->cards.begin() + (randNum + 1), this->cards.end());
        parentDiscardPile->cards.emplace_back(std::move(this->cards.back()));
        this->cards.pop_back();
        std::rotate(this->cards.begin(), this->cards.begin() + (getCurrentSize() - randNum), this->cards.end());
    }
}

void Hand::discardAll() {
    int size = getCurrentSize();
    for (int i = 0; i < size; i++) {
        parentDiscardPile->cards.emplace_back(std::move(this->cards.back()));
        this->cards.pop_back();
    }
}



void Hand::replaceInPlace(int value, int suit) {
    int size = getCurrentSize();
    for (int i = 0; i < size; i++) {
        if ((this->cards[i]->getValue() == value) && (this->cards[i]->getSuit() == suit)) {
            std::rotate(this->cards.begin(), this->cards.begin() + (i + 1), this->cards.end());
            parentDiscardPile->cards.emplace_back(std::move(this->cards.back()));
            this->cards.pop_back();
            this->cards.emplace_back(std::move(parentDeck->cards.back()));
            std::rotate(this->cards.begin(), this->cards.end() - (i + 1), this->cards.end());
            break;
        }
    }
}