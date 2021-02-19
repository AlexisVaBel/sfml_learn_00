#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "pacwoman.h"
#include "ghost.h"

template <class T>
void centerOrigin(T& drawable){
    sf::FloatRect rect = drawable.getLocalBounds();
    drawable.setOrigin(rect.width/2, rect.height/2);
}

class Game;

class GameState
{
    public:
    enum GStates{
        NoCoin,
        GetReady,
        Playing,
        Won,
        Lost,
        Count
    };

    GameState(Game *game);
    virtual void insertCoin() = 0;
    //
    virtual void pressButton() = 0;
    //
    virtual void moveStick(sf::Vector2i direction) = 0;
    //
    virtual void update(sf::Time delta) = 0;
    //
    virtual void draw(sf::RenderWindow &window) = 0;

    Game *getGame() const;

private:
    Game *m_game;
};








#endif // GAMESTATE_H
