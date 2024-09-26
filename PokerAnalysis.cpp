//
// Created by super on 3/28/2023.
//

#include "PokerAnalysis.h"

PokerAnalysis::PokerAnalysis() : runs(0) {}

bool PokerAnalysis::isNotFull() {
    for (int i = 0; i < 10; i++){
        if (listOfScores[i] == 0){
            return true;
        }
    }
    return false;
}

CardHand PokerAnalysis::deckAndHand() {
    Deck deck;
    deck.shuffle();
    CardHand hand;
    for (int i = 0; i < 5; i++){
        hand.addCard(deck.dealCard());
    }
    CardHandScorer::sort(hand);
    return hand;
}

void PokerAnalysis::runAnalysis() {
    PokerScore pokerScore;
    CardHand hand;
    runs = 0;
    do {
        hand = deckAndHand();
        pokerScore = CardHandScorer::scorePokerHand(hand);
        for (int i = 0; i < pokerScore.size(); i++){
            listOfScores[pokerScore[i]]++;
        }
        if (uniqueHands[pokerScore[0]].isEmpty()){
            uniqueHands[pokerScore[0]] = hand;
        }
        runs++;
    } while(isNotFull());
}

void PokerAnalysis::drawAnalysis() {
    sf::RenderWindow window;
    std::vector<Component1*> components;

    sf::Font font;
    if (!font.loadFromFile("tahoma.ttf")){
        exit(11);
    }

    sf::Text runsText;
    runsText.setFont(font);
    runsText.setString("Runs: " + std::to_string(runs));
    runsText.setPosition(1000 - runsText.getLocalBounds().width - 10, 0);

    for (int i = 0; i < 10; i++){
        uniqueHands[i].initializeGraphics();
        uniqueHands[i].setHeight( (392/4 + 5) * i);
        uniqueHands[i].initializeText(font, i, listOfScores[i], runs);
        components.push_back(&uniqueHands[i]);
    }


    window.create({1000, (392/4 + 5) * 10 - 5, 32}, "Poker Analysis");
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            for(Component1* c : components){
                //c->eventHandler(window, event);
            }
        }
        window.clear();
        for(Component1* c : components){
            window.draw(*c);
        }
        window.draw(runsText);
        window.display();
    }
}

std::ostream& operator<<(std::ostream& out, PokerAnalysis pokerAnalysis){
    for (int i = 0; i <= 9; i++){
        switch(i){
            case 0:
                std::cout << "ROYAL_FLUSH";
                break;
            case 1:
                std::cout << "STRAIGHT_FLUSH";
                break;
            case 2:
                std::cout << "FOUR_OF_A_KIND";
                break;
            case 3:
                std::cout << "FULL_HOUSE";
                break;
            case 4:
                std::cout << "FLUSH";
                break;
            case 5:
                std::cout << "STRAIGHT";
                break;
            case 6:
                std::cout << "THREE_OK_A_KIND";
                break;
            case 7:
                std::cout << "TWO_PAIR";
                break;
            case 8:
                std::cout << "ONE_PAIR";
                break;
            case 9:
                std::cout << "HIGH_CARD";
                break;
            default:
                break;
        }
        std::cout << ": " << pokerAnalysis.listOfScores[i] << " Probability: " << 100.0 * pokerAnalysis.listOfScores[i]/pokerAnalysis.runs << "%\n";
    }
    return out;
}

