#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800,800), "Loading", sf::Style::Default, settings);
    CircleShape loading;
    RectangleShape load(Vector2f(120,40));
    RectangleShape fill(Vector2f(120,40));
    fill.setFillColor(Color::Cyan);
    load.setPosition(300,300);
    fill.setPosition(300,300);
    //loading.setFillColor(Color::Cyan);
    //loading.setOutlineColor(Color::White);
    //triangle.setOutlineThickness(1);
    while(window.isOpen())
    {
        sf::Event event;
        window.clear();
        for(int i=0;i<1200;i++)
        {
            //window.clear(Color::Blue);
            //loading.setRotation(i); //minus means oppo rotation
            //loading.setRadius(i/20);
            //loading.setPosition(800,500);
            //loading.setPosition(240+25*i,300);
            //window.draw(loading);
            window.draw(load);
            fill.setSize(Vector2f(i/10,40));
            window.draw(fill);
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