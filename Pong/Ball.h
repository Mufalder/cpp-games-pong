#pragma once
#include "GameObject.h"

class Ball : public GameObject
{
private:
	sf::CircleShape shape;
	sf::Vector2f dir;

	int radius;
	float speed;
	float minSpeed;
	float maxSpeed;
	float speedRiseRatio;

	void bounce_x();
	void bounce_y();
	void reset();

public:
	static sf::Vector2f pos;

	Ball(int radius, float minSpeed, float maxSpeed, float speedRiseRatio);

	void update(float delta);
	void draw(sf::RenderWindow* window);
};

