//
// Created by super on 3/30/2023.
//

#include "RowOfCardsPoker.h"

RowOfCardsPoker::RowOfCardsPoker() {}

void RowOfCardsPoker::addCard(CardPoker card) {
    card.setPosition({static_cast<float>(910.0 / 13 * cards.size()), static_cast<float>(height)});
    cards.push_back(card);
}

void RowOfCardsPoker::setHeight(int num) {
    height = num;
    for (int i = 0; i < cards.size(); i++){
        cards.at(i).setPosition({static_cast<float>(910.0 / 13 * i), static_cast<float>(height)});
    }
}

bool RowOfCardsPoker::isEmpty() {
    return cards.empty();
}

void RowOfCardsPoker::eventHandler(sf::RenderWindow &window, sf::Event event) {
    for (int i = 0; i < cards.size(); i++){
        cards[i].eventHandler(window, event);
    }

}

void RowOfCardsPoker::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < cards.size(); i++){
        target.draw(cards.at(i));
    }
    target.draw(handText);
}

void RowOfCardsPoker::operator =(CardHand hand){
    for (int i = 0; i < hand.getSize(); i++){
        addCard(hand.getCardAt(i));
    }
}

void RowOfCardsPoker::initializeText(const sf::Font& font, int score, int scoreAmt, int runs) {
    int gcd = findGCD(scoreAmt, runs);
    handText.setFont(font);
    handText.setString(numToString(score) + " - Odds: " + std::to_string(runs/gcd) + " : " + std::to_string(scoreAmt/gcd));
    handText.setPosition(910/4 + 150, 392/8 - handText.getCharacterSize()/2 + ((392.0)/4 + 4) * score);
}

int RowOfCardsPoker::findGCD(int num, int denom){
    while(num % denom != 0){
        if (num % denom == 0){
            return denom;
        }
        int temp = num;
        num = denom;
        denom = temp % denom;
    }
    return denom;
}

std::string RowOfCardsPoker::numToString(int num) {
    switch(num){
        case 0:
            return "Royal Flush";
        case 1:
            return "Straight Flush";
        case 2:
            return "Four of a Kind";
        case 3:
            return "Full House";
        case 4:
            return "Flush";
        case 5:
            return "Straight";
        case 6:
            return "Three of a Kind";
        case 7:
            return "Two Pair";
        case 8:
            return "One Pair";
        case 9:
            return "High CardPoker";
        default:
            return "Error";

    }
}

void RowOfCardsPoker::initializeGraphics() {
    for(int i = 0; i < cards.size(); i++){
        cards.at(i).initializeGraphics();
    }
}
