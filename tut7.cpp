#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(600,600),"WASD");
    sf::CircleShape circle(10.f);
    sf::CircleShape tail(10.f);
    tail.setFillColor(sf::Color::Red);
    int x = 1;
    int y = 1;
    circle.setPosition(x,y);
    tail.setPosition(x,y);
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
            {
                window.close();
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            y++;
            tail.setPosition(x+10,y+10);
            circle.setPosition(x,y);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            y--;
            circle.setPosition(x,y);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            x++;
            circle.setPosition(x,y);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            x--;
            circle.setPosition(x,y);
        }
        window.draw(tail);
        window.clear();
        window.draw(circle);
        window.display();
    }
    return 0;
}