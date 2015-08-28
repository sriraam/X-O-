#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>


using namespace :: std;
char repo[3][3];
int i, j;
int turn = 1;
sf::Sprite empty;
sf::Texture emptytexture;
sf::Sprite selected[9];



//bool grid[9];
/*void clearing(){
	for (i = 0; i < 9; i++){

	}
}*/



bool grid[9] = { false, false, false, false, false, false, false, false, false };
void clearing(){
	if (!emptytexture.loadFromFile("empty.png")){
		cout << "Texture empty is missing";
	}
	empty.setTexture(emptytexture);

	for (i = 0; i < 9; i++){
		grid[i] = false;
		turn = 1;
		selected[i] = empty;
	}

}
char winner(){
	//if (repo[0] == 'x' && repo[1] == 'x' && repo[2] == 'x'){
		
//	}
	if (repo[0][0] == 'x' && repo[0][0] == repo[0][1] && repo[0][0]==repo[0][2]){
		return 'x';	}//Row 1
	//if (repo[0][0] == 'x' && repo[0][0] == repo[1][1] && repo[0][0] == repo[2][2]){
	//	return 'x';//diag l
	//}
	if (repo[0][0] == 'x' && repo[0][0] == repo[1][0] && repo[0][0] == repo[2][0]){
		return 'x';//column 1
	}
	if (repo[0][1] == 'x' && repo[0][1] == repo[1][1] && repo[0][1] == repo[2][1]){
		return 'x';//colum 2
	}
	if (repo[0][2] == 'x' && repo[0][2] == repo[1][2] && repo[0][2] == repo[2][2]){
		return 'x';//column 3
	}
	if (repo[1][0] == 'x' && repo[1][0] == repo[1][1] && repo[1][0] == repo[1][2]){
		return 'x';//row 2
	}
	if (repo[2][0] == 'x' && repo[2][0] == repo[2][1] && repo[2][0] == repo[2][2]){
		return 'x';//row 3
	}
	//if (repo[0][2] == 'x' && repo[0][2] == repo[1][1] && repo[0][2] == repo[2][0]){
	//	return 'x';//diag r
	//}
	if (repo[1][1] == 'x' && repo[1][1] == repo[0][0] && repo[1][1] == repo[2][2]){
		return 'x';//
	}
	if (repo[1][1] == 'x' && repo[1][1] == repo[0][2] && repo[1][1] == repo[2][0]){
		return 'x';//diag r
	}
	if (repo[1][1] == 'x' && repo[1][1] == repo[0][2] && repo[1][1] == repo[2][0]){
		return 'x';//diag l
	}
	

	// OOOO
	if (repo[0][0] == 'o' && repo[0][0] == repo[0][1] && repo[0][0] == repo[0][2]){
		return 'o';
	}//Row 1
	//if (repo[0][0] == 'x' && repo[0][0] == repo[1][1] && repo[0][0] == repo[2][2]){
	//	return 'x';//diag l
	//}
	if (repo[0][0] == 'o' && repo[0][0] == repo[1][0] && repo[0][0] == repo[2][0]){
		return 'o';//column 1
	}
	if (repo[0][1] == 'o' && repo[0][1] == repo[1][1] && repo[0][1] == repo[2][1]){
		return 'o';//colum 2
	}
	if (repo[0][2] == 'o' && repo[0][2] == repo[1][2] && repo[0][2] == repo[2][2]){
		return 'o';//column 3
	}
	if (repo[1][0] == 'o' && repo[1][0] == repo[1][1] && repo[1][0] == repo[1][2]){
		return 'o';//row 2
	}
	if (repo[2][0] == 'o' && repo[2][0] == repo[2][1] && repo[2][0] == repo[2][2]){
		return 'o';//row 3
	}
	//if (repo[0][2] == 'x' && repo[0][2] == repo[1][1] && repo[0][2] == repo[2][0]){
	//	return 'x';//diag r
	//}
	if (repo[1][1] == 'o' && repo[1][1] == repo[0][0] && repo[1][1] == repo[2][2]){
		return 'o';//diag r
	}
	if (repo[1][1] == 'o' && repo[1][1] == repo[0][2] && repo[1][1] == repo[2][0]){
		return 'o';//diag l
	}

	

}
	


	

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
	
	sf::Sprite sxo;
	
	char play;
	int i; 

	

	bool start = false;
	bool win = false;
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
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				m_pos.x = event.mouseButton.x;
				m_pos.y = event.mouseButton.y;
				start = true;

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
				if (m_pos.x > 1 && m_pos.x <= 100 && m_pos.y > 100 && m_pos.y < 200){

					if (grid[0] == false){
						grid[0] = true;
						
						cout << "X";
						turn++;
						selected[0] = sxo;
						selected[0].setPosition(25, 115);
						repo[0][0] = play;
					}
				}
				if (m_pos.x > 100 && m_pos.x <= 200 && m_pos.y > 100 && m_pos.y < 200){
					if (grid[1] == false){
						grid[1] = true;
						
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
						
						cout << "X";
						turn++;
						selected[3] = sxo;
						selected[3].setPosition(25, 215);
						repo[1][0] = play;
					}
				}
				if (m_pos.x > 100 && m_pos.x <= 200 && m_pos.y > 200 && m_pos.y <= 300){
					if (grid[4] == false){
						grid[4] = true;
						
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
				cout << "THE WINNER IS X";
				clearing();

			}
			if (winner() == 'o'){
				win = true;
				cout << "THE WINNER IS O";
				clearing();
			}
		}

		/*if (grid[4] == true){
			for (i = 0; i < 9; i++){
				cout << repo[i]<<"\n";
				
			}
			grid[4] = false;
		}*/
		window.draw(sprite);
		for (i = 0; i < 9; i++){
			window.draw(selected[i]);
		}
		
		window.display();
	}

}