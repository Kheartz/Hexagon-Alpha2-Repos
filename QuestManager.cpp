#include "QuestManager.h"

static QuestManager* QM;

QuestManager::QuestManager()
{

	/*
	QUESTLIST["Where's my book?"] = new Quest_Deliver(Bunny_NPC, eBook, Bunny_NPC, 25);
	QUESTLIST["Where's my book?"]->setName("Where's my book?");
	QUESTLIST["Where's my book?"]->addItemGive(ePotion);
	setConvo(QUESTLIST["Where's my book?"], QUESTLIST["Where's my book?"]->getName());
	QUESTLIST["Where's my book?"]->activate();

	QUESTLIST["Carbon where art thou?"] = new Quest_Deliver(Mario_NPC, eCarbon, Mario_NPC, 50);
	QUESTLIST["Carbon where art thou?"]->setName("Carbon where art thou?");
	QUESTLIST["Carbon where art thou?"]->addItemGive(eCarbon);
	QUESTLIST["Carbon where art thou?"]->addPreReqQ(QUESTLIST["Where's my book?"]);
	setConvo(QUESTLIST["Carbon where art thou?"], QUESTLIST["Carbon where art thou?"]->getName());
	QUESTLIST["See the alchemist!"] = new Quest_Deliver(Mario_NPC, eCarbon, Baurn_NPC, 60);
	QUESTLIST["See the alchemist!"]->setName("See the alchemist!");
	QUESTLIST["See the alchemist!"]->addItemGive(eCarbon);
	QUESTLIST["See the alchemist!"]->addPreReqQ(QUESTLIST["Carbon where art thou?"]);
	setConvo(QUESTLIST["See the alchemist!"], QUESTLIST["See the alchemist!"]->getName());
	QUESTLIST["Beware of witches!"] = new Quest_Kill_Enemies(Baurn_NPC, Baurn_NPC, Coa_NPC, 1, 230);
	//QUESTLIST["Beware of witches!"] = new Quest_Deliver(Baurn_NPC,eCarbon,Baurn_NPC, 60);
	QUESTLIST["Beware of witches!"]->setName("Beware of witches!");
	QUESTLIST["Beware of witches!"]->addItemGive(eChlorine);
	QUESTLIST["Beware of witches!"]->addPreReqQ(QUESTLIST["See the alchemist!"]);
	setConvo(QUESTLIST["Beware of witches!"], QUESTLIST["Beware of witches!"]->getName());
	*/

}
QuestManager::~QuestManager()
{
	for (auto it = questList.begin(); it != questList.end(); it++)
		delete (*it);
}
QuestManager* QuestManager::getInstance()
{
	if (!QM)
	{
		QM = new QuestManager();
	}
	return QM;
}
void QuestManager::deleteQuest(char* q)
{
}

void QuestManager::addQuest(Quest* q)
{
	questList.push_back(q);
}

void QuestManager::addQuest(){

}
void QuestManager::setConvo(Quest* q, char* name)
{
	/*string filename = "test/Conversations/Quests/" + name.substr(0, name.length() - 1) + ".txt";
	file.open(filename.c_str());
	file.clear();
	while (getline(file, phrase))
	{
		if (phrase.substr(0, 7) == "ACTIVE:")
			q->setActiveConvo(phrase.substr(7));
		else if (phrase.substr(0, 9) == "ACTIVECY:")
			q->setActivecyConvo(phrase.substr(9));
		else if (phrase.substr(0, 9) == "ACTIVECN:")
			q->setActivecnConvo(phrase.substr(9));
		else if (phrase.substr(0, 8) == "STARTED:")
			q->setStartedConvo(phrase.substr(8));
		else if (phrase.substr(0, 10) == "STARTEDCN:")
			q->setStartedcnConvo(phrase.substr(10));
		else if (phrase.substr(0, 11) == "STARTEDCYF:")
			q->setStartedcyfConvo(phrase.substr(11));
		else if (phrase.substr(0, 11) == "STARTEDCYT:")
			q->setStartedcytConvo(phrase.substr(11));
		else if (phrase.substr(0, 5) == "DONE:")
			q->setDoneConvo(phrase.substr(5));
	}
	file.close();
	//q->printConversations();
	*/
}


void QuestManager::Update()
{
	std::cout << "QM WORKS IN LUA!!!" << std::endl;
}