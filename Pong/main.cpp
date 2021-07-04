#include "Engine.h"
#include "GUI.h"
#include "Ball.h"
#include "Racket.h"

/*
*  --- Known issues ---
* 1) AI is too overpowered
* 2) Ball trajectory is too perfect. Maybe add little randomness when it bounces?
* 3) No game over.
*/

//Main class. Everything starts here.
int main()
{
	//Configure display
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	//Creating "engine" object that will handle drawing and update. 
	//TODO: Restrict multiple "Engine" objects from creating. Singleton?
	Engine engine(sf::VideoMode(640, 480), "Pong", sf::Style::Default, settings);

	//Creating game objects
	GUI* gui = new GUI();
	Ball* ball = new Ball(4, 260, 700, 5);
	Racket* player = new Racket(true);
	Racket* enemy = new Racket(false);
	//Pushing all game objects to the list.
	//TODO: Better to put it in the GO constructor?
	//TODO: Don't use list and find better solution?
	engine.gameObjects.push_back(gui);
	engine.gameObjects.push_back(ball);
	engine.gameObjects.push_back(player);
	engine.gameObjects.push_back(enemy);
	//Starting engine
	engine.start();

	return 0;
}