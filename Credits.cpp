//
// Created by Lower School Music on 3/24/23.
//

#include "Credits.h"

Credits::Credits() {
    amount = 0;
}

Credits::Credits(int startingAmount) : amount{startingAmount} {}

int Credits::getAmount() {
    return amount;
}

void Credits::setAmount(int newAmount) {
    amount = newAmount;
}

std::strong_ordering Credits::operator<=>(const int &otherAmount) const {
    return amount <=> otherAmount;
}

Credits& Credits::operator+=(const int& otherAmount) {
    amount += otherAmount;
    return *this;
}

Credits& Credits::operator-=(const int& otherAmount) {
    amount -= otherAmount;
    return *this;
}