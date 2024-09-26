//
// Created by super on 3/18/2023.
//

#include "CardHand.h"

CardHand::CardHand() : hand({}){}

CardHand::CardHand(const std::vector<CardPoker>& hand) : hand(hand){}

void CardHand::addCard(const CardPoker& card) {
    hand.push_back(card);
}

CardPoker& CardHand::getCardAt(int index){
    return hand.at(index);
}

int CardHand::getSize() const{
    return hand.size();
}

std::ostream& operator<<(std::ostream& out, const CardHand& CardHand){
    if (CardHand.hand.size() > 0) {
        for (int i = 0; i < CardHand.hand.size() - 1; i++) {
            std::cout << CardHand.hand.at(i) << ", ";
        }
        std::cout << CardHand.hand.at(CardHand.hand.size() - 1) << std::endl;
    }
    return out;
}

