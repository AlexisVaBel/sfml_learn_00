#include "playingstate.h"
#include "game.h"
PlayingState::PlayingState(Game *game):GameState(game),
    m_packWoman(game->getTexture()),
    m_ghost(game->getTexture())
{
    m_packWoman.move(100,100);
    m_ghost.move(50, 50);
}

void PlayingState::insertCoin()
{
    m_packWoman.die();
}

void PlayingState::pressButton()
{
    m_ghost.setWeak(sf::seconds(3));
}

void PlayingState::moveStick(sf::Vector2i direction)
{
    if(direction.x == -1){
        getGame()->changeGameState(GameState::Lost);
    }
    if(direction.x == 1){
        getGame()->changeGameState(GameState::Won);
    }
}

void PlayingState::update(sf::Time delta)
{
    m_packWoman.update(delta);
    m_ghost.update(delta);

}

void PlayingState::draw(sf::RenderWindow &window)
{
    window.draw(m_packWoman);
    window.draw(m_ghost);
}
