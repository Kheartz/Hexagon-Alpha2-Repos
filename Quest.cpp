#include "quest.h"

Quest::Quest()
{
	
	bStarted = false;
	bSatisfied = false;
	bCompleted = false;
	bActive = true;
	startNPC = NULL;
}
//Quest_Kill_Enemies::Quest_Kill_Enemies(int Start_id, int End_id, int Enemy_id, int numberOf, int XP)
Quest_Kill_Enemies::Quest_Kill_Enemies(NPC* startNPC, NPC* endNPC, Enemy* enemy, int numberOf, int XP)
{
	startNPC = startNPC;
	targetEnemy = enemy;
	numberTotal = numberOf;
	numberKilled = 0;
	xpGive = XP;
	type = 1;
}

/*
Quest_Escort::Quest_Escort(int Start_id, SDL_Rect endLoc, int XP)
{
	////endLocation = endLoc;
	startTargetNPC = Start_id;
	xpGive = XP;
}
*/

Quest_Deliver::Quest_Deliver()
{
	questType = QUEST_TYPE::DELIVER;
}


Quest_GoTo_NPC::Quest_GoTo_NPC()
{
	questType = QUEST_TYPE::GOTONPC;
}
Quest_GoTo_Area::Quest_GoTo_Area()
{
	questType = QUEST_TYPE::GOTOAREA;
}

void Quest::start()
{
	bStarted = true; bActive = false;
	startNPC->setConversation(getActivecyConvo());
	questStartTimer.start();

}



void Quest_GoTo_Area::setTargetArea(float X, float Y, int W, int H){
	targetArea.left = X;
	targetArea.top = Y;
	targetArea.width = W;
	targetArea.height = H;
}

void Quest::Satisfy(){
	std::cout << "SATISFIED" << std::endl;
	bStarted = false;
	bSatisfied = true;
}
void Quest::complete(){ 
	bCompleted = true;
	endNPC->setConversation(getStartedcytConvo());
}
void Quest::update(){
	if (questStartTimer.isStarted() && questStartTimer.get_ticks() / 7000){
		if (!isSatisfied())
			startNPC->setConversation(getStartedConvo());
		questStartTimer.stop();
	}
}

void Quest::award(Player* p){
	std::string test;
	char* test2;
	
	for (unsigned int i = 0; i < itemsGive.size(); i++){
		test = "test/item/element/" + std::string(itemsGive[i]) + ".png";
		std::transform(test.begin(), test.end(), test.begin(), ::tolower);
		test2 = (char*)(test.c_str());
		p->addItem(new Item(0, 0, 32, 32, itemsGive[i], itemsGive[i], test2));
	}
}

bool Quest::preReqsCompleted()
{
	for (unsigned int i = 0; i < preReqQ.size(); i++)
		if (!preReqQ[i]->isCompleted())
			return false;
	return true;

}
void Quest::printConversations() const
{
	std::cout << activeConvo << std::endl;
	std::cout << activecyConvo << std::endl;
	std::cout << activecnConvo << std::endl;
	std::cout << startedConvo << std::endl;
	std::cout << startedcnConvo << std::endl;
	std::cout << startedcyfConvo << std::endl;
	std::cout << startedcytConvo << std::endl;
	std::cout << doneConvo << std::endl;
}
/*
Quest::Quest(char* Name, unsigned short int Q_ID, unsigned short int Diff)
{
isDone = false;
isOn = false;
name = Name;
questID = Q_ID;
difficulty = Diff;
startingNPC = NULL;
endingNPC = NULL;
}
Quest::~Quest()
{
startingNPC = NULL;
endingNPC = NULL;
name = "";
}
unsigned short int Quest::getQuest_ID()
{
return questID;
}
unsigned short int Quest::getDifficulty()
{
return difficulty;
}
void Quest::setStartingNPC(NPC* npc)
{
startingNPC = npc;
}
void Quest::setEndingNPC(NPC* npc)
{
endingNPC = npc;
}
NPC* Quest::getStartingNPC()
{
return startingNPC;
}
NPC* Quest::getEndingNPC()
{
return endingNPC;
}

/*



*/