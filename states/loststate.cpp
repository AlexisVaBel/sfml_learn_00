#include "loststate.h"
#include "game.h"

LostState::LostState(Game *game):GameState(game)
{
    m_text.setFont(getGame()->getFont());
    m_text.setString("You lost ...");
    m_text.setCharacterSize(24);
    centerOrigin(m_text);
    m_text.setPosition(240, 120);

    m_countDownText.setFont(getGame()->getFont());
    m_countDownText.setCharacterSize(12);
    centerOrigin(m_countDownText);
    m_countDownText.setPosition(240, 240);

}

void LostState::insertCoin()
{
    getGame()->changeGameState(GameState::GetReady);
}

void LostState::pressButton()
{

}

void LostState::moveStick(sf::Vector2i direction)
{

}

void LostState::update(sf::Time delta)
{
    m_countDown += delta;
    if(m_countDown.asSeconds() >= 10){
        getGame()->changeGameState(GameState::NoCoin);
    }
    m_countDownText.setString("Insert coin to continue ... "+std::to_string(10 - static_cast<int>(m_countDown.asSeconds())));
}

void LostState::draw(sf::RenderWindow &window)
{
    window.draw(m_text);
    window.draw(m_countDownText);
}
