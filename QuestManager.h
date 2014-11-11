#pragma once

#include "Quest.h"
#include "tolua.h"
#include "stdafx.h"


class QuestManager 
{
private:
	int numQuestActive;
	std::ifstream file;
	char* phrase;
	std::vector<Quest*> questList;
public:

	QuestManager();
	~QuestManager();

	std::vector<Quest*>& getQuestList(){ return questList; }
	
	void addQuest(Quest* q);
	void addQuest();
	void deleteQuest(char* q);
	void setConvo(Quest* q, char* name);
	void Update();

	static QuestManager* getInstance();
};


static QuestManager qm;