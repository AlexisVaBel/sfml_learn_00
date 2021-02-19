#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include "gamestate.h"

class PlayingState: public GameState{
public:
    PlayingState (Game *game);
    void insertCoin();
    void pressButton();
    void moveStick(sf::Vector2i direction);
    void update(sf::Time delta);
    void draw(sf::RenderWindow &window);
private:

    Pacwoman m_packWoman;
    Ghost    m_ghost;
};


#endif // PLAYINGSTATE_H
