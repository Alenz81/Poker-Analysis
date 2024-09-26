//
// Created by super on 3/18/2023.
//

#ifndef POKER_ANALYSIS_CARDHANDSCORER_H
#define POKER_ANALYSIS_CARDHANDSCORER_H
#include "PokerScore.h"
#include "CardHand.h"

class CardHandScorer {
private:
    static bool inOrder(CardHand hand);
    static Scores pairs(CardHand hand);
public:
    static void sort(CardHand& hand);
    CardHandScorer();
    static PokerScore scorePokerHand(CardHand &hand);
    static void addAdditional(PokerScore &pokerScore);
    static void isSequentialAndSameSuit(CardHand hand, bool &isSequential, bool &isOneSuit, bool &aceFail, bool &isAce);
};
//a static function that takes a CardHand object as an argument.
// The purpose of this static function is to return the score for the Poker hand.
// This score will be stored in a PokerScore object that is mention in the next section.
//
//The function should analyze the CardHand and add all possible scores to the PokerScore object in which it will then return this object.

#endif //POKER_ANALYSIS_CARDHANDSCORER_H
