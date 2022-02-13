#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <math.h>
#define M_PI 3.14159265358979323846
using namespace sf;
static float GetDistanceBetweenTwoPoints(float x, float y, float x2, float y2)
{
    return sqrt((x2-x)*(x2-x) + (y2-y)*(y2-y));
}
static float GetAngleBetweenTwoPoints(float x, float y, float x2, float y2)
{
    return atan2(y2-y,x2-x) * (180 / M_PI);
}
RenderWindow window(VideoMode(400,400),"tline subroutine");
RectangleShape line_xx;
void line(float x, float y, float x2, float y2, float width, Color color)
{
    Vector2f d(GetDistanceBetweenTwoPoints(x2,y2,x,y),width);
    line_xx.setPosition(x,y);
    line_xx.setSize(d);
    line_xx.setFillColor(color);
    line_xx.setRotation(GetAngleBetweenTwoPoints(x,y,x2,y2));
    window.draw(line_xx);
}

int main()
{
    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        line(200,200,300,200,1,Color::Green);
        line(200,200,200,300,1,Color::Red);
        line(200,200,100,200,1,Color::Blue);
        line(200,200,200,100,1,Color::Yellow);
        window.display();
    }
    return 0;
}