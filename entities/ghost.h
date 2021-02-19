#ifndef GHOST_H
#define GHOST_H

#include "character.h"
#include "animation/animator.h"
#include "pacwoman.h"

class Ghost: public Character
{
public:

    enum State{
        Strong,
        Weak
    };

    Ghost(sf::Texture &texture);

    void setWeak(sf::Time duration);
    bool isWeak() const;
    void update(sf::Time delta);

    // Drawable interface
protected:
    bool m_isWeak;
    sf::Time m_weaknessDuration;

    sf::Sprite m_visual;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    Animator    m_strongAnimator;
    Animator    m_weakAnimator;

    void prepare_animators();
};


#endif // GHOST_H
