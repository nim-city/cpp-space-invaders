#include <SFML/Graphics.hpp>
#include <vector>
#include "alien.cpp"

int main()
{
    std::string title = "Space Invaders";
    float windowWidth = 500;
    float windowHeight = 500;

    sf::RenderWindow window(sf::VideoMode(windowWidth,windowHeight), title);

    // Ship
    float shipLength = 50;
    sf::RectangleShape playerShip(sf::Vector2f(shipLength,shipLength));
    playerShip.setFillColor(sf::Color::Green);
    float playerX = (windowWidth / 2) - (shipLength / 2);
    float playerY = windowHeight - shipLength;
    playerShip.setPosition(sf::Vector2f(playerX,playerY));

    // Alien ships
    float alienShipLength = shipLength;
    std::vector<Alien> aliens;
    float alienVelocity = 25;
    float maxAlienMovement = 200;
    aliens.push_back(Alien((windowWidth / 4), alienShipLength, alienShipLength, alienShipLength, maxAlienMovement));
    aliens.push_back(Alien((windowWidth / 2) - (alienShipLength / 2), alienShipLength, alienShipLength, alienShipLength, maxAlienMovement));
    aliens.push_back(Alien((windowWidth * 3 / 4) - alienShipLength, alienShipLength, alienShipLength, alienShipLength, maxAlienMovement));
    // sf::RectangleShape alienShip(sf::Vector2f(alienShipLength,alienShipLength));
    // alienShip.setFillColor(sf::Color::Red);
    // float alienX = (windowWidth / 2) - (alienShipLength / 2);
    // float alienY = alienShipLength;
    // alienShip.setPosition(sf::Vector2f(alienX,alienY));
    

    // Alien ships

    // Bullets


    float gameSpeed = 800;

    int i = 0;
    while (window.isOpen())
    {
        i += 1;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    if (playerX > 0) {
                        playerX -= shipLength / 2;
                    }
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    if (playerX < (windowWidth - shipLength)) {
                        playerX += shipLength / 2;
                    }
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    // Fire missile
                }
            }
        }
        
        

        if (i == gameSpeed) {
            for (int j = 0; j < aliens.size(); j++) {
                aliens[j].updatePosition(alienVelocity);
            }
            i = 0;
        }

        window.clear();

        playerShip.setPosition(sf::Vector2f(playerX,playerY));
        window.draw(playerShip);

        for (int j = 0; j < aliens.size(); j++) {
            window.draw(aliens[j].sprite);
        }

        window.display();
    }

    return 0;
}