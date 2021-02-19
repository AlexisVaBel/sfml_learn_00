#include "nocoinstate.h"
#include <iostream>
#include "game.h"

NoCoinState::NoCoinState(Game *game):GameState(game)
{
    m_sprite.setTexture(getGame()->getLogo());
    m_sprite.setPosition(20,50);

    m_text.setFont(getGame()->getFont());
    m_text.setString("Insert Coin");
    centerOrigin(m_text);
    m_text.setPosition(240, 150);

    m_displayText = true;
}

void NoCoinState::insertCoin()
{
    getGame()->changeGameState(GameState::GetReady);
    std::cout << __PRETTY_FUNCTION__ << std::endl;

}

void NoCoinState::pressButton()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void NoCoinState::moveStick(sf::Vector2i direction)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void NoCoinState::update(sf::Time delta)
{
    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer +=delta;
    while (timeBuffer >= sf::seconds(0.5)) {
        m_displayText = !m_displayText;
        timeBuffer -= sf::seconds(1);
    }

}

void NoCoinState::draw(sf::RenderWindow &window)
{    
    window.draw(m_sprite);
    if(m_displayText)
        window.draw(m_text);

}

