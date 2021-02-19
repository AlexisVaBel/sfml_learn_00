#include "game.h"
#include "getreadystate.h"
#include "loststate.h"
#include "nocoinstate.h"
#include "playingstate.h"
#include "wonstate.h"
#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>




//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 24;

//The frame rate
const int FRAMES_PER_SECOND = 20;


Game::Game():m_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pac woman"){
    if(!m_font.loadFromFile("assets/font.ttf"))
        throw std::runtime_error("unable to load fonts");
    if(!m_logo.loadFromFile("assets/logo.png"))
        throw std::runtime_error("unable to load logo");
    if(!m_texture.loadFromFile("assets/texture.png"))
        throw std::runtime_error("unable to load texture");


    m_gameStates[GameState::NoCoin]     = new NoCoinState(this);
    m_gameStates[GameState::GetReady]   = new GetReadyState(this);
    m_gameStates[GameState::Playing]    = new PlayingState(this);
    m_gameStates[GameState::Lost]       = new LostState(this);
    m_gameStates[GameState::Won]        = new WonState(this);

    changeGameState(GameState::NoCoin);
}

Game::~Game()
{    
    for(GameState *st: m_gameStates){
        delete  st;
    }
}

void Game::changeGameState(GameState::GStates state)
{
    m_currentState = m_gameStates[state];    
}

sf::Font &Game::getFont()
{
    return m_font;
}

sf::Texture &Game::getLogo()
{
    return m_logo;
}

sf::Texture &Game::getTexture()
{
    return m_texture;
}

void Game::run()
{
    sf::Clock frameClock;
    while(m_window.isOpen()){
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                m_window.close();
            }
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::I) m_currentState->insertCoin();
                if(event.key.code == sf::Keyboard::S) m_currentState->pressButton();
                if(event.key.code == sf::Keyboard::Up)    m_currentState->moveStick(sf::Vector2i(0,-1));
                if(event.key.code == sf::Keyboard::Down)  m_currentState->moveStick(sf::Vector2i(0, 1));
                if(event.key.code == sf::Keyboard::Left)  m_currentState->moveStick(sf::Vector2i(-1, 0));
                if(event.key.code == sf::Keyboard::Right) m_currentState->moveStick(sf::Vector2i(1, 0));
            }

        }
        m_currentState->update(frameClock.restart());
        m_window.clear();     
        m_currentState->draw(m_window);
        m_window.display();
    }
}

