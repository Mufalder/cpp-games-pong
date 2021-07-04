#pragma once
#include <list>
#include <SFML/Graphics.hpp>

//Basic header for all game objects
class GameObject
{
public:
	GameObject() {};
	~GameObject() {};
	virtual void update(float delta) = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
};