#ifndef NOCOINSTATE_H
#define NOCOINSTATE_H

#include "gamestate.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class NoCoinState: public GameState{
public:
    NoCoinState (Game *game);
    void insertCoin();
    void pressButton();
    void moveStick(sf::Vector2i direction);
    void update(sf::Time delta);
    void draw(sf::RenderWindow &window);
private:
    sf::Text m_text;
    sf::Sprite m_sprite;
    bool m_displayText;
};



#endif // NOCOINSTATE_H
