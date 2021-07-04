#pragma once
#include "GameObject.h"

class Racket : public GameObject
{
private:
	bool player;
	float speed;
	sf::RectangleShape shape;

public:
	sf::Vector2f pos;
	sf::Vector2f size;

	Racket(bool isPlayer);

	void update(float delta);
	void draw(sf::RenderWindow* window);
	void reset();

	static std::list<Racket*> rackets;
};