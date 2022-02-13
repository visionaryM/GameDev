#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <assert.h>
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(800,800),"Sprite and Shape");
	Sprite sprite;
	Texture texture;
	assert(texture.loadFromFile("resources/image/spider.jpeg"));
	sprite.setTexture(texture);
	float frame = 0;
	float speed = 0.005f;
	//creating an empty, convex shape
	ConvexShape convex;
	//resize it to 6 point
	convex.setPointCount(6);
	//define points in clockwise order
	convex.setPoint(0,Vector2f(0,0));
	convex.setPoint(1,Vector2f(50,50));
	convex.setPoint(2,Vector2f(50,100));
	convex.setPoint(3,Vector2f(0,150));
	convex.setPoint(4,Vector2f(-50,100));
	convex.setPoint(5,Vector2f(-50,50));
	while(window.isOpen())
	{
		Event event;
		if(Keyboard::isKeyPressed(Keyboard::W))
		{
			window.close();
		}
		while(window.pollEvent(event))
		{
			if(event.type==Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		sprite.setTextureRect(IntRect((int)frame%3*200, 0, 400, 400));
		sprite.setPosition(200,200);
		sprite.setScale(1,1);
		window.draw(sprite);
		sprite.setPosition(600,200);
		sprite.setScale(-1,1);
		window.draw(sprite);
		frame += speed;
		convex.setFillColor(Color::Red);
		convex.setPosition(100,300);
		window.draw(convex);
		window.display();
	}
	return 0;
}
