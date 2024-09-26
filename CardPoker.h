//
// Created by super on 3/18/2023.
//

#ifndef POKER_ANALYSIS_CARDPOKER_H
#define POKER_ANALYSIS_CARDPOKER_H
#include <iostream>
#include "Suits.h"
#include "Ranks.h"
#include <SFML/Graphics.hpp>
#include "Component1.h"


class CardPoker : public Component1{
private:
    Suits suit;
    Ranks rank;
    sf::Sprite background;
    sf::IntRect intRect;
    static sf::Texture texture;
public:
    CardPoker();
    CardPoker(const std::string& suit, const std::string& rank);
    CardPoker(int suit, int rank);

    Suits getSuit();
    Ranks getRank();

    void initializeGraphics();

    friend std::ostream& operator<<(std::ostream& out, const CardPoker& card);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void updateCard(Ranks rank, Suits suit);
    void setPosition(sf::Vector2f position);

};


#endif //POKER_ANALYSIS_CARDPOKER_H
