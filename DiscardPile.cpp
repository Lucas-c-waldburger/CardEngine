//
// Created by Lucas on 3/19/2023.
//

#include "DiscardPile.h"

DiscardPile::DiscardPile(int maxSize, Deck& deck) : CardGroup(maxSize) {
    this->parentDeck = &deck;
}

void DiscardPile::shuffleBackIntoDeck() {
    int size = getCurrentSize();
    for (int i = 0; i < size; i++) {
        parentDeck->cards.emplace_back(std::move(this->cards.back()));
        this->cards.pop_back();
    }
    parentDeck->shuffle();
}


