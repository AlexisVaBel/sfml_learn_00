#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <vector>
#include <SFML/Graphics.hpp>

class Animator
{
public:
    Animator();

    void addFrame(sf::IntRect frame);
    void play(sf::Time duration, bool loop);
    bool isPlaying() const;

    void update(sf::Time delta);
    void animate(sf::Sprite &sprite);

private:
    std::vector<sf::IntRect> m_frames;


    sf::Time m_duration;
    bool     m_loop;
    bool     m_isPlaying;

    unsigned int m_currentFrame;
};

#endif // ANIMATOR_H
