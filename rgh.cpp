#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#define M_PI 3.14159265358979323864
double velocity = 10; //feet/s
double t = 0; //sec
float angle = 45; //degree
double x = 0;
double y = 0;
double gravity = 32;
double dt = 0.01;
double basex = 640/5; //origin for curve
double basey = 480/2;
double scale = 60;
void update()
{
    double rad = angle * (M_PI / 180);
    x = velocity * cos(rad) * t;
    x = velocity * sin(rad) * t-gravity * t * t/2;
    t = t + dt;
}
double a = 1,b = 7, c = 1, d = 7, j = 3, k = 3;
void update2()
{
    x = cos(a*t) - pow(cos(b*t),j);
    x = cos(c*t) - pow(cos(d*t),k);
    t = t+dt;
}
int main()
{
    // sf::ContextSettings settings;
    // settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(640,480), "trajectory curve");
    sf::CircleShape shape(2.f);
    shape.setFillColor(sf::Color::Green);
    ///window.clear();
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
        update();
        shape.setPosition(sf::Vector2f((float)(basex + scale * x),(float)(basey - scale * y)));
        window.draw(shape);
        window.display();
    }
    return 0;
}