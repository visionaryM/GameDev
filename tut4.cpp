//Bouncing Circle
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Problem");
    sf::CircleShape circle(10.f);
    while (window.isOpen())
    {
        sf::Event event;
        //     for(int i=0;i<600;i++)
        //     {
        //         window.clear();
        //         circle.setPosition(i,0);
        //         window.draw(circle);
        //         window.display();
        //     }
        //     for(int i=0;i<500;i++)
        //     {
        //         window.clear();
        //         circle.setPosition(600-i,i);
        //         window.draw(circle);
        //         window.display();
        //     }
        //     for(int i=0;i<500;i++)
        //     {
        //         window.clear();
        //         circle.setPosition(i,600-i);
        //         window.draw(circle);
        //         window.display();
        //     }
        for (int i = 0; i < 600; i++)
        {
            window.clear();
            circle.setPosition(300, i);
            window.draw(circle);
            window.display();
        }
        for(int i=0;i<500;i++)
        {
            window.clear();
            circle.setPosition(300, 600-i);
            window.draw(circle);
            window.display();
        }
        for(int i=100;i<600;i++)
        {
            window.clear();
            circle.setPosition(300, i);
            window.draw(circle);
            window.display();
        }
        for(int i=0;i<400;i++)
        {
            window.clear();
            circle.setPosition(300, 600-i);
            window.draw(circle);
            window.display();
        }
        for(int i=200;i<600;i++)
        {
            window.clear();
            circle.setPosition(300, i);
            window.draw(circle);
            window.display();
        }
        for(int i=0;i<300;i++)
        {
            window.clear();
            circle.setPosition(300, 600-i);
            window.draw(circle);
            window.display();
        }
        for(int i=300;i<600;i++)
        {
            window.clear();
            circle.setPosition(300, i);
            window.draw(circle);
            window.display();            
        }
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }
    return 0;
}