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

std::string getStateAlpha(int state) {
    if (state == royalFlush) {
        return "Royal Flush";
    }if (state == straightFlush) {
        return "Straight Flush";
    }if (state == fourKind) {
        return "Four of a Kind";
    }if (state == fullHouse) {
        return "Full House";
    }if (state == flush) {
        return "Flush";
    }if (state == straight) {
        return "Straight";
    }if (state == threeKind) {
        return "Three of a Kind";
    }if (state == twoPair) {
        return "Two Pair";
    }if (state == pairJacksUp) {
        return "Pair of Jacks+";
    }
    else {
        return "Lose";
    }
}


int main() {
    CardArt cardArt;
    Deck deck(52);
    DiscardPile discardPile(deck.getStartingSize(), deck);

    Hand p1Hand(5, deck, discardPile);

//    deck.orderByValue();
//    deck.print();

//    Hand player2Hand(5, deck);
//    deck.orderByValue();
//    p1Hand.orderByValue();
    for (int i = 0; i < p1Hand.getCurrentSize(); i++) {
        std::cout << p1Hand.cards[i]->getValue() << ", " << p1Hand.cards[i]->getSuit() << '\n';
    }
    std::cout << "---------------------" << '\n';
////
////
//    std::vector<int> cardValues;
//    for (std::unique_ptr<Card> &card: p1Hand.cards) {
//        cardValues.push_back(card->getValue());
//    }
//
//
//
//    auto it = std::adjacent_find(cardValues.begin(), cardValues.end());
//    int firstPairIndex = -1;
//    int secondPairIndex = -1;
////
//    if (it == cardValues.end()) {
//        std::cout << "no matches" << '\n';
//    }
//    else {
//        firstPairIndex = std::distance(cardValues.begin(), it);
//    }
//
//    if (firstPairIndex > -1) {
//        // if pair found, rotate start of pair to index [0]
//        std::rotate(cardValues.begin(), cardValues.begin() + firstPairIndex, cardValues.end());
//        std::cout << "[" << cardValues[0] << ", "
//                  << cardValues[1] << ", "
//                  << cardValues[2] << ", "
//                  << cardValues[3] << ", "
//                  << cardValues[4] << "]" << '\n';
//        // checks if at least 3 in row
//        if (cardValues[1] == cardValues[2]) {
//            // checks if 4 in row
//            if (cardValues[2] == cardValues[3]) {
//                std::cout << "Four of a kind" << '\n';
//            }
//            else {
//                // if only 3 in row, checks if last two cards are a different pair for full house
//                if (cardValues[firstPairIndex + 3] == cardValues[firstPairIndex + 4]) {
//                    std::cout << "Full House" << '\n';
//                }
//                // if last two cards not a pair, we know it's three of a kind
//                else {
//                    std::cout << "Three of a kind";
//                }
//
//            }
//        }
//        // confirmed it's just two in a row
//        else {
//
//            // check if another pair exists beyond the first pair
//            it = std::adjacent_find(cardValues.begin() + 2, cardValues.end());
//            if (it == cardValues.end()) {
//                std::cout << "No additional Pairs" << '\n';
//            }
//            else {
//                secondPairIndex = std::distance(cardValues.begin(), it);
//            }
//
//            if (secondPairIndex > -1) {
//                //we know that index of start of second pair could either be index pos [2] or [3]
//                //check if in index pos [2]
//                if (secondPairIndex == 2) {
//                    //now we know there's a possibility of a full house. wont be three of a kind, because
//                    //a pair exists at index pos [1] and [2]
//
//                    if (cardValues[3] == cardValues[4]) {
//                        std::cout << "Full House" << '\n';
//                    } else {
//                        std::cout << "Two Pair" << '\n';
//                    }
//                }
//                // now check for two pair
//                else if (secondPairIndex == 3) {
//                    if (cardValues[3] == cardValues[4]) {
//                        std::cout << "Two Pair";
//                    }
//                }
//            }
//            //since no other pairs found, finally check to see if first pair is jacks or better
//            else if (cardValues[0] > 10) {
//                std::cout << "Pair of Jacks or Better" << '\n';
//            }
//        }
//    }
//
//
////    p1Hand.discardRand(2);
////
////
////    for (int i = 0; i < p1Hand.getCurrentSize(); i++) {
////        std::cout << p1Hand.cards[i]->getValue() << ", " << p1Hand.cards[i]->getSuit() << '\n';
////    }
////
////    std::cout << "---------------------" << '\n';
////
////    for (int i = 0; i < discardPile.getCurrentSize(); i++) {
////        std::cout << discardPile.cards[i]->getValue() << ", " << discardPile.cards[i]->getSuit() << '\n';
////    }

    WinState winstate(p1Hand);

    std::cout << getStateAlpha(winstate.getState());

    return 0;
}
