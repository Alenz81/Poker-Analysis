//
// Created by super on 3/18/2023.
//

#ifndef POKER_ANALYSIS_DECK_H
#define POKER_ANALYSIS_DECK_H
#include <iostream>
#include "CardPoker.h"

class Deck {
private:
    const int DECK_SIZE = 52;// this is the size of your deck
    CardPoker deck[52];// this is your final deck of cards
    int cardIndex; //marks the index of the next card in the deck
public:
    Deck(); // this is the constructor
    bool empty(); //returns true if deck has no cards
    void shuffle(); // puts cards in random order
    CardPoker dealCard(); // returns the next card in the deck
    CardPoker& getCardAt(int index);// gets the CardPoker at the given index
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck); // prints all the cards to the console
};


#endif //POKER_ANALYSIS_DECK_H
