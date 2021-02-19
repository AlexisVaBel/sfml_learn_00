#ifndef PACWOMAN_H
#define PACWOMAN_H

#include "character.h"
#include "animation/animator.h"


class Pacwoman: public Character
{
public:
    Pacwoman(sf::Texture &texture);

    void die();
    bool isDead() const;
    bool isDying() const;
    void update(sf::Time delta);

    // Drawable interface
protected:
    bool m_isDying;
    bool m_isDead;

    sf::Sprite m_visual;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    Animator    m_runAnimator;
    Animator    m_dieAnimator;

    void prepare_animators();
};

#endif // PACWOMAN_H
