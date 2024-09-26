//
// Created by super on 3/18/2023.
//

#include "Tests.h"

void deckTest(){
    Deck deck;
    std::cout << "Un-Shuffled Deck\n" << deck << std::endl;
    deck.shuffle();
    std::cout << "Shuffled Deck\n" << deck << std::endl;
}

void cardHandTest(){
    CardHand hand1;
    std::cout << "Hand1\n" << hand1 << std::endl;

    CardHand hand2({CardPoker(1, 10), CardPoker(2, 11), CardPoker(3, 12), CardPoker(0, 13)});
    std::cout << "Hand2\n" << hand2 << std::endl;

    Deck deck;
    CardHand hand3;
    for (int i = 0; i < 3; i++) {
        hand3.addCard(deck.dealCard());
    }
    std::cout << "Hand3\n" << hand3 << std::endl;

    CardHand hand4;
    for (int i = 0; i < 3; i++) {
        hand4.addCard(deck.dealCard());
    }
    std::cout << "Hand4\n" << hand4 << std::endl;

    Deck deck2;
    deck2.shuffle();
    std::cout << "Deck2\n" << deck2 << std::endl;
    CardHand hand5;
    for (int i = 0; i < 3; i++) {
        hand5.addCard(deck2.dealCard());
    }
    std::cout << "Hand5\n" << hand5 << std::endl;

    /*CardHandScorer hand5Scorer;
    hand5Scorer.sort(hand5);
    std::cout << "sort Hand5\n" << hand5 << std::endl;*/
}

void sortTest(){
    CardHand hand1({CardPoker(1, 7), CardPoker(1, 2), CardPoker(1, 5), CardPoker(1, 3)});
    std::cout << "Hand 1 Unsorted:\n" << hand1 << std::endl;
    CardHandScorer handSorter1;
    handSorter1.sort(hand1);
    std::cout << "Hand 1 Sorted:\n" << hand1 << std::endl;


    CardHand hand2({CardPoker(3, 7), CardPoker(0, 7), CardPoker(1, 1), CardPoker(2, 10), CardPoker(2, 7)});
    std::cout << "Hand 2 Unsorted:\n" << hand2 << std::endl;
    CardHandScorer handSorter2;
    handSorter2.sort(hand2);
    std::cout << "Hand 2 Sorted:\n" << hand2 << std::endl;

    std::cout << CardHandScorer::scorePokerHand(hand2) << std::endl;

    CardHand hand3({CardPoker(0, 13), CardPoker(0, 12), CardPoker(0, 11), CardPoker(0, 10), CardPoker(0, 9)});
    std::cout << hand3 << std::endl;
    std::cout << CardHandScorer::scorePokerHand(hand3);


}


void testGraphics() {
    sf::RenderWindow window;
    std::vector<Component1*> components;

    CardPoker card(1, 1);
    card.initializeGraphics();
    //components.push_back(&card);

    CardHand hand;
    hand.addCard({0, 1});
    hand.addCard({1, 2});
    hand.addCard({2, 3});

    RowOfCardsPoker row;
    sf::Font font;
    font.loadFromFile("tahoma.ttf");
    row = hand;
    row.initializeGraphics();
    row.initializeText(font, 1, 4, 50);

    row.setHeight((392/4 + 5) * 2);
    components.push_back(&row);

    window.create({1024, 720, 32}, "Poker Analysis");
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            for(Component1* c : components){
                c->eventHandler(window, event);
            }
        }
        window.clear();
        for(Component1* c : components){
            window.draw(*c);
        }
        window.display();
    }
}
