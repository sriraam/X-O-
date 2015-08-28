#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>


using namespace :: std;

sf::RenderWindow window;
sf::Vector2i m_pos;
char repo[3][3];
int i, j, k, b,counts=0;
int fills = 0;
int turn = 1,fini;
bool win = false,but=false;
sf::Sprite empty;
sf::Texture emptytexture;
sf::Sprite selected[9];



bool grid[9] = { false, false, false, false, false, false, false, false, false };


void clearing(){
	
				if (!emptytexture.loadFromFile("empty.png")){
					cout << "Texture empty is missing";
				}
				empty.setTexture(emptytexture);

				for (i = 0; i < 9; i++){
					
					grid[i] = false;
					selected[i] = empty;
				}
				for (j = 0; j < 3; j++){
					for (k = 0; k < 3; k++){
						repo[j][k] = 'e';
					}
				}
				
				fills = 0;
				win = false;
			}
	
int tie(){
	
	fills++;
	return 0;
		
}
char winner(){
	//if (repo[0] == 'x' && repo[1] == 'x' && repo[2] == 'x'){

	//	}
	if (repo[0][0] == 'x' && repo[0][0] == repo[0][1] && repo[0][0] == repo[0][2]){
		return 'x';
	}//Row 1
	else if (repo[0][0] == 'x' && repo[0][0] == repo[1][0] && repo[0][0] == repo[2][0]){
		return 'x';//column 1
	}
	else if (repo[0][1] == 'x' && repo[0][1] == repo[1][1] && repo[0][1] == repo[2][1]){
		return 'x';//colum 2
	}
	else if (repo[0][2] == 'x' && repo[0][2] == repo[1][2] && repo[0][2] == repo[2][2]){
		return 'x';//column 3
	}
	else if (repo[1][0] == 'x' && repo[1][0] == repo[1][1] && repo[1][0] == repo[1][2]){
		return 'x';//row 2
	}
	else if (repo[2][0] == 'x' && repo[2][0] == repo[2][1] && repo[2][0] == repo[2][2]){
		return 'x';//row 3
	}
	else if (repo[1][1] == 'x' && repo[1][1] == repo[0][0] && repo[1][1] == repo[2][2]){
		return 'x';//
	}
	else if (repo[1][1] == 'x' && repo[1][1] == repo[0][2] && repo[1][1] == repo[2][0]){
		return 'x';//diag r
	}
	else if (repo[1][1] == 'x' && repo[1][1] == repo[0][2] && repo[1][1] == repo[2][0]){
		return 'x';//diag l
	}


	// OOOO
	else if (repo[0][0] == 'o' && repo[0][0] == repo[0][1] && repo[0][0] == repo[0][2]){
		return 'o';
	}//Row 1
	else if (repo[0][0] == 'o' && repo[0][0] == repo[1][0] && repo[0][0] == repo[2][0]){
		return 'o';//column 1
	}
	else if (repo[0][1] == 'o' && repo[0][1] == repo[1][1] && repo[0][1] == repo[2][1]){
		return 'o';//colum 2
	}
	else if (repo[0][2] == 'o' && repo[0][2] == repo[1][2] && repo[0][2] == repo[2][2]){
		return 'o';//column 3
	}
	else if (repo[1][0] == 'o' && repo[1][0] == repo[1][1] && repo[1][0] == repo[1][2]){
		return 'o';//row 2
	}
	else if (repo[2][0] == 'o' && repo[2][0] == repo[2][1] && repo[2][0] == repo[2][2]){
		return 'o';
		cout << "O is here";//row 3
	}
	else if (repo[1][1] == 'o' && repo[1][1] == repo[0][0] && repo[1][1] == repo[2][2]){
		return 'o';//diag r
	}
	else if (repo[1][1] == 'o' && repo[1][1] == repo[0][2] && repo[1][1] == repo[2][0]){
		return 'o';//diag l
	}
	else{
		return 's';
	}
	
}
	


	

