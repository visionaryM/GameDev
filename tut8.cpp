#include <assert.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(600,600),"Text,Texture,Sound and Music");
    sf::Font font;
    sf::Text text;
    sf::Texture texture;
    sf::Texture texture1;
    sf::Texture texture2;
    sf::SoundBuffer buf;
    sf::Sound sound;
    sf::Music music;
    sf::CircleShape circle(150.f);
    // int frame = 0;
    assert(texture.loadFromFile("resources/image/bossbaby.jpeg"));
    assert(texture1.loadFromFile("resources/image/bossbaby1.jpeg"));
    assert(texture2.loadFromFile("resources/image/bossbaby2.jpeg"));
    assert(font.loadFromFile("resources/fonts/priscilla_2/Priscilla.ttf"));
    assert(buf.loadFromFile("resources/audio/Tiger.wav"));
    assert(music.openFromFile("resources/audio/ForestDay.wav"));
    text.setString("My Name is \nBoss Baby!");
    text.setCharacterSize(50);
    text.setColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold|sf::Text::Underlined);
    // text.setRotation(50.f);
    text.setFont(font);
    sound.setBuffer(buf);
    sound.play();
    music.setLoop(true);
    music.play();
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
        window.clear();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            circle.setTexture(&texture, true);
            text.setPosition(150,80);
            text.setRotation(30.f);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            circle.setTexture(&texture2, true);
            text.setPosition(250,150);
            text.setRotation(0.f);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            circle.setTexture(&texture1, true);
            text.setPosition(50,250);
            text.setRotation(0.f);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            text.setPosition(0,0);
            text.setRotation(0.f);
        }
        circle.setPosition(200,200);
        circle.setTextureRect(sf::IntRect(0,0,600,600));
        // circle.setOutlineColor(sf::Color::Red);
        // circle.setOutlineThickness(2);
        window.draw(circle);
        window.draw(text);
        // circle.setPosition(300,300);
        // circle.setTextureRect(sf::IntRect(0+frame*600,0+frame*600,600,600));
        // circle.setOutlineThickness(0);
        // window.draw(circle);
        // frame = (frame + 1) % 3;
        window.display();
    }
    return 0;
}