#include <SFML/Graphics.hpp>


int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800,800), "SFML works!", sf::Style::Default, settings);
	sf::Vertex line1[] =
	{
		sf::Vertex(sf::Vector2f(150,0)),
		sf::Vertex(sf::Vector2f(150,250))
	};
    sf::Vertex line2[] =
	{
		sf::Vertex(sf::Vector2f(50,0)),
		sf::Vertex(sf::Vector2f(50,200))
	};
	sf::CircleShape circle(100.f);
	sf::CircleShape triangle(100.f,3);
    circle.setPosition(50,100);
    triangle.setPosition(50,100);
    circle.setFillColor(sf::Color::Transparent);
    triangle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(1);
    triangle.setOutlineThickness(1);
    circle.setOutlineColor(sf::Color::White);
    triangle.setOutlineColor(sf::Color::White);
    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
            {
                window.close();
            }
        }
        window.draw(circle);
        window.draw(triangle);
        window.draw(line1, 2, sf::Lines);
        window.draw(line2, 2, sf::Lines);
        window.display();
    }
    return 0;
}