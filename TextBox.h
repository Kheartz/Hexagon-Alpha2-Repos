#pragma once

#include "GUI.h"

class TextBox : public GUI{
private:
	sf::Text text;
public:
	TextBox(float X, float Y, int W, int H, char* filename, int alpha, char* text);

};
/*
text.setCharacterSize(static_cast<unsigned int>(height));

// Get the size of the text
sf::FloatRect bounds = text.getLocalBounds();

// The text still has too fit inside the area
if (bounds.width > width)
{
	// Adjust the text size
	text.setCharacterSize(static_cast<unsigned int>((height * width) / bounds.width));
}*/