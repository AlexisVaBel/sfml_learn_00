#include "bonus.h"

Bonus::Bonus(sf::Texture &texture):m_visual(texture)
{
    m_visual.setOrigin(15,15);
    setFruit(Banana);
}

void Bonus::setFruit(Bonus::Fruit fr)
{
    switch (fr) {
    case Banana: m_visual.setTextureRect(sf::IntRect(32,0,30,30));
        break;
    case Apple: m_visual.setTextureRect(sf::IntRect(32+30,0,30,30));
        break;
    case Cherry: m_visual.setTextureRect(sf::IntRect(32+60,0,30,30));
        break;
    default: m_visual.setTextureRect(sf::IntRect(32,0,30,30));
    }
}

void Bonus::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_visual, states);
}
