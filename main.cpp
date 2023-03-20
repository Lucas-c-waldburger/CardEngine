#include <iostream>
#include "Deck.h"
#include "Hand.h"
#include "WinState.h"

int main() {
    CardArt cardArt;
    Deck deck(52);
    DiscardPile discardPile(deck.getStartingSize(), deck);
    Hand p1Hand(5, deck, discardPile);
//    Hand player2Hand(5, deck);

    p1Hand.print();
    WinState winState(p1Hand);
    std::cout << winState.getState();

    return 0;
}
