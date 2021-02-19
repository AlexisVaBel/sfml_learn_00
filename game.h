#ifndef GAME_H
#define GAME_H

#include "gamestate.h"
#include <array>


#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>



class Game
{
public:
    Game();
    ~Game();

    void changeGameState(GameState::GStates state);
    sf::Font&    getFont();
    sf::Texture& getLogo();
    sf::Texture& getTexture();


    void run();


private:
    sf::RenderWindow m_window;
    GameState *m_currentState;
    std::array <GameState *, GameState::Count> m_gameStates;

    sf::Font    m_font;
    sf::Texture m_logo;
    sf::Texture m_texture;
};

#endif // GAME_H
