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
    deck.orderByValue();
    for (int i = 0; i < deck.getCurrentSize(); i++) {
        std::cout << deck.cards[i]->getValue() << ", " << deck.cards[i]->getSuit() << '\n';
    }

    p1Hand.print();

    int cardValue;
    int cardSuit;

//    std::cout << "Choose a card to discard: ";
//    std::cin >> cardValue >> cardSuit;
//    p1Hand.discard(cardValue, cardSuit);
//    std::cout << '\n';
//    p1Hand.print();

    std::cout << "Choose a card to draw: ";
    std::cin >> cardValue >> cardSuit;
    p1Hand.drawSpecific(cardValue, cardSuit);
    std::cout << '\n';
    p1Hand.print();

    return 0;
}
