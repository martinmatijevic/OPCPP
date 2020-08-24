#include "game.h"
#include <stdexcept>
#include <iostream>

Game::Game() : mWindow(sf::VideoMode(400, 400), "SFML window") {
    if (!mTexture.loadFromFile("cb.bmp"))
        throw std::runtime_error("Cannot open file cb.bmp!");
    mSprite.setTexture(mTexture);
    mDtFixed = sf::seconds(1.0f/60.0f);
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate >= mDtFixed)
        {
            timeSinceLastUpdate -= mDtFixed;
            processEvents();
            update(mDtFixed);
        }
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type){
            case sf::Event::Closed:
                mWindow.close();
                break;
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::MouseButtonPressed:
                if (mSprite.getGlobalBounds().contains(sf::Mouse::getPosition(mWindow).x,sf::Mouse::getPosition(mWindow).y))
                    if (event.key.code == sf::Mouse::Right || event.key.code == sf::Mouse::Left){
                        Hover = true;
                        Movable = true;
                    }
                break;
            case sf::Event::MouseMoved:
                if (Hover && Movable) mSprite.setPosition(event.mouseMove.x-75,event.mouseMove.y-60);
                break;
            case sf::Event::MouseButtonReleased:
                Movable = false;
                Hover = false;
                break;
        }
    }
}

void Game::update(sf::Time dt) {
    sf::Vector2f velocity(0.f,0.f);
    if (mIsMovingUp) velocity.y -= mVelocity;
    if (mIsMovingDown) velocity.y += mVelocity;
    if (mIsMovingLeft) velocity.x -= mVelocity;
    if (mIsMovingRight) velocity.x += mVelocity;
    mSprite.move(velocity*dt.asSeconds());
}

void Game::render() {
    // Clear screen
    mWindow.clear();
    // Draw the sprite
    mWindow.draw(mSprite);
    // Update the window
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key code, bool isPressed){
    if (code == sf::Keyboard::Key::Up)
        mIsMovingUp = isPressed;
    if (code == sf::Keyboard::Key::Down)
        mIsMovingDown = isPressed;
    if (code == sf::Keyboard::Key::Left)
        mIsMovingLeft = isPressed;
    if (code == sf::Keyboard::Key::Right)
        mIsMovingRight = isPressed;
}
