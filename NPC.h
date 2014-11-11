#pragma once
#include "Character.h"
#include "Timer.h"
#include "GUI.h"

class NPC : public Character{ //tolua_export
private:

	sf::Font font;
	sf::Text conversation;
	///Not sure how to reimplement Text class yet
	//Text conversationtext;

	std::string examination;

	bool bIsMobile; //Flag to determine the ability for the NPC to move--useful for conversations, etc...
	sf::Texture _portraitTexture;
	sf::Sprite _portraitSprite;

public:
	//tolua_begin
	NPC(float X, float Y, int W, int H, char* name, int HP, int MP, char* filename);
	
	void setConversation(char* c);
	sf::Text& getConversation(){ return conversation; }
	void freeze(){ bIsMobile = false; }
	void unfreeze(){ bIsMobile = true; }
	//tolua_end
	void moveAI();
	virtual void update(); //Might not even need

	sf::Sprite& getPortraitSprite(){ return _portraitSprite; }

virtual ~NPC();
	Timer npcTimer;



	std::string getExamination() { return examination; }

};