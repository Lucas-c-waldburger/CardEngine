//TODO make suits into enum
//
// Created by Lucas on 3/19/2023.
//

#include "Card.h"
#include "CardArt.h"
#include <iostream>



Card::Card(int value, int suit) {

    this->value = value;
    this->suit = suit;
    this->color = determineColor();
    this->art = CardArt::arts[value-2][suit];
}

int Card::getValue() const {
    return value;
}

void Card::setValue(int value, bool update) {
    this->value = value;
    if (update) {
        updateArt();
    }
}

int Card::getSuit() const {
    return suit;
}

void Card::setSuit(int suit, bool update) {
    this->suit = suit;
    if (update) {
        updateArt();
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


std::string Card::getArt() {
    return art;
}

void Card::setArt(std::string cardArt) {
    this->art = cardArt;
}

void Card::updateArt() {
    this->art = CardArt::arts[value-2][suit];
}

std::ostream &operator<<(std::ostream &stream, const Card &card) {
    stream << card.art;
    return stream;
}
