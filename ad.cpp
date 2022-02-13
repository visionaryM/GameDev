#include <SFML/Graphics.hpp>

#include <iostream>

using namespace std;

int main()
{
    sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(600,600), "SFML works!", sf::Style::Default, settings);
    sf::CircleShape circle(5.f);
    while(window.isOpen())
    {
        sf::Event event;
        for(int i=0;i<50;i++)
        {
            window.clear();
            circle.setPosition(290+i,300);
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