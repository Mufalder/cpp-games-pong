#pragma once
#include <math.h>
#include "GameObject.h"

class Engine
{
private:
	sf::RenderWindow window;

	void update(float delta);
	void draw();

public:
	std::list<GameObject*> gameObjects;
	static int screenWidth;
	static int screenHeight;
	static float time;

	void start();

	Engine(sf::VideoMode videoMode, std::string caption, int style, sf::ContextSettings settings);
};