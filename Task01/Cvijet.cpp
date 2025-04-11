#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow& window) : window(window)
{
    sunce.setRadius(20.f);
    sunce.setFillColor(sf::Color::Yellow);
    sunce.setPosition({ 190.f, 100.f }); // novi stil inicijalizacije

    smanjuje = true;
}

void Cvijet::draw()
{
    if (clock.getElapsedTime().asMilliseconds() > 100)
    {
        if (smanjuje)
            sunce.setRadius(sunce.getRadius() - 0.5f);
        else
            sunce.setRadius(sunce.getRadius() + 0.5f);

        if (sunce.getRadius() <= 15.f)
            smanjuje = false;
        if (sunce.getRadius() >= 20.f)
            smanjuje = true;

        clock.restart();
    }

    window.draw(sunce);
}
