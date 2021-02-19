#ifndef BONUS_H
#define BONUS_H

#include <SFML/Graphics.hpp>


class Bonus: public sf::Drawable, public sf::Transformable
{
public:
    enum Fruit{
        Banana,
        Apple,
        Cherry

    };

    Bonus(sf::Texture &texture);

    void setFruit(Fruit fr);
private:
    sf::Sprite m_visual;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif // BONUS_H
