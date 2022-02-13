#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <assert.h>
using namespace sf;

int main()
{
    ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(800,800), "SFML works!",Style::Default, settings);
    //making wheel
    CircleShape wheel(50);
    wheel.setOutlineColor(Color::White);
    wheel.setFillColor(Color::Transparent);
    wheel.setOutlineThickness(1);
    //making road
    Vertex road[] =
    {
        Vertex(Vector2f(0,700)),
        Vertex(Vector2f(800,700))
    };
    //cloud image
    //CircleShape circle(100.f);
    Texture texture;
    Sprite sprite;
    sprite.setTexture(texture);
    assert(texture.loadFromFile("resources/image/cloud.jpeg"));
    // circle.setTextureRect(sf::IntRect(0,0,200,200));
    //making moon
    CircleShape moon(50.f);
    while(window.isOpen())
    {
        Event event;
        for(int i=0;i<800;i++)
        {
            window.clear();
            Vertex line[] =
            {
                Vertex(Vector2f(i+50,600)),
                Vertex(Vector2f(i+200,600))
            };
            Vertex line1[] =
            {
                Vertex(Vector2f(i+200,600)),
                Vertex(Vector2f(i+200-20,550))
            };
            Vertex line2[] = 
            {
                Vertex(Vector2f(i+200-20,550)),
                Vertex(Vector2f(i+200-40,550))
            };
            moon.setPosition(i/3+30,60);
            sprite.setTextureRect(IntRect(0,0,200,200));
            sprite.setScale(1,1);
            sprite.setPosition(i/2,50);
            sprite.setColor(Color::White);
            window.draw(sprite);
            window.draw(moon);
            //window.draw(moon);
		    window.draw(line, 2, Lines);
		    window.draw(line1, 2, Lines);
		    window.draw(line2, 2, Lines);
		    window.draw(road, 2, Lines);
            wheel.setPosition(i,800-200);
            window.draw(wheel);
            wheel.setPosition(i+150,800-200);
            window.draw(wheel);
            window.display();
        }
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }
        }
    }
    return 0;
}