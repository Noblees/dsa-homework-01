#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
    sf::RenderWindow& window;
    sf::CircleShape sunce; // malo sunce gore lijevo
    sf::CircleShape sredinaCvijeta; // žuti centar cvijeta
    sf::CircleShape latice; // crveni "prsten" oko centra
    sf::RectangleShape stabljika; // stabljika
    sf::ConvexShape list; // list
    sf::Clock clock;
    bool smanjuje;

public:
    Cvijet(sf::RenderWindow& window);
    void draw();
};
