//
// Created by super on 3/21/2023.
//

#include "Suits.h"

Suits::Suits() : sSuits("N/A"), numSuits(-1) {}

Suits::Suits(std::string suit) : sSuits(suit), numSuits(suitToInt(suit)){}

Suits::Suits(int suit) : sSuits(suitToString(suit)), numSuits(suit){}

std::string Suits::suitToString(int suit){
    switch(suit) {
        case 0:
            return "Hearts";
        case 1:
            return "Clubs";
        case 2:
            return "Diamonds";
        case 3:
            return  "Spades";
        default:
            return "N/A";
    }
}

int Suits::suitToInt(std::string suit) {
    if (suit == "Hearts"){
        return 0;
    } else if (suit == "Clubs"){
        return 1;
    } else if (suit == "Diamonds"){
        return 2;
    } else if (suit == "Spades"){
        return 3;
    }
    return 0;
}


void Suits::setSuit(int suit){
    numSuits = suit;
    sSuits = suitToString(suit);
}

int Suits::getNum() const{
    return numSuits;
}

std::string Suits::getString() const{
    return sSuits;
}

bool operator !=(Suits a, Suits b){
    return a.getNum() != b.getNum();
}