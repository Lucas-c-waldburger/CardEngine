//
// Created by Lucas on 3/19/2023.
//

#ifndef CARDENGINE_CARD_H
#define CARDENGINE_CARD_H


#include <iostream>
#include "ArtFiles.h"

enum Suits {
    diamonds = 0,
    hearts = 1,
    clubs = 2,
    spades = 3,
    NUM_OF_SUITS = 4
};

enum FaceValues {
    jack = 11,
    queen = 12,
    king = 13,
    ace = 14
};

class Card {
public:
    Card(int value, int suit);

    int getValue() const;
    void setValue(int value, bool update = false);

    int getSuit() const;
    void setSuit(int suit, bool update = false);

    std::string getArtFilename();
    void setArtFilename(std::string artFilename);
    void updateArtFilenameFromMatrix();

    std::string determineColor();
    std::string getColor() const;
    void setColor(std::string color);

private:
    int value;
    int suit;
    std::string color;
    std::string artFilename;

};
#endif //CARDENGINE_CARD_H
