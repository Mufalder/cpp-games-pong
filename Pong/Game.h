#pragma once
#include <string>

class Game
{
	
private:
	static int score_1;
	static int score_2;
	static std::string scoreToString(int score);

public:
	static void incScore(bool player);
	static std::string getScore(bool player);

};