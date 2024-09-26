//
// Created by super on 3/21/2023.
//

#ifndef POKER_ANALYSIS_SUITS_H
#define POKER_ANALYSIS_SUITS_H
#include <iostream>

class Suits {
private:
    std::string sSuits;
    int numSuits;
public:
    Suits();
    Suits(std::string suit);
    Suits(int suit);
    std::string suitToString(int suit);
    int suitToInt(std::string suit);
    void setSuit(int suit);
    int getNum() const;
    std::string getString() const;

    friend bool operator !=(Suits a, Suits b);
};


#endif //POKER_ANALYSIS_SUITS_H
