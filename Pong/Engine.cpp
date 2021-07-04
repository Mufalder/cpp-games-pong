#include "Engine.h"

int Engine::screenHeight = 0;
int Engine::screenWidth = 0;
float Engine::time = 0;

//Call update method on all game objects
void Engine::update(float delta)
{
	std::list<GameObject*>::iterator it;
	for (it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		(*it)->update(delta);
	}
}

//Call draw method on all game objects
void Engine::draw()
{
	window.clear();
	std::list<GameObject*>::iterator it;
	for (it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		(*it)->draw(&window);
	}
	window.display();
}

//Start the engine
void Engine::start()
{
	std::srand(std::time(nullptr));

	sf::Clock clock;

	while (window.isOpen())
	{
		//Calculate frame time and overall run time
		sf::Time dt = clock.restart();
		float delta = dt.asSeconds();
		Engine::time += delta;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		update(delta);
		draw();
	}
}

Engine::Engine(sf::VideoMode videoMode, std::string caption, int style, sf::ContextSettings settings)
{
	window.create(videoMode, caption, style, settings);
	Engine::screenWidth = videoMode.width;
	Engine::screenHeight = videoMode.height;
}