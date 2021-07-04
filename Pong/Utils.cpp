#include "Utils.h"

float Utils::pi = 3.14f;

float Utils::deg2Rad(float deg)
{
	return deg * pi / 180.0f;
}

float Utils::PI()
{
	return pi;
}