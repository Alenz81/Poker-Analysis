//
// Created by super on 3/18/2023.
//

#ifndef POKER_ANALYSIS_POKERSCORE_H
#define POKER_ANALYSIS_POKERSCORE_H
#include <iostream>
#include <vector>

enum Scores{
    //0
    ROYAL_FLUSH, //A, K, Q, J, 10, all the same suit.
    //1
    STRAIGHT_FLUSH, //five cards of the same suit and consecutive ranking
    //2
    FOUR_OF_A_KIND, //four cards of the same ranking
    //3
    FULL_HOUSE, //three cards of the same rank along with two cards of the same rank
    //4
    FLUSH, //five cards of the same suit
    //5
    STRAIGHT, //five cards in consecutive ranking
    //6
    THREE_OK_A_KIND, //three cards of the same rank
    //7
    TWO_PAIR, //two cards of the same rank along with another two cards of the same rank
    //8
    ONE_PAIR, //two cards of the same rank
    //9
    HIGH_CARD //highest card in the player’s hand

};

class PokerScore {
private:
    std::vector<Scores> scores;
public:
    PokerScore();
    int size() const;
    void operator+=(const Scores& score);
    Scores& operator[](unsigned int index);

    friend bool operator==(const PokerScore& p, Scores score);
    friend std::ostream& operator<<(std::ostream& out, const PokerScore& p);

};


#endif //POKER_ANALYSIS_POKERSCORE_H
