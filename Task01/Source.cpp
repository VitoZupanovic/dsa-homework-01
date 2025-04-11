#include <SFML/Graphics.hpp>
#include <iostream>
#include "Flower.h"

int main()
{
   
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::ContextSettings settings;
 
    sf::RenderWindow window(sf::VideoMode({ 500, 500 }), "SFML flower", sf::Style::Default, sf::State::Windowed, settings);

    Flower flower(&window);


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        flower.draw();

        window.clear();
        window.draw(shape);
        window.display();
    }
}