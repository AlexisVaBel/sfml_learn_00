#ifndef WONSTATE_H
#define WONSTATE_H

#include "gamestate.h"

#include <SFML/Graphics/Text.hpp>



class WonState: public GameState{
public:
    WonState (Game *game);
    void insertCoin();
    void pressButton();
    void moveStick(sf::Vector2i direction);
    void update(sf::Time delta);
    void draw(sf::RenderWindow &window);
private:
    sf::Text m_text;
};



#endif // WONSTATE_H
