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

bool Credits::operator==(const int &otherAmount) const {
    return (amount == otherAmount);
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

