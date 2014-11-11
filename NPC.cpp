#include "NPC.h"
#include <iostream>
#include <fstream>
NPC::NPC(float X, float Y, int W, int H, char* name, int HP, int MP, char* filename) :
Character(X, Y, W, H, name, HP, MP, filename){
	bIsMobile = true;
	npcTimer.start();
	std::string filename_(filename);
	std::string temp; 
	std::ifstream FILE;

	
	font.loadFromFile("test/font/tahomabd.ttf");
	conversation.setFont(font);
	conversation.setCharacterSize(18);

	std::string nametmp = name;
	std::transform(nametmp.begin(), nametmp.end(), nametmp.begin(), ::tolower);
	_portraitTexture.loadFromFile("test/character/portrait/" + nametmp + ".png");
	_portraitSprite.setTexture(_portraitTexture);



}
NPC::~NPC()
{
	
}
void NPC::moveAI(){
	if (!npcTimer.isStarted() && xVel == 0 && yVel == 0)
	{
		npcTimer.start();
	}
	if (npcTimer.isStarted() && bIsMobile && npcTimer.get_ticks() > (rand() % 5500 + 2000) && xVel == 0 && yVel == 0){
		switch ((rand() % 4 + 1)){
		case 1: xVel = 1; this->direction = Character::FACING_DIRECTION::RIGHT; break;
		case 2: xVel = -1; this->direction = Character::FACING_DIRECTION::LEFT; break;
		case 3: yVel = 1; this->direction = Character::FACING_DIRECTION::DOWN; break;
		case 4: yVel = -1; this->direction = Character::FACING_DIRECTION::UP; break;
		default: break; //YOU DUN FUCKED UP
		}
	}

	if (npcTimer.isStarted() && npcTimer.get_ticks() > rand() % 10000 + 6000){
		xVel = 0;
		yVel = 0;
		npcTimer.stop(); 
	}
}

void NPC::update(){
	if (bIsMobile){
		if (xVel != 0)
			xFrame++;
		else if (yVel != 0)
			yFrame++;
		this->move(xVel, yVel);
	}
}

void NPC::setConversation(char* c){
	sf::String mystring(c);

	unsigned currentOffset = 0;
	bool firstWord = true;
	int wordBegining = 0;
	char currentChar;
	sf::Glyph glyph;
	for (std::size_t pos(0); pos < mystring.getSize(); ++pos) {
		
		currentChar = mystring[pos];
		if (currentChar == '\n' || currentChar == '\n' || currentChar == '\t' || currentChar == '\v'){
			currentOffset = 0;
			firstWord = true;
			continue;
		}
		else if (currentChar == ' ') {
			wordBegining = pos;
			firstWord = false;
		}

		glyph = font.getGlyph(currentChar, 32, false);
		currentOffset += glyph.advance;

		if (!firstWord && currentOffset > 800) {
			pos = wordBegining;
			mystring[pos] = '\n';
			firstWord = true;
			currentOffset = 0;
		}
	}
	conversation.setString(mystring);
}