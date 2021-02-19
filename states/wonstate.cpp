#include "wonstate.h"
#include "game.h"

WonState::WonState(Game *game):GameState(game)
{
    m_text.setFont(getGame()->getFont());
    m_text.setString("You Won ...");
    m_text.setCharacterSize(42);
    centerOrigin(m_text);
    m_text.setPosition(240, 120);

}

void WonState::insertCoin()
{

}

void WonState::pressButton()
{

}

void WonState::moveStick(sf::Vector2i direction)
{

}

void WonState::update(sf::Time delta)
{
    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer +=delta;
    if (timeBuffer >= sf::seconds(5)) {
        getGame()->changeGameState(GameState::GetReady);
    }
}

void WonState::draw(sf::RenderWindow &window)
{
    window.draw(m_text);
}
