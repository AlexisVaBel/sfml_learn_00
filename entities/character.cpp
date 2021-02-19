#include "character.h"

Character::Character():m_speed(1.f)
{

}

float Character::getSpeed() const
{
    return m_speed;
}

void Character::setSpeed(float speed)
{
    m_speed = speed;
}
