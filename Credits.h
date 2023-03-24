//
// Created by Lower School Music on 3/24/23.
//

#ifndef CARDENGINE_CREDITS_H
#define CARDENGINE_CREDITS_H
#include <iostream>
#include <compare>

class Credits {
public:
    Credits();
    Credits(int startingAmount);

    int getAmount();
    void setAmount(int newAmount);

    std::strong_ordering operator<=>(const int& otherAmount) const;
    Credits& operator+=(const int& otherAmount);
    Credits& operator-=(const int& otherAmount);

private:
    int amount;


};




#endif //CARDENGINE_CREDITS_H
