#include "getreadystate.h"
#include "game.h"

GetReadyState::GetReadyState(Game *game):GameState(game)
{
    m_text.setFont(getGame()->getFont());
    m_text.setString("Press start button");
    m_text.setCharacterSize(14);
    centerOrigin(m_text);
    m_text.setPosition(240, 240);

}

void GetReadyState::insertCoin()
{

}

void GetReadyState::pressButton()
{
    getGame()->changeGameState(GameState::Playing);
}

void GetReadyState::moveStick(sf::Vector2i direction)
{

}

void GetReadyState::update(sf::Time delta)
{

}

void GetReadyState::draw(sf::RenderWindow &window)
{
    window.draw(m_text);
}
