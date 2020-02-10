#include <SFML/Graphics.hpp>
#include "map.hpp"
#include <cmath>
#include <sstream>

int main()
{
	sf::Clock timer;

	sf::Font font;
	sf::Text fps;
	std::ostringstream s;
	font.loadFromFile("../res/inconsolata.ttf");
	fps.setFont(font);
	fps.setFillColor(sf::Color::White);
	fps.setPosition(0, 0);
	fps.setString("60");

	double posX = 22, posY = 12;             //x and y start position
	double dirX = -1, dirY = 0;              //initial direction vector
	double planeX = 0, planeY = 0.66;        //the 2d raycaster version of camera plane

	double frameTime;                        //frameTime is the time this frame has taken, in seconds
	double moveSpeed = 0;                    //the constant value is in squares/second
	double rotSpeed = 0;                     //the constant value is in radians/second

	sf::VertexArray screen(sf::Lines);

	sf::RectangleShape floor(sf::Vector2f(screenWidth, screenHeight / 2.0));
	floor.setPosition(0, screenHeight / 2.0);
	floor.setFillColor(sf::Color(64, 32, 64));

	sf::CircleShape crosshair(2.0);
	crosshair.setPosition(screenWidth / 2.0 - 1, screenHeight / 2.0 - 1);
	crosshair.setFillColor(sf::Color(255, 255, 255, 200));

	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Raycaster");
	window.setFramerateLimit(60);

	window.setMouseCursorVisible(false);

	while (window.isOpen()) {
		timer.restart();
		sf::Event event = {};
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			} else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
					break;
				}
			}
		}
		window.clear();
		screen.clear();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			if (worldMap[int(posX + dirX * moveSpeed)][int(posY)] == 0) {
				posX += dirX * moveSpeed;
			}
			if (worldMap[int(posX)][int(posY + dirY * moveSpeed)] == 0) {
				posY += dirY * moveSpeed;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			if (worldMap[int(posX - dirX * moveSpeed)][int(posY)] == 0) {
				posX -= dirX * moveSpeed;
			}
			if (worldMap[int(posX)][int(posY - dirY * moveSpeed)] == 0) {
				posY -= dirY * moveSpeed;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (worldMap[int(posX - planeX * moveSpeed)][int(posY)] == 0) {
				posX -= planeX * moveSpeed;
			}
			if (worldMap[int(posX)][int(posY - planeY * moveSpeed)] == 0) {
				posY -= planeY * moveSpeed;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (worldMap[int(posX + planeX * moveSpeed)][int(posY)] == 0) {
				posX += planeX * moveSpeed;
			}
			if (worldMap[int(posX)][int(posY + planeY * moveSpeed)] == 0) {
				posY += planeY * moveSpeed;
			}
		}
		if (sf::Mouse::getPosition(window).x < screenWidth / 2.0) {
			//both camera direction and camera plane must be rotated
			double diff = std::abs(screenWidth / 2.0 - sf::Mouse::getPosition(window).x);
			rotSpeed *= (diff / 50.0);

			double oldDirX = dirX;
			dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
			dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
			double oldPlaneX = planeX;
			planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
			planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
		}
		if (sf::Mouse::getPosition(window).x > screenWidth / 2.0) {
			//both camera direction and camera plane must be rotated
			double diff = std::abs(screenWidth / 2.0 - sf::Mouse::getPosition(window).x);
			rotSpeed *= (diff / 50.0);

			double oldDirX = dirX;
			dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
			dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
			double oldPlaneX = planeX;
			planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
			planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
		}
		sf::Mouse::setPosition(sf::Vector2i(screenWidth / 2.0, screenHeight / 2.0), window);

		for (int x = 0; x < screenWidth; x++) {
			//calculate ray position and direction
			double cameraX = 2 * x / double(screenWidth) - 1; //x-coordinate in camera space
			double rayDirX = dirX + planeX * cameraX;
			double rayDirY = dirY + planeY * cameraX;

			//which box of the map we're in
			int mapX = int(posX);
			int mapY = int(posY);

			//length of ray from current position to next x or y-side
			double sideDistX;
			double sideDistY;

			//length of ray from one x or y-side to next x or y-side
			double deltaDistX = std::abs(1.0 / rayDirX);
			double deltaDistY = std::abs(1.0 / rayDirY);
			double perpWallDist;

			//what direction to step in x or y-direction (either +1 or -1)
			int stepX;
			int stepY;

			int hit = 0; //was there a wall hit?
			int side; //was a NS or a EW wall hit?

			//calculate step and initial sideDist
			if (rayDirX < 0) {
				stepX = -1;
				sideDistX = (posX - mapX) * deltaDistX;
			} else {
				stepX = 1;
				sideDistX = (mapX + 1.0 - posX) * deltaDistX;
			}
			if (rayDirY < 0) {
				stepY = -1;
				sideDistY = (posY - mapY) * deltaDistY;
			} else {
				stepY = 1;
				sideDistY = (mapY + 1.0 - posY) * deltaDistY;
			}

			//perform DDA
			while (hit == 0) {
				//jump to next map square, OR in x-direction, OR in y-direction
				if (sideDistX < sideDistY) {
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				} else {
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				//Check if ray has hit a wall
				if (worldMap[mapX][mapY] > 0) hit = 1;
			}

			//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
			if (side == 0) { perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX; }
			else { perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY; }

			//Calculate height of line to draw on screen
			int lineHeight = (int)(screenHeight / perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
			int drawStart = -lineHeight / 2 + screenHeight / 2;
			if (drawStart < 0) drawStart = 0;
			int drawEnd = lineHeight / 2 + screenHeight / 2;
			if (drawEnd >= screenHeight) drawEnd = screenHeight - 1;

			//choose wall color
			sf::Color color = sf::Color::Yellow;
			switch (worldMap[mapX][mapY]) {
				case 1:
					color = sf::Color::Red;
					break; //red
				case 2:
					color = sf::Color::Green;
					break; //green
				case 3:
					color = sf::Color::Blue;
					break; //blue
				case 4:
					color = sf::Color::White;
					break; //white
				default:
					break; //yellow
			}
			//give x and y sides different brightness
			if (side == 1) {
				color -= sf::Color(128, 128, 128, 0);
			}
			//draw the pixels of the stripe as a vertical line
			screen.append(sf::Vertex(sf::Vector2f(x, drawStart), color));
			screen.append(sf::Vertex(sf::Vector2f(x, drawEnd), color));
		}

		window.draw(floor);
		window.draw(screen);
		window.draw(fps);
		window.draw(crosshair);
		window.display();

		frameTime = timer.getElapsedTime().asSeconds();
		s.str("");
		s << (round(1.0 / frameTime));
		fps.setString(s.str());
		//speed modifiers
		moveSpeed = frameTime * 5.0; //the constant value is in squares/second
		rotSpeed = frameTime * 2.0; //the constant value is in radians/second
	}
	return 0;
}