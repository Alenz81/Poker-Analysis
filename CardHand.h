//
// Created by super on 3/18/2023.
//

#ifndef POKER_ANALYSIS_CARDHAND_H
#define POKER_ANALYSIS_CARDHAND_H
#include <iostream>
#include <vector>
#include "Deck.h"

class CardHand {
private:
    std::vector<CardPoker> hand;
public:
    CardHand();
    CardHand(const std::vector<CardPoker>& hand);
    void addCard(const CardPoker& card);
    CardPoker& getCardAt(int index);
    int getSize() const;
    friend std::ostream& operator<<(std::ostream& out, const CardHand& hand);
};


#endif //POKER_ANALYSIS_CARDHAND_H
