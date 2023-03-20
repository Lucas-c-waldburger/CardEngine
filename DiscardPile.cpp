//
// Created by Lucas on 3/19/2023.
//

#include "DiscardPile.h"

DiscardPile::DiscardPile(int maxSize, Deck& deck) : CardGroup(maxSize) {
    this->parentDeck = &deck;
}

void DiscardPile::shuffleBackIntoDeck() {
    for (int i = 0; i < this->getCurrentSize(); i ++) {
        parentDeck->cards.emplace_back(std::move(this->cards.back()));
        this->cards.erase(this->cards.end());
    }
    parentDeck->shuffle();
}