int main(){

	
	sf::Vector2i dimension(300, 400);
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Sprite x;
	sf::Sprite o;
	sf::Texture textureo;
	sf::Texture texturex;
	
	

	
	sf::Sprite sxo;
	
	char play;
	int i; 

	

	bool start = true, tap = false;
	
	sf::Font font;
	font.loadFromFile("Transformers Movie.ttf");

	sf::Text playerx;
	playerx.setString("X WON THE GAME");
	playerx.setColor(sf::Color::Red);
	playerx.setStyle(sf::Text::Regular);
	playerx.setCharacterSize(30);
	playerx.setFont(font);
	playerx.setPosition(20, 20);

	sf::Text playero;
	playero.setString("O WON THE GAME");
	playero.setColor(sf::Color::Green);
	playero.setStyle(sf::Text::Regular);
	playero.setCharacterSize(30);
	playero.setFont(font);
	playero.setPosition(20, 20);


	sf::Text playertie;
	playertie.setString("The Game is Tie");
	playertie.setColor(sf::Color::Black);
	playertie.setStyle(sf::Text::Regular);
	playertie.setCharacterSize(30);
	playertie.setFont(font);
	playertie.setPosition(20, 20);
	
	sf::Text reset;
	reset.setString("Press SPACE BAR to Start");
	reset.setFont(font);
	reset.setColor(sf::Color::Black);
	reset.setCharacterSize(20);
	//reset.setStyle();
	reset.setPosition(sf::Vector2f(25, 230));

	sf::RectangleShape button;
	button.setSize(sf::Vector2f(300, 300));
	button.setPosition(0, 100);
	


	//int bound = player1.getLocalBounds().width;


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
				play = 'o';
			}
			else{

				sxo = x;
				play = 'x';
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

				if (tap == true){
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){

						turn = 1;
						tap = false;
						clearing();

					}
			}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
					m_pos.x = event.mouseButton.x;
					m_pos.y = event.mouseButton.y;


					counts++;
					std::cout << "Mousex" << m_pos.x << " Mousey" << m_pos.y << std::endl;



					/*
				   THE BELOW if statements are to divide the coordinates of the selected region
				   Grid[]--> boolean opearion ,which avoids the repeated selection of region
				   Turn  --> at each turn x & o changes alternatively.
				   it is used to swap the x and o display using even oper
				   selected[a]-->It is a sprite,which holds the X and O image of selected region.
				   a-> depends upon selected region,
				   it stores x & O alternatively using turn condition at initial
				   repo[]-->same like selected,instead of image it contains char for validating the result
				   */

					/*if (m_pos.x > 0 && m_pos.x <= 300 && m_pos.y > 100 && m_pos.y < 400){
						if (tap == true){
							turn = 1;
							tap = false;
							start = true;
							clearing();


							//cout << "grid values":

						}
					}*/

					
						if (m_pos.x > 1 && m_pos.x <= 100 && m_pos.y > 100 && m_pos.y < 200){

							if (grid[0] == false){
								grid[0] = true;
								tie();
								cout << "X";

								selected[0] = sxo;

								selected[0].setPosition(25, 115);
								repo[0][0] = play;
								turn++;
							}
						}
						if (m_pos.x > 100 && m_pos.x <= 200 && m_pos.y > 100 && m_pos.y < 200){
							if (grid[1] == false){
								grid[1] = true;
								tie();
								cout << "X";
								turn++;
								selected[1] = sxo;
								selected[1].setPosition(120, 115);
								repo[0][1] = play;
							}
						}
						if (m_pos.x > 200 && m_pos.x <= 300 && m_pos.y > 100 && m_pos.y <= 200){
							if (grid[2] == false){
								grid[2] = true;
								tie();
								cout << "X";
								turn++;
								selected[2] = sxo;
								selected[2].setPosition(220, 115);
								repo[0][2] = play;
							}
						}
						if (m_pos.x > 1 && m_pos.x <= 100 && m_pos.y > 200 && m_pos.y <= 300){
							if (grid[3] == false){
								grid[3] = true;
								tie();
								cout << "X";
								turn++;
								tie();
								selected[3] = sxo;
								selected[3].setPosition(25, 215);
								repo[1][0] = play;
							}
						}
						if (m_pos.x > 100 && m_pos.x <= 200 && m_pos.y > 200 && m_pos.y <= 300){
							if (grid[4] == false){
								grid[4] = true;
								tie();
								cout << "X";
								turn++;
								selected[4] = sxo;
								selected[4].setPosition(120, 215);
								repo[1][1] = play;
							}
						}
						if (m_pos.x > 200 && m_pos.x <= 300 && m_pos.y > 200 && m_pos.y <= 300){
							if (grid[5] == false){
								grid[5] = true;
								tie();
								cout << "X";
								turn++;
								selected[5] = sxo;
								selected[5].setPosition(220, 215);
								repo[1][2] = play;
							}
						}
						if (m_pos.x > 1 && m_pos.x <= 100 && m_pos.y > 300 && m_pos.y <= 400){
							if (grid[6] == false){
								grid[6] = true;
								tie();
								cout << "X";
								turn++;
								selected[6] = sxo;
								selected[6].setPosition(25, 315);
								repo[2][0] = play;
							}
						}
						if (m_pos.x > 100 && m_pos.x <= 200 && m_pos.y > 300 && m_pos.y <= 400){
							if (grid[7] == false){
								grid[7] = true;
								tie();
								cout << "X";
								turn++;
								selected[7] = sxo;
								selected[7].setPosition(120, 315);
								repo[2][1] = play;
							}
						}
						if (m_pos.x > 200 && m_pos.x <= 300 && m_pos.y > 300 && m_pos.y <= 400){
							if (grid[8] == false){
								grid[8] = true;
								tie();
								cout << "X";
								turn++;
								selected[8] = sxo;
								selected[8].setPosition(220, 315);
								repo[2][2] = play;
							}
						}

					
				}
			}

			if (win == false){

				if (winner() == 'x'){
					win = true;
					start = false;
					cout << "THE WINNER IS X";
					for (i = 0; i < 9; i++){
						grid[i] = true;
					}
					tap = true;
					//clearing();	
				}
				else if (winner() == 'o'){
					win = true;
					start = false;
					cout << "THE WINNER IS O";
					tap = true;
					//	clearing();

				}
				else if (fills == 10){
					win = true;
					start = false;
					cout << "The Game is Tie";
					tap = true;
					//	clearing();

				}
			}


			window.draw(sprite);
			for (i = 0; i < 9; i++){
				window.draw(selected[i]);
			}
			//window.draw(button);
			if (tap == true){
				if (winner() != 's'){
					if (play == 'o'){
						button.setFillColor(sf::Color(255, 0, 0, 100));
						window.draw(button);
						window.draw(reset);
						window.draw(playerx);
					}
					else 
					{
						button.setFillColor(sf::Color(0, 255, 0, 100));
						window.draw(button);
						window.draw(reset);
						window.draw(playero);
					}
				}
				else{
					button.setFillColor(sf::Color(255, 255, 255, 100));
					window.draw(button);
					window.draw(reset);
					window.draw(playertie);
				}
			}
			window.display();
		

	}
 }
 