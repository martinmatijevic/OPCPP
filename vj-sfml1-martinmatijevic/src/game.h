#pragma once
#include <SFML/Graphics.hpp>

class Game{
public:
    Game();
    void run();
private:
    void processEvents();
    void update(sf::Time dt);
    void render();
    void handlePlayerInput(sf::Keyboard::Key code, bool isPressed);

    sf::RenderWindow mWindow;
    sf::Texture mTexture;
    sf::Sprite mSprite;

    bool mIsMovingUp = false;
    bool mIsMovingDown = false;
    bool mIsMovingLeft = false;
    bool mIsMovingRight = false;
    bool mIsMovingMouse = false;

    bool Hover = false;
    bool Movable = true;
    
    float mVelocity = 120.0f;
    sf::Time mDtFixed;
};
