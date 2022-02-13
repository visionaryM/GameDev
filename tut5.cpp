#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace std;

int distance(double x1, double y1, double x2, double y2)
{
    double ans;
    {
        double x = pow(x2-x1,2);
        double y = pow(y2-y1,2);
        ans = x+y;
    }
    return ans;
}

bool isright(double point1[], double point2[], double point3[])
{
    double p = distance(point1[0],point1[1],point2[0],point2[1]);
    double b = distance(point3[0],point3[1],point2[0],point2[1]);
    double h = distance(point1[0],point1[1],point3[0],point3[1]);
    if(p==b+h || b==p+h || h==p+b)
    {
        return true;
    }
    return false;
}
int main()
{
    double p1[2] = {1,4};
    double p2[2] = {5,6};
    double p3[2] = {2,3};
    sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(600,600), "SFML works!", sf::Style::Default, settings);
    sf::CircleShape circle(10.f);
	sf::Vertex line1[] =
	{
		sf::Vertex(sf::Vector2f(100*p1[0],100*p1[1])),
		sf::Vertex(sf::Vector2f(100*p2[0],100*p2[1]))
	};
    sf::Vertex line2[] =
	{
		sf::Vertex(sf::Vector2f(100*p2[0],100*p2[1])),
		sf::Vertex(sf::Vector2f(100*p3[0],100*p3[1]))
	};
    sf::Vertex line3[] =
	{
		sf::Vertex(sf::Vector2f(100*p1[0],100*p1[1])),
		sf::Vertex(sf::Vector2f(100*p3[0],100*p3[1]))
	};
    while(window.isOpen())
    {
        sf::Event event;
        if(isright(p1,p2,p3)==true)
        {
            window.draw(line1, 2, sf::Lines);
            window.draw(line2, 2, sf::Lines);
            window.draw(line3, 2, sf::Lines);
        }
        else
        {
            for(int i=0;i<50;i++)
            {
                window.clear();
                circle.setPosition(290+i,300);
                window.draw(circle);
                window.display();
            }
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