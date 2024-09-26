//
// Created by super on 3/18/2023.
//

#include "CardHandScorer.h"

CardHandScorer::CardHandScorer() {}

void CardHandScorer::sort(CardHand& hand) {
    while (!inOrder(hand)) {
        for (int i = 0; i < hand.getSize() - 1; i++) {
            CardPoker temp = hand.getCardAt(i);
            if (temp.getRank() < hand.getCardAt(i + 1).getRank()){
                hand.getCardAt(i) = hand.getCardAt(i + 1);
                hand.getCardAt( i + 1) = temp;
            }
        }
    }
}

bool CardHandScorer::inOrder(CardHand hand){
    for (int i = 0; i < hand.getSize(); i++){
        for (int j = i + 1; j < hand.getSize(); j++){
            if (hand.getCardAt(i).getRank() < hand.getCardAt(j).getRank()){
                return false;
            }
        }
    }
    return true;
}

Scores CardHandScorer::pairs(CardHand hand){
    int highestCardAmt;
    int amtPairs(0);
    int cardsInHand[13] = {0};
    for (int i = 0; i < hand.getSize(); i++){
        cardsInHand[hand.getCardAt(i).getRank().getNum()]++;
    }
    highestCardAmt = cardsInHand[0];
    for (int i = 0; i < 13; i++){
        if (cardsInHand[i] >= 2){
            amtPairs += cardsInHand[i]/2;
        }
        if (cardsInHand[i] > highestCardAmt){
            highestCardAmt = cardsInHand[i];
        }
    }
    if (highestCardAmt == 4){
        return FOUR_OF_A_KIND;
    } else if (highestCardAmt == 3){
        if (amtPairs >= 2){
            return FULL_HOUSE;
        }
        return THREE_OK_A_KIND;
    } else if (amtPairs == 2){
        return TWO_PAIR;
    } else if (amtPairs == 1){
        return ONE_PAIR;
    } else {
        return HIGH_CARD;
    }
}

PokerScore CardHandScorer::scorePokerHand(CardHand &hand) {
    sort(hand);
    bool isSequential(true);
    bool isOneSuit(true);
    bool isAce(false);
    bool aceFail(false);
    PokerScore pokerScore;
    isSequentialAndSameSuit(hand, isSequential, isOneSuit, aceFail, isAce);

    if(isSequential){
        if (isOneSuit){
            pokerScore += STRAIGHT_FLUSH;
        }
        pokerScore += STRAIGHT;
    }

    if (isOneSuit){
        if (isAce){
            pokerScore += ROYAL_FLUSH;
        }
        pokerScore += FLUSH;
    }

    pokerScore += pairs(hand);
    addAdditional(pokerScore);

    return pokerScore;
}

void CardHandScorer::isSequentialAndSameSuit(CardHand hand, bool &isSequential, bool &isOneSuit, bool &aceFail, bool &isAce){
    CardPoker highCard = hand.getCardAt(0);
    for (int i = 1; i < 5; i++){
        if (hand.getCardAt(i).getSuit() != highCard.getSuit()){
            isOneSuit = false;
        }
        if (hand.getCardAt(i).getRank().getNum() != highCard.getRank().getNum() - i){
            isSequential = false;
            if (i != hand.getSize() - 1){
                aceFail = true;
            }
            if (i == hand.getSize() - 1){
                if (hand.getCardAt(i).getRank().getNum() == 1 && !aceFail && hand.getCardAt(0).getRank().getNum() == 13){
                    isAce = true;
                }
            }
        }
    }
}

void CardHandScorer::addAdditional(PokerScore &pokerScore) {
    switch (pokerScore[0]){
        case FOUR_OF_A_KIND:
        case FULL_HOUSE:
            pokerScore += THREE_OK_A_KIND;
            pokerScore += TWO_PAIR;
            pokerScore += ONE_PAIR;
            pokerScore += ONE_PAIR;
            break;
        case THREE_OK_A_KIND:
            pokerScore += ONE_PAIR;
            break;
        case TWO_PAIR:
            pokerScore += ONE_PAIR;
            pokerScore += ONE_PAIR;
            break;
        default:
            break;
    }
    if (!(pokerScore == HIGH_CARD)){
        pokerScore += HIGH_CARD;
    }
}


