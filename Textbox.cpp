#include "TextBox.h"

TextBox::TextBox(float X, float Y, int W, int H, char* filename, int alpha, char* text)
	:GUI(X, Y, W, H, filename, alpha, false){


	sf::Font tomahabd;
	tomahabd.loadFromFile("test/font/tahomabd.ttf");

	this->text.setString(text);
	this->text.setFont(tomahabd);
	this->text.setCharacterSize(36);

}