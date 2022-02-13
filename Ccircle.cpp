#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

#include <iostream>

using namespace std;

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800,800), "Concentric Circle!", sf::Style::Default, settings);
    CircleShape circle(1.f);
    circle.setFillColor(Color::Transparent);
    circle.setOutlineThickness(1);
    circle.setOutlineColor(Color::White);
    circle.setPosition(300,300);
    circle.setOrigin(300,300);
    while(window.isOpen())
    {
        sf::Event event;
        for(int i=0;i<300;i++)
        {
            window.clear();
            circle.setRadius(i);
            window.draw(circle);
            window.display();
        }
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
            {
                window.close();
            }
        }
    }
    return 0;
}