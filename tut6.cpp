#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(600,600),"Mouse And KeyBoard Demo");
    float size = 40.f;
    sf::CircleShape circle(size);
    sf::Color color = sf::Color::Yellow;
    bool prevLeft = false;
    bool prevRight = false;
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
            {
                window.close();
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        {
            color = sf::Color::Blue;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        {
            color = sf::Color::Green;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            color = sf::Color::Red;
            prevLeft = false;
            prevRight = false;
        }
        else if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if(!prevLeft)
            {
                size += 10;
                circle.setRadius(size);
                prevLeft = true;
            }
        }
        else if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            if(!prevRight)
            {
                size -= 10;
                circle.setRadius(size);
                prevRight = true;
            }
        }
        //global one relative to desktop
        sf::Vector2i globalPosition = sf::Mouse::getPosition();
        //local one relative to window
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        window.clear();
        circle.setFillColor(color);
        circle.setPosition(localPosition.x-size,localPosition.y-size);
        //circle.setPosition(globalPosition.x-size,globalPosition.y-size);
        window.draw(circle);
        window.display();
    }
    return 0;
}