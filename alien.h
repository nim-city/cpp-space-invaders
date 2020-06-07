#include <SFML/Graphics.hpp>

class Alien
{
    float xPos;
    float yPos;
    float width;
    float height;
    float maxMovement;
    int direction;
    bool shouldChangeDirection;
public:
    float currentMovement;
    sf::RectangleShape sprite;
    Alien(float, float, float, float, float);
    void updatePosition(float);
};