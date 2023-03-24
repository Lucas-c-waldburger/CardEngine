//
// Created by Lucas on 3/19/2023.
//

#ifndef CARDENGINE_CARDGROUP_H
#define CARDENGINE_CARDGROUP_H
#include "Card.h"
#include <iostream>
#include <memory>
#include <random>

class CardGroup {
public:
    explicit CardGroup(int startingSize);

    std::vector<std::unique_ptr<Card>> cards;

    void setDistrib(int minNum, int maxNum);
    int getRand();

    int getStartingSize();
    void setStartingSize(int size);
    int getCurrentSize(bool update = true);
    void updateCurrentSize();

    void shuffle();

    void orderBySuit();
    void orderByValue();
    void orderByBoth();

//    void print();

private:
    int startingSize;
    int currentSize;

    std::mt19937 mt;
    std::random_device rd;
    std::uniform_int_distribution<> distrib;

};


#endif //CARDENGINE_CARDGROUP_H
