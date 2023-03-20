//
// Created by Lucas on 3/19/2023.
//

#include "Deck.h"

Deck::Deck(int maxSize) : CardGroup(maxSize) {
    populate();
    shuffle();
}

void Deck::populate() {
    for (int s = 0; s < 4; s++) {
        for (int n = 2; n < 15; n++) {
            cards.emplace_back(std::make_unique<Card>(n, s));
        }
    }
}

