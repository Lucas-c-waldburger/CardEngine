//
// Created by Lucas on 3/19/2023.
//

#ifndef CARDENGINE_CARDART_H
#define CARDENGINE_CARDART_H


#include <iostream>
#include <vector>


class CardArt {
public:
    CardArt();

    static std::string arts[13][4];

private:

    std::string suits[4]{"^", "v", "&", "o"};

    std::string line1 = " _______ \n";
    std::string line2;
    std::string line3;
    std::string line4;
    std::string line5;
    std::string line6;

    std::string get2(const std::string& suit);
    std::string get3(const std::string& suit);
    std::string get4(const std::string& suit);
    std::string get5(const std::string& suit);
    std::string get6(const std::string& suit);
    std::string get7(const std::string& suit);
    std::string get8(const std::string& suit);
    std::string get9(const std::string& suit);
    std::string get10(const std::string& suit);
    std::string getJack(const std::string& suit);
    std::string getQueen(const std::string& suit);
    std::string getKing(const std::string& suit);
    std::string getAce(const std::string& suit);

    std::string combineLines();
    void populateArts();
};

#endif //CARDENGINE_CARDART_H
