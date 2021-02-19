#include "gamestate.h"
#include <iostream>


GameState::GameState(Game *game):m_game(game){
}

Game *GameState::getGame() const
{
    return m_game;
}


