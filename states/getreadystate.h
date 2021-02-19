#ifndef GETREADYSTATE_H
#define GETREADYSTATE_H

#include "gamestate.h"

#include <SFML/Graphics/Text.hpp>

class GetReadyState: public GameState{
public:
    GetReadyState (Game *game);
    void insertCoin();
    void pressButton();
    void moveStick(sf::Vector2i direction);
    void update(sf::Time delta);
    void draw(sf::RenderWindow &window);
private:
    sf::Text m_text;
};


#endif // GETREADYSTATE_H
