#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow& window) : window(window)
{
    // Malo sunce u kutu
    sunce.setRadius(10.f);
    sunce.setFillColor(sf::Color::Yellow);
    sunce.setPosition({ 10.f, 10.f });

    // Žuta sredina cvijeta
    sredinaCvijeta.setRadius(50.f);
    sredinaCvijeta.setFillColor(sf::Color::Yellow);
    sredinaCvijeta.setPosition({ 150.f, 100.f }); // centrirano u prozoru

    // Crvene latice (prsten oko žute sredine)
    latice.setRadius(70.f);
    latice.setFillColor(sf::Color::Red);
    latice.setPosition({ 130.f, 80.f }); // oko sredine
    latice.setPointCount(100); // da krug bude lijepo gladak

    // Stabljika
    stabljika.setSize({ 10.f, 100.f });
    stabljika.setFillColor(sf::Color::Green);
    stabljika.setPosition({ 185.f, 200.f });

    // List (koso)
    list.setPointCount(4);
    list.setPoint(0, { 0.f, 0.f });
    list.setPoint(1, { 50.f, -20.f });
    list.setPoint(2, { 80.f, 0.f });
    list.setPoint(3, { 50.f, 20.f });
    list.setFillColor(sf::Color::Green);
    list.setPosition({ 190.f, 250.f });

    smanjuje = true;
}

void Cvijet::draw()
{
    if (clock.getElapsedTime().asMilliseconds() > 100)
    {
        if (smanjuje)
            sunce.setRadius(sunce.getRadius() - 0.2f);
        else
            sunce.setRadius(sunce.getRadius() + 0.2f);

        if (sunce.getRadius() <= 8.f)
            smanjuje = false;
        if (sunce.getRadius() >= 10.f)
            smanjuje = true;

        clock.restart();
    }

    // Prvo crtamo latice (iza)
    window.draw(latice);
    // Onda sredinu cvijeta
    window.draw(sredinaCvijeta);
    // Onda stabljiku
    window.draw(stabljika);
    // Onda list
    window.draw(list);
    // I na kraju malo sunce
    window.draw(sunce);
}
