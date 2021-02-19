#ifndef LOSTSTATE_H
#define LOSTSTATE_H

#include "gamestate.h"

#include <SFML/Graphics/Text.hpp>



class LostState: public GameState{
public:
    LostState (Game *game);
    void insertCoin();
    void pressButton();
    void moveStick(sf::Vector2i direction);
    void update(sf::Time delta);
    void draw(sf::RenderWindow &window);
private:
    sf::Text m_text;
    sf::Text m_countDownText;
    sf::Time m_countDown;

};

#endif // LOSTSTATE_H
