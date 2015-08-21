#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>


using namespace ::std;
int main(){

	sf::RenderWindow window;
	sf::Vector2i dimension(300,400);
	sf::Texture texture;
	sf::Sprite sprite;
	
	
	
	window.create(sf::VideoMode(dimension.x,dimension.y),"My Game");
	if (!texture.loadFromFile("bg.jpg"))
	{
		cout << "Texture file is missing" << endl;
	}

	sprite.setTexture(texture);
	while (window.isOpen()){
	
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == event.Closed){
				window.close();
			}
		}
		window.draw(sprite);
		window.display();
	}
	
}