#include "Racket.h"
#include "Engine.h"
#include "Ball.h"

std::list<Racket*> Racket::rackets = std::list<Racket*>();

void Racket::update(float delta)
{
	//Racket movement
	if (player)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			pos.y -= speed * delta;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			pos.y += speed * delta;
		}
	}
	else
	{
		if (pos.y > Ball::pos.y)
			pos.y -= speed * delta;
		else if (pos.y < Ball::pos.y)
			pos.y += speed * delta;
	}

	//Clamp racket position
	if (pos.y < 0)
		pos.y = 0;
	if (pos.y > Engine::screenHeight - size.y)
		pos.y = Engine::screenHeight - size.y;

	shape.setPosition(pos);
}

void Racket::draw(sf::RenderWindow* window)
{
	window->draw(shape);
}

void Racket::reset()
{
	//Reset racket position
	pos.y = Engine::screenHeight / 2 - size.y / 2;
}

Racket::Racket(bool isPlayer)
{
	player = isPlayer;

	speed = 320;
	size = sf::Vector2f(4, 60);
	pos.x = player ? Engine::screenWidth - 54 : 50;
	pos.y = Engine::screenHeight / 2 - size.y / 2;

	shape.setFillColor(sf::Color::White);
	shape.setSize(size);
	shape.setPosition(pos);

	rackets.push_back(this);
}