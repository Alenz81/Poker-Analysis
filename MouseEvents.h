//
// Created by super on 3/30/2023.
//

#ifndef NEW_SFML_TUTORIAL_MOUSEEVENTS_H
#define NEW_SFML_TUTORIAL_MOUSEEVENTS_H
#include <SFML/Graphics.hpp>

class MouseEvents {
public:
    MouseEvents();
    static bool isHovered(const sf::FloatRect& bounds, const sf::RenderWindow& window);
    static bool isClicked(const sf::FloatRect& bounds, const sf::RenderWindow& window);
};


#endif //NEW_SFML_TUTORIAL_MOUSEEVENTS_H
