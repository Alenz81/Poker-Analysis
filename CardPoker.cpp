//
// Created by super on 3/18/2023.
//

#include "CardPoker.h"

sf::Texture CardPoker::texture;

CardPoker::CardPoker() : suit("N/A"), rank("N/A"){}

CardPoker::CardPoker(const std::string& suit, const std::string& rank) : suit(suit), rank(rank){}

CardPoker::CardPoker(int suit, int rank) : suit(suit), rank(rank){}

Suits CardPoker::getSuit() {
    return suit;
}

Ranks CardPoker::getRank() {
    return rank;
}

std::ostream& operator<<(std::ostream& out, const CardPoker& card){
    std::cout << card.rank.getString() << " of " << card.suit.getString();
    return out;
}

void CardPoker::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background);
}

void CardPoker::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents::isClicked(background.getGlobalBounds(), window)){
        int r = (intRect.left/intRect.width) + 1;
        int s = (intRect.top/intRect.height) + 1;
        Ranks rank = static_cast<Ranks>(r % (13));
        Suits suit = static_cast<Suits>(s % (3));
        updateCard(rank, suit);
    }

}

void CardPoker::updateCard(Ranks rank, Suits suit) {
    intRect.left = rank.getNum() * intRect.width;
    intRect.top = suit.getNum() * intRect.height;
    background.setTextureRect(intRect);
}

void CardPoker::setPosition(sf::Vector2f position) {
    background.setPosition(position);
}

void CardPoker::initializeGraphics() {
    intRect.width = 910.0/13;
    intRect.height = 392.0/4;
    intRect.left = (rank.getNum() - 1) * intRect.width;
    intRect.top = suit.getNum() * intRect.height;
    texture.loadFromFile("LittleCardSprites.png");
    background.setTexture(texture);
    background.setTextureRect(intRect);
}



