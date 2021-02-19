#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>




class Character: public sf::Drawable, public sf::Transformable
{
public:
    Character();

    float getSpeed() const;
    void  setSpeed(float speed);

private:
    float m_speed;
};

#endif // CHARACTER_H
