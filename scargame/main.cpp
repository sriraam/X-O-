#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>


using namespace ::std;
int main(){

	sf::RenderWindow window;
	sf::Vector2i dimension(300,400);
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Sprite x;
	sf::Texture texturex;
	sf::Vector2i m_pos;


	sf::Font font;
	
	
	sf::Text txtx,txto;
	font.loadFromFile("Transformers Movie.ttf");
	txtx.setFont(font);
	txtx.setString("X");
	txtx.setColor(sf::Color::Red);
	txtx.setStyle(sf::Text::Regular);
	txtx.setCharacterSize(100);
	
	bool grid[] = { false, false, false, false, false, false, false, false, false };
	
	window.create(sf::VideoMode(dimension.x,dimension.y),"My Game");
	if (!texture.loadFromFile("bg.jpg"))
	{
		cout << "Texture file is missing" << endl;
	}
	if (!texturex.loadFromFile("x1.png"))
	{
		cout << "Texture file is missing" << endl;
	}
	sprite.setTexture(texture);
	x.setTexture(texturex);
	window.draw(sprite);
	while (window.isOpen()){
	
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == event.Closed){
				window.close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				m_pos.x = event.mouseButton.x;
				m_pos.y = event.mouseButton.y;
				
				std::cout << "Mousex" << m_pos.x << " Mousey" << m_pos.y << std::endl;
				if (m_pos.x > 1 && m_pos.x <= 100 && m_pos.y>100 && m_pos.y < 200){
					if (grid[0] == false){
						grid[0] = true;
						x.setPosition(25, 115);
						cout << "X";
						window.draw(x);
					}
				}
				if (m_pos.x > 100 && m_pos.x <= 200 && m_pos.y>100 && m_pos.y < 200){
					if (grid[1] == false){
						grid[1] = true;
						x.setPosition(120, 115);
						cout << "X";
						window.draw(x);
					}
				}
				if (m_pos.x > 200 && m_pos.x <= 300  && m_pos.y>100 && m_pos.y <= 200){
					if (grid[2] == false){
						grid[2] = true;
						x.setPosition(220, 115);
						cout << "X";
						window.draw(x);
					}
				}
				if (m_pos.x > 1 && m_pos.x <= 100 && m_pos.y>200 && m_pos.y <= 300){
					if (grid[3] == false){
						grid[3] = true;
						x.setPosition(25, 215);
						cout << "X";
						window.draw(x);
					}
				}
				if (m_pos.x > 100 && m_pos.x <= 200 && m_pos.y>200 && m_pos.y <= 300){
					if (grid[4] == false){
						grid[4] = true;
						x.setPosition(120, 215);
						cout << "X";
						window.draw(x);
					}
				}
				if (m_pos.x > 200 && m_pos.x <= 300 && m_pos.y>200 && m_pos.y <= 300){
					if (grid[5] == false){
						grid[5] = true;
						x.setPosition(220, 215);
						cout << "X";
						window.draw(x);
					}
				}
				if (m_pos.x > 1 && m_pos.x <= 100 && m_pos.y>300 && m_pos.y <= 400){
					if (grid[6] == false){
						grid[6] = true;
						x.setPosition(25, 315);
						cout << "X";
						window.draw(x);
					}
				}
				if (m_pos.x > 100 && m_pos.x <= 200 && m_pos.y>300 && m_pos.y <= 400){
					if (grid[7] == false){
						grid[7] = true;
						x.setPosition(120, 315);
						cout << "X";
						window.draw(x);
					}
				}
				if (m_pos.x > 200 && m_pos.x <= 300 && m_pos.y>300 && m_pos.y <= 400){
					if (grid[8] == false){
						grid[8] = true;
						x.setPosition(220, 315);
						cout << "X";
						window.draw(x);
					}
				}

			}
		}
		
		
		window.display();
	}
	
}