#pragma once
#include <string>
#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"

class Animation
{
public:
	std::string fileName = "";
	sf::IntRect coordinates;
	int coordinateWidth, coordinateHeight;
	int startPoint, startY, endPoint, incrementFrame, row;
	float time = 0.1;
	float switchTime = 0.8;
	float totalTime;
	bool flipped;

	void setFileName(std::string fileName);
	void setAnimation(int startX, int startY, int width, int height, int endPoint);
	void setStartEndPoints(int start, int end);
	void Animate(sf::RectangleShape &rect, float switchTime);
};

