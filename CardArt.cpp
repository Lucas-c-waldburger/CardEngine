//
// Created by Lucas on 3/19/2023.
//

#include "CardArt.h"
#include <iostream>

std::string CardArt::arts[13][4];

CardArt::CardArt() {
    populateArts();
}

std::string CardArt::combineLines() {
    return line1 + line2 + line3 + line4 + line5 + line6;
}

std::string CardArt::get2(const std::string& suit) {
    line2 = "|2      |\n";
    line3 = "|   " + suit + "   |\n";
    line4 = "|       |\n";
    line5 = line3;
    line6 = "|______2|";
    return combineLines();
}

std::string CardArt::get3(const std::string& suit) {
    line2 = "|3      |\n";
    line3 = "| " + suit + "   " + suit + " |\n";
    line4 = "|       |\n";
    line5 = "|   " + suit + "   |\n";
    line6 = "|______3|";
    return combineLines();
}
std::string CardArt::get4(const std::string& suit) {
    line2 = "|4      |\n";
    line3 = "| " + suit + "   " + suit + " |\n";
    line4 = "|       |\n";
    line5 = line3;
    line6 = "|______4|";
    return combineLines();
}
std::string CardArt::get5(const std::string& suit) {
    line2 = "|5      |\n";
    line3 = "| " + suit + "   " + suit + " |\n";
    line4 = "|   " + suit + "   |\n";
    line5 = line3;
    line6 = "|______5|";
    return combineLines();
}
std::string CardArt::get6(const std::string& suit) {
    line2 = "|6      |\n";
    line3 = "| " + suit + "   " + suit + " |\n";
    line4 = line3;
    line5 = line3;
    line6 = "|______6|";
    return combineLines();
}
std::string CardArt::get7(const std::string& suit) {
    line2 = "|7      |\n";
    line3 = "| " + suit + "   " + suit + " |\n";
    line4 = "| " + suit + " " + suit + " " + suit + " |\n";
    line5 = line3;
    line6 = "|______7|";
    return combineLines();
}
std::string CardArt::get8(const std::string& suit) {
    line2 = "|8      |\n";
    line3 = "| " + suit + " " + suit + " " + suit + " |\n";
    line4 = "|  " + suit + " " + suit + "  |\n";
    line5 = line3;
    line6 = "|______8|";
    return combineLines();
}
std::string CardArt::get9(const std::string& suit) {
    line2 = "|9      |\n";
    line3 = "| " + suit + " " + suit + " " + suit + " |\n";
    line4 = line3;
    line5 = line3;
    line6 = "|______9|";
    return combineLines();
}
std::string CardArt::get10(const std::string& suit) {
    line2 = "|10  " + suit + "  |\n";
    line3 = "| " + suit + " " + suit + " " + suit + " |\n";
    line4 = line3;
    line5 = line3;
    line6 = "|_____10|";
    return combineLines();
}
std::string CardArt::getJack(const std::string& suit) {
    line2 = "|J      |\n";
    line3 = "|   " + suit + "   |\n";
    line4 = "| " + suit + " J " + suit + " |\n";
    line5 = line3;
    line6 = "|______J|";
    return combineLines();
}
std::string CardArt::getQueen(const std::string& suit) {
    line2 = "|Q      |\n";
    line3 = "|   " + suit + "   |\n";
    line4 = "| " + suit + " Q " + suit + " |\n";
    line5 = line3;
    line6 = "|______Q|";
    return combineLines();
}
std::string CardArt::getKing(const std::string& suit) {
    line2 = "|K      |\n";
    line3 = "|   " + suit + "   |\n";
    line4 = "| " + suit + " K " + suit + " |\n";
    line5 = line3;
    line6 = "|______K|";
    return combineLines();
}
std::string CardArt::getAce(const std::string& suit) {
    line2 = "|A      |\n";
    line3 = "|   " + suit + "   |\n";
    line4 = "| " + suit + " A " + suit + " |\n";
    line5 = line3;
    line6 = "|______A|";
    return combineLines();
}


void CardArt::populateArts() {
    for (int i = 0; i < 4; i++) {
        arts[0][i] = get2(suits[i]);
        arts[1][i] = get3(suits[i]);
        arts[2][i] = get4(suits[i]);
        arts[3][i] = get5(suits[i]);
        arts[4][i] = get6(suits[i]);
        arts[5][i] = get7(suits[i]);
        arts[6][i] = get8(suits[i]);
        arts[7][i] = get9(suits[i]);
        arts[8][i] = get10(suits[i]);
        arts[9][i] = getJack(suits[i]);
        arts[10][i] = getQueen(suits[i]);
        arts[11][i] = getKing(suits[i]);
        arts[12][i] = getAce(suits[i]);
    }
}


