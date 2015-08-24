#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>


using namespace ::std;
int main(){

	sf::RenderWindow window;
	sf::Vector2i dimension(300, 400);
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Sprite x;
	sf::Sprite o;
	sf::Texture textureo;
	sf::Texture texturex;
	sf::Vector2i m_pos;
	sf::Sprite selected[8];
	sf::Sprite sxo;
	int turn = 1; 

	bool start = false;

	sf::Font font;
	font.loadFromFile("Transformers Movie.ttf");

	sf::Text player1;
	player1.setString("PLAYER 1 TURN");
	player1.setColor(sf::Color::Red);
	player1.setStyle(sf::Text::Regular);
	player1.setCharacterSize(35);
	player1.setFont(font);

	sf::Text player2;
	player2.setString("PLAYER 2 TURN");
	player2.setColor(sf::Color::Red);
	player2.setStyle(sf::Text::Regular);
	player2.setCharacterSize(30);
	player2.setFont(font);


	int bound = player1.getLocalBounds().width;

	bool grid[] = { false, false, false, false, false, false, false, false, false };

	window.create(sf::VideoMode(dimension.x, dimension.y), "My Game");
	if (!texture.loadFromFile("bg.jpg"))
	{
		cout << "Texture file bg is missing" << endl;
	}
	if (!texturex.loadFromFile("x1.png"))
	{
		cout << "Texture file X is missing" << endl;
	}
	if (!textureo.loadFromFile("o.png")){
		cout << "Texture file O is missing";
	}
	sprite.setTexture(texture);
	x.setTexture(texturex);
	o.setTexture(textureo);

	

	

	
	while (window.isOpen()){
		if (turn % 2 == 0){
			
			sxo = o;
		}
		else{
			sxo = x;
		}

		/*if (start == false){
			player1.setPosition(15, 25);
			window.draw(player1);

		}
		else{

			player2.setPosition(15, 25);
			window.draw(player2);
			window.display();
		}
		*/
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == event.Closed){
				window.close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				m_pos.x = event.mouseButton.x;
				m_pos.y = event.mouseButton.y;
				start = true;

				std::cout << "Mousex" << m_pos.x << " Mousey" << m_pos.y << std::endl;
				if (m_pos.x > 1 && m_pos.x <= 100 && m_pos.y > 100 && m_pos.y < 200){

					if (grid[0] == false){
						grid[0] = true;
						
						cout << "X";
						turn++;
						selected[0] = sxo;
						selected[0].setPosition(25, 115);
						
					}
				}
				if (m_pos.x > 100 && m_pos.x <= 200 && m_pos.y > 100 && m_pos.y < 200){
					if (grid[1] == false){
						grid[1] = true;
						
						cout << "X";
						turn++;
						selected[1] = sxo;
						selected[1].setPosition(120, 115);
						
					}
				}
				if (m_pos.x > 200 && m_pos.x <= 300 && m_pos.y > 100 && m_pos.y <= 200){
					if (grid[2] == false){
						grid[2] = true;
						
						cout << "X";
						turn++;
						selected[2] = sxo;
						selected[2].setPosition(220, 115);
						
					}
				}
				if (m_pos.x > 1 && m_pos.x <= 100 && m_pos.y > 200 && m_pos.y <= 300){
					if (grid[3] == false){
						grid[3] = true;
						
						cout << "X";
						turn++;
						selected[3] = sxo;
						selected[3].setPosition(25, 215);
						
					}
				}
				if (m_pos.x > 100 && m_pos.x <= 200 && m_pos.y > 200 && m_pos.y <= 300){
					if (grid[4] == false){
						grid[4] = true;
						
						cout << "X";
						turn++;
						selected[4] = sxo;
						selected[4].setPosition(120, 215);
						
					  }
				}
				if (m_pos.x > 200 && m_pos.x <= 300 && m_pos.y > 200 && m_pos.y <= 300){
					if (grid[5] == false){
						grid[5] = true;
						
						cout << "X";
						turn++;
						selected[5] = sxo;
						selected[5].setPosition(220, 215);
					
					}
				}
				if (m_pos.x > 1 && m_pos.x <= 100 && m_pos.y > 300 && m_pos.y <= 400){
					if (grid[6] == false){
						grid[6] = true;
						
						cout << "X";
						turn++;
						selected[6] = sxo;
						selected[6].setPosition(25, 315);
						
					}
				}
				if (m_pos.x > 100 && m_pos.x <= 200 && m_pos.y > 300 && m_pos.y <= 400){
					if (grid[7] == false){
						grid[7] = true;
						
						cout << "X";
						turn++;
						selected[7] = sxo;
						selected[7].setPosition(120, 315);
						
					}
				}
				if (m_pos.x > 200 && m_pos.x <= 300 && m_pos.y > 300 && m_pos.y <= 400){
					if (grid[8] == false){
						grid[8] = true;
						
						cout << "X";
						turn++;
						selected[8] = sxo;
						selected[8].setPosition(220, 315);
						
					}
				}

			}
		}

		window.draw(sprite);
		window.draw(selected[2]);
		window.display();
	}

}