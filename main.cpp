#include <iostream>
#include "Deck.h"
#include "Hand.h"

int main() {
    CardArt cardArt;
    Deck deck(52);
    DiscardPile discardPile(deck.getStartingSize(), deck);
    Hand p1Hand(5, deck, discardPile);
//    Hand player2Hand(5, deck);

    p1Hand.print();
    p1Hand.shuffle();
    p1Hand.print();

    return 0;
}
