//create multiple circle
#include <SFML/Graphics.hpp>

int main()
{
    sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(600,600), "SFML works!", sf::Style::Default, settings);
	sf::CircleShape circle(10.f);
    while(window.isOpen())
    {
        sf::Event event;
        window.clear();
        for(int i=1;i<39;i++)
        {
            circle.setPosition(15*i,15*i);
            window.draw(circle);
        }
        for(int i=1;i<39;i++)
        {
            circle.setPosition(585-(15*i),15*i);
            window.draw(circle);
        }
        for(int i=1;i<28;i++)
        {
            circle.setPosition(21*i,590/2);
            window.draw(circle);
        }
        for(int i=1;i<28;i++)
        {
            circle.setPosition(590/2,21*i);
            window.draw(circle);
        }
		while(window.pollEvent(event))
		{
			if(event.type==sf::Event::Closed)
			{
				window.close();
			}
		}
        window.display();
    }
    return 0;
}