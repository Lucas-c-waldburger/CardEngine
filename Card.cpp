//TODO make suits into enum
//
// Created by Lucas on 3/19/2023.
//

#include "Card.h"
#include <iostream>



Card::Card(int value, int suit) {

    this->value = value;
    this->suit = suit;
    this->color = determineColor();
    this->artFilename = ArtFiles::artFilenames[value-2][suit];
}

int Card::getValue() const {
    return value;
}

void Card::setValue(int value, bool update) {
    this->value = value;
    if (update) {
        updateArtFilenameFromMatrix();
    }
}

int Card::getSuit() const {
    return suit;
}

void Card::setSuit(int suit, bool update) {
    this->suit = suit;
    if (update) {
        updateArtFilenameFromMatrix();
    }
}

std::string Card::getColor() const {
    return color;
}

void Card::setColor(std::string color) {
    this->color = color;
}

std::string Card::determineColor() {
    if (suit == diamonds || suit == hearts) {
        return "red";
    }
    else if (suit == clubs || suit == spades) {
        return "black";
    }
    return "wild";
}


std::string Card::getArtFilename() {
    return artFilename;
}

void Card::setArtFilename(std::string artFilename) {
    this->artFilename = artFilename;
}

void Card::updateArtFilenameFromMatrix() {
    this->artFilename = ArtFiles::artFilenames[value-2][suit];
}


