//
// Created by super on 3/18/2023.
//

#include "Deck.h"

Deck::Deck() : cardIndex(0){
    for (int i = 0; i < 4; i++){
        for (int j = 1; j <= 13; j++){
            deck[i * 13 + j - 1] = CardPoker(i, j);
        }
    }
}

bool Deck::empty() {
    for (int i = 0; i < DECK_SIZE; i++){
        if(deck[i].getRank().getNum() != -1 && deck[i].getSuit().getNum() == -1){
            return false;
        }
    }
    return true;
}

void Deck::shuffle() {
    for (int i = 0; i < 52; i++){
        int tempInt = rand() % 52;
        CardPoker tempCard = deck[tempInt];
        deck[tempInt] = deck[i];
        deck[i] = tempCard;
    }
}

CardPoker Deck::dealCard() {
    CardPoker temp = deck[cardIndex];
    deck[cardIndex] = CardPoker();
    cardIndex++;
    if (cardIndex >= 52){
        cardIndex = 0;
    }
    return temp;
}

CardPoker& Deck::getCardAt(int index) {
    return deck[index];
}

std::ostream& operator<<(std::ostream& out, const Deck& deck){
    for (int i = 0; i < 52; i++){
        std::cout << i + 1 << ": " << deck.deck[i] << std::endl;
    }
    return out;
}
