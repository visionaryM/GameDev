#include <SFML/Graphics.hpp>

int main()
{
	//Context Setting Sharpen the shape
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800,800), "SFML works!", sf::Style::Default, settings);
	//Traingle
	sf::CircleShape traingle(100.f,3);
	//Circle
	sf::CircleShape circle(100.f);
	//Shape having n sides
	int n = 4;
	sf::CircleShape shape_n(100.f,n);
	//Rectanle
	sf::RectangleShape rectangle(sf::Vector2f(120,50));
	//Convex Shape with n sides
	sf::ConvexShape convex_shape(n);
	//Line
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(10,10)),
		sf::Vertex(sf::Vector2f(150,150))
	};
	//Texture
	// sf::Texture texture;
	// shape.setTexture(&texture);
	// shape.setTextureRect(sf::IntRect(10,10,100,100));

	//Color Combination and Axis
	// shape.setFillColor(sf::Color::Transparent);
	// shape.setOutlineThickness(5.f);
	// shape.setOutlineColor(sf::Color::Red);
	// shape.setFillColor(sf::Color::White);
	// shape.setPosition(x-axis,y-axis);
	while(window.isOpen())
	{
		sf::Event event;
		// for(int j=0;j<4;j++){
		// 	for(int i=1;i<800;i++)
		// 	{
		// 		shape.setPosition(i,i);
		// 		window.clear();
		// 		window.draw(shape);
		// 		window.draw(lines);
		// 		window.display();
		// 	}
		// }
		while(window.pollEvent(event))
		{
			if(event.type==sf::Event::Closed)
			{
				window.close();
			}
		}
		// window.close();
		//window.draw(line, 2, sf::Lines);
		// window.draw(everything except line);
		window.display();
	}
	return 0;	
}
