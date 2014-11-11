#pragma once

#include "stdafx.h"
#include "NPC.h"
#include "Enemy.h"
#include "Item.h"
#include "Timer.h"
#include "Player.h"

#include <iostream>



class Quest
{
protected:
	std::string name; //Name of the quest
	char* examine; //Examine the quest
	bool bActive; //Flag to check for active quest
	bool bStarted; //Flag for started quest
	bool bSatisfied;
	bool bCompleted; //Flag for completed quest
	int xpGive; //Amount of Exp gained for completing
	int moniesGive;
	std::vector<char*> itemsGive; //Name will be passed into Item constructor.

	NPC* startNPC;
	NPC* endNPC; //NPC to hand quest to?

	int type;

	char* activeConvo;
	char* activecyConvo;
	char* activecnConvo;
	char* startedConvo;
	char* startedcnConvo;
	char* startedcyfConvo;
	char* startedcytConvo;
	char* doneConvo;
	std::vector<Quest*> preReqQ;

	Timer questStartTimer;

public: 
	Quest();
	virtual void Satisfy();
	virtual void completeQuest(){ bCompleted = true; }
	
	virtual void setStartNPC(NPC* n) { startNPC = n; }
	virtual NPC* getStartNPC(){ return startNPC; }
	virtual void setEndNPC(NPC* n) { endNPC = n; }
	virtual NPC* getEndNPC(){ return endNPC; }

	virtual void setName(char* Name){ name = Name; }
	virtual char* getName(){ return (char*)name.c_str(); }
	virtual void setExamine(char* Examine){ examine = Examine; }
	virtual char* getExamine(){ return examine; }

	virtual bool isActive(){ return bActive; }
	virtual bool isStarted(){ return bStarted; }
	virtual bool isSatisfied(){ return bSatisfied; }
	virtual bool isCompleted(){ return bCompleted; }

	virtual void setGiveXP(int xp){ xpGive = xp; }
	virtual int getGiveXP(){ return xpGive; }
	virtual void activate(){ bActive = true; }
	virtual void start();
	virtual void complete();
	virtual void update();

	virtual void setActiveConvo(char* s){ activeConvo = s; }
	virtual void setActivecyConvo(char* s){ activecyConvo = s; }
	virtual void setActivecnConvo(char* s){ activecnConvo = s; }
	virtual void setStartedConvo(char* s){ startedConvo = s; }
	virtual void setStartedcnConvo(char* s){ startedcnConvo = s; }
	virtual void setStartedcyfConvo(char* s){ startedcyfConvo = s; }
	virtual void setStartedcytConvo(char* s){ startedcytConvo = s; }
	virtual void setDoneConvo(char* s){ doneConvo = s; }
	virtual void printConversations() const;

	virtual int getType(){ return type; } //MAKE THIS ENUM

	virtual char* getActiveConvo(){ return activeConvo; }
	virtual char* getActivecyConvo(){ return activecyConvo; }
	virtual char* getActivecnConvo(){ return activecnConvo; }
	virtual char* getStartedConvo(){ return startedConvo; }
	virtual char* getStartedcnConvo(){ return startedcnConvo; }
	virtual char* getStartedcyfConvo(){ return startedcyfConvo; }
	virtual char* getStartedcytConvo(){ return startedcytConvo; }
	virtual char* getDoneConvo(){ return doneConvo; }

	virtual void addPreReqQ(Quest* q){ preReqQ.push_back(q); }
	virtual bool preReqsCompleted();

	virtual void pushItemsGive(char* i){ itemsGive.push_back(i); }
	virtual void award(Player* p);

	enum QUEST_TYPE{
		GOTONPC,
		KILLENEMIES,
		DELIVER,
		GOTOAREA
	};

	QUEST_TYPE questType;
	QUEST_TYPE getQuestType(){ return questType; }
	////std::vector<ITEMID>& getItemsGive(){ return itemsGive; } 
	
};

class Quest_Kill_Enemies : public Quest
{
private:
	Enemy* targetEnemy;
	int numberTotal; //Target number to kill for quest
	int numberKilled; //Number of Currently Killed foes

public:
	//Quest_Kill_Enemies(int Start_id, int End_id, int Enemy_id, int numberOf, int XP);
	Quest_Kill_Enemies(NPC* startNPC, NPC* endNPC, Enemy* enemy, int numberOf, int XP);
	Enemy* getTargetEnemy(){ return targetEnemy; }
	int getNumberTotal(){ return numberTotal; }
	int getNumberKilled(){ return numberKilled; }
	void incKill(){ numberKilled++; }
	////SDL_Rect getEndLocation(){ SDL_Rect dummy; dummy.x = -1; return dummy; }

};

class Quest_Escort : public Quest
{
private:
	////SDL_Rect endLocation;
public:
	//Quest_Escort(int Start_id, SDL_Rect endLoc, int XP);
	Quest_Escort(NPC* npc, sf::IntRect& r, int XP);
	////SDL_Rect getEndLocation(){ return endLocation; }

	//Stuff that Don't belong
	//kill shit quests
	//deliever quests
};

class Quest_Deliver : public Quest
{
private:
	Item* item;
public:
	Quest_Deliver();
	Item* getItem(){ return item; }
	void setItem(Item* i){ this->item = i; }


};

class Quest_GoTo_NPC : public Quest
{
private:
	NPC* targetNPC;
public:
	Quest_GoTo_NPC();
	NPC* getTargetNPC(){ return targetNPC; }
	void setTargetNPC(NPC* tar){ targetNPC = tar; }
};
class Quest_GoTo_Area : public Quest
{
private:
	sf::FloatRect targetArea;
public:
	Quest_GoTo_Area();
	sf::FloatRect& getTargetArea(){ return targetArea; }
	void setTargetArea(float X, float Y, int W, int H);
};
