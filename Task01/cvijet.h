#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
    sf::RenderWindow& window;
    sf::CircleShape sunce;
    sf::Clock clock;
    bool smanjuje;

public:
    Cvijet(sf::RenderWindow& window); // referenca, ne pointer
    void draw();
};
