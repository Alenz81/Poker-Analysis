//
// Created by super on 3/28/2023.
//

#ifndef POKER_ANALYSIS_POKERANALYSIS_H
#define POKER_ANALYSIS_POKERANALYSIS_H
#include "CardHandScorer.h"
#include "RowOfCardsPoker.h"

class PokerAnalysis {
private:
    RowOfCardsPoker uniqueHands[10];
    int listOfScores[10] = {0};
    int runs;
public:
    PokerAnalysis();
    bool isNotFull();
    void runAnalysis();
    CardHand deckAndHand();
    void drawAnalysis();




    friend std::ostream& operator<<(std::ostream& out, PokerAnalysis pokerAnalysis);
};


#endif //POKER_ANALYSIS_POKERANALYSIS_H
