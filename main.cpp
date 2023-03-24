#include <iostream>
#include "Deck.h"
#include "Hand.h"
#include "WinState.h"



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
    std::string filepath = "/Users/lowerschoolmusic/Desktop/CardEngine/CardImages";
    ArtFiles artFiles = ArtFiles(filepath);
    Deck deck(52);
    std::cout << deck.cards[0]->getValue() << ", " << deck.cards[0]->getSuit() << '-' << deck.cards[0]->getArtFilename();
    DiscardPile discardPile(deck.getStartingSize(), deck);
//
//    Hand p1Hand(5, deck, discardPile, 11, 9, 10, 8, 12, 2, 0, 0, 0, 0);
//
//
//    for (int i = 0; i < p1Hand.getCurrentSize(); i++) {
//        std::cout << p1Hand.cards[i]->getValue() << ", " << p1Hand.cards[i]->getSuit() << '\n';
//    }
//    std::cout << "---------------------" << '\n';
//
//    Hand hand(5, deck, discardPile);
//    WinState winState;
//    int winResult;
//    for (int n = 0; n < 100000; n++) {
//        hand.discardAll();
//        discardPile.shuffleBackIntoDeck();
//        hand.drawTilFull();
//        winState = WinState(hand);
//        winResult = winState.getState();
//        if (winResult >= straightFlush) {
//            for (int i = 0; i < hand.getCurrentSize(); i++) {
//                std::cout << hand.cards[i]->getValue() << ", " << hand.cards[i]->getSuit() << '\n';
//            }
//            std::cout << "------" << '\n';
//            std::cout << getStateAlpha(winResult) << '\n';
//            std::cout << "---------------------" << '\n';
//        }
//    }

//    Hand playerHand(1, deck, discardPile);
//    for (int i = 0; i < 5; i++) {
//
//        playerHand.drawSpecific(playerHand.cards[playerHand.getCurrentSize()-1]->getValue()+1,
//                           playerHand.cards[playerHand.getCurrentSize()-1]->getSuit());
//    }

//    std::cout << "------" << '\n';
//    playerHand.chooseHolds();
//    std::cout << "------" << '\n';
//    playerHand.print();
//
//    WinState winState = WinState(playerHand);
//    int winResult = winState.getState();
//    std::cout << "------" << '\n';
//    std::cout << getStateAlpha(winResult) << '\n';
//    std::cout << "---------------------" << '\n';



    return 0;
}
