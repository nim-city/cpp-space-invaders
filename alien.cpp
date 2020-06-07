#include "alien.h"
#include <iostream>

Alien::Alien(float x, float y, float w, float h, float m) {
    xPos = x;
    yPos = y;
    width = w;
    height = h;
    currentMovement = m / 2;
    maxMovement = m;
    direction = -1;
    shouldChangeDirection = false;

    sprite.setSize(sf::Vector2f(w,w));
    sprite.setFillColor(sf::Color::Red);
    sprite.setPosition(sf::Vector2f(xPos,yPos));
    
}

// 1 move left
// 2 continue and decrease current movement amount
// 3 when current movement <= 0 or current movement >= max movement, change movement variable to negative

void Alien::updatePosition(float byX) {
    if (shouldChangeDirection) {
        yPos += height;
        sprite.setPosition(sf::Vector2f(xPos, yPos));
        shouldChangeDirection = false;
        return;
    }

    xPos += (byX * direction);
    currentMovement += (byX * direction);

    if (currentMovement <= 0) {
        direction = 1;
        shouldChangeDirection = true;
    } else if (currentMovement >= maxMovement) {
        direction = -1;
        shouldChangeDirection = true;
    }
    
    sprite.setPosition(sf::Vector2f(xPos, yPos));
}



