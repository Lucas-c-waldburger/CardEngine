#include <iostream>
#include "Deck.h"
#include "Hand.h"
#include "WinState.h"


void testDiscard(Hand& hand) {
    int cardValue;
    int cardSuit;
    hand.print();
    std::cout << "Choose a card to discard: ";
    std::cin >> cardValue >> cardSuit;
    hand.replaceInPlace(cardValue, cardSuit);
    std::cout << '\n';
    hand.print();
}

void testDraw(Hand& hand) {
    int cardValue;
    int cardSuit;
    hand.print();
    std::cout << "Choose a card to draw: ";
    std::cin >> cardValue >> cardSuit;
    hand.drawSpecific(cardValue, cardSuit);
    std::cout << '\n';
    hand.print();
}


int main() {
    CardArt cardArt;
    Deck deck(52);
    DiscardPile discardPile(deck.getStartingSize(), deck);
    Hand p1Hand(5, deck, discardPile);



//    Hand player2Hand(5, deck);
//    deck.orderByValue();
    for (int i = 0; i < p1Hand.getCurrentSize(); i++) {
        std::cout << p1Hand.cards[i]->getValue() << ", " << p1Hand.cards[i]->getSuit() << '\n';
    }

    std::cout << "---------------------" << '\n';


    p1Hand.discardRand(2);


    for (int i = 0; i < p1Hand.getCurrentSize(); i++) {
        std::cout << p1Hand.cards[i]->getValue() << ", " << p1Hand.cards[i]->getSuit() << '\n';
    }

    std::cout << "---------------------" << '\n';

    for (int i = 0; i < discardPile.getCurrentSize(); i++) {
        std::cout << discardPile.cards[i]->getValue() << ", " << discardPile.cards[i]->getSuit() << '\n';
    }

    return 0;
}
