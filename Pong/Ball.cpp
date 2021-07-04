#include "Ball.h"
#include "Engine.h"
#include "Game.h"
#include "Utils.h"
#include "Racket.h"

sf::Vector2f Ball::pos = sf::Vector2f(0, 0);

void Ball::update(float delta)
{
	//Ball movement
	pos += sf::Vector2f(dir.x * speed * delta, dir.y * speed * delta);

	speed += delta * speedRiseRatio;
	//Clamp ball speed and make it red when it reaches its max speed
	if (speed > maxSpeed)
	{
		shape.setFillColor(sf::Color::Red);
		speed = maxSpeed;
	}

	//Add score if ball is on the edge of the screen
	if (pos.x <= 0)
	{
		Game::incScore(true);
		reset();
	}
	else if (pos.x >= Engine::screenWidth - radius * 2)
	{
		Game::incScore(false);
		reset();
	}

	//Ball collision
	std::list<Racket*>::iterator it;
	for (it = Racket::rackets.begin(); it != Racket::rackets.end(); ++it)
	{
		sf::Vector2f racketPos = (*it)->pos;
		sf::Vector2f racketSize = (*it)->size;
		
		if (pos.x >= racketPos.x - radius * 2 && pos.x <= racketPos.x + racketSize.x
			&& pos.y >= racketPos.y - radius * 2 && pos.y <= racketPos.y + racketSize.y)
			bounce_x();
	}

	//Bounce from top and bottom screen edges
	if (pos.y <= 0 || pos.y >= Engine::screenHeight - radius * 2)
		bounce_y();

	//Update shape position
	shape.setPosition(pos);
}

void Ball::draw(sf::RenderWindow* window)
{
	window->draw(shape);
}

void Ball::bounce_x()
{
	pos.x += (dir.x >= 0 ? -radius : radius);
	dir.x = -dir.x;
}

void Ball::bounce_y()
{
	dir.y = -dir.y;
	if (pos.y <= 0)
		pos.y = radius;
	else pos.y = Engine::screenHeight - radius * 3;
}

void Ball::reset()
{
	//Reset ball position, speed and direction.
	pos = sf::Vector2f(Engine::screenWidth / 2, Engine::screenHeight / 2);
	bool startDir = std::rand() % 2 == 1;
	float angle;
	if (startDir)
	{
		angle = std::rand() % 90 + 45;
	}
	else
	{
		angle = std::rand() % 90 + 225;
	}
	angle -= 90;
	if (angle < 0)
		angle = 360 + angle;
	angle = Utils::deg2Rad(angle);
	dir = sf::Vector2f(std::cosf(angle), -std::sinf(angle));

	speed = minSpeed;

	//Reset rackets
	//TODO: should be done by the reset event
	if (Engine::time > 0)
	{
		std::list<Racket*>::iterator it;
		for (it = Racket::rackets.begin(); it != Racket::rackets.end(); ++it)
		{
			(*it)->reset();
		}
	}
}

Ball::Ball(int radius, float minSpeed, float maxSpeed, float speedRiseRatio)
{
	this->radius = radius;
	this->minSpeed = minSpeed;
	this->maxSpeed = maxSpeed;
	this->speedRiseRatio = speedRiseRatio;

	reset();

	shape.setRadius(radius);
	shape.setFillColor(sf::Color::White);
}