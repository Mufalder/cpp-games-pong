#include "GUI.h"
#include "Game.h"

void GUI::update(float delta)
{
}

void GUI::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < 16; i++)
	{
		line.setPosition(sf::Vector2f(319, i * 30 + 5));
		window->draw(line);
	}

	text.setString(Game::getScore(false));
	text.setPosition(sf::Vector2f(200, 50));
	window->draw(text);
	text.setString(Game::getScore(true));
	text.setPosition(sf::Vector2f(320, 50));
	window->draw(text);
}

GUI::GUI()
{
	font.loadFromFile("blank-Regular.ttf");
	text.setFont(font);
	text.setCharacterSize(60);
	text.setLetterSpacing(0);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Regular);
	line.setSize(sf::Vector2f(2, 20));
}