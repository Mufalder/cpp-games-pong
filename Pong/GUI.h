#pragma once
#include "GameObject.h"


class GUI : public GameObject
{
private:
	sf::Font font;
	sf::Text text;
	sf::RectangleShape line;

public:
	GUI();

	void update(float delta);
	void draw(sf::RenderWindow* window);

};