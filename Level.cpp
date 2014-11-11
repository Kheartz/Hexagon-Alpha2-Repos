#include "Level.h"
#include <iostream>


Level::Level(sf::RenderWindow* rw)
	: maploaderr("test/level/"), gui(*rw) {
	
	_blackTexture.loadFromFile("test/misc/black.png");
	_blackSprite.setTexture(_blackTexture);
	_blackSprite.setColor(sf::Color(255, 255, 255, 0));
	player = NULL;
	this->rw = rw;
	levelView = sf::View(sf::FloatRect(0.0, 0.0, SCREEN_WIDTH, SCREEN_HEIGHT));
	//this->rw->setView(levelView);
	inv = new GUI(levelView.getCenter().x / levelView.getCenter().x, levelView.getCenter().y / levelView.getCenter().y, 320, 576, "test/misc/inventory bg2.png", 120, false);

	playerBar.push_back(new GUI(0, 0, 1024, 64, "test/GUI/bar.png", 255, true));
	playerBar.push_back(new GUI(0, 0, 416, 32, "test/GUI/redHPBar.png", 255, true));
	playerBar.push_back(new GUI(0, 0, 416, 32, "test/GUI/greenHPBar.png", 255, true));
	playerBar.push_back(new GUI(0, 0, 416, 32, "test/GUI/lblueManaBar.png", 255, true));
	playerBar.push_back(new GUI(0, 0, 416, 32, "test/GUI/dblueManaBar.png", 255, true));

	maploaderr.AddSearchPath("test/sheet/");
	maploaderr.Load("testLevel.tmx");

	gui.setGlobalFont("test/font/arial.ttf");

	chat = tgui::TextBox::Ptr(gui, "PictureWindow");
	chat->setSize(600, 50);
	chat->setBackgroundColor(sf::Color(255,255,255,255/2));
	chat->setPosition(0, 0);
	
	promptBox = tgui::ListBox::Ptr(gui, "Quest Prompt");
	promptBox->setBorders(3, 3, 3, 3);
	promptBox->setBackgroundColor(sf::Color(0,0,0,255/2));
	promptBox->setBorderColor(sf::Color(255, 215, 0));
	promptBox->setCallbackId(1);
	promptBox->setTextColor(sf::Color(255,255,255, 255));
	promptBox->addItem("Yes");
	promptBox->addItem("No");
	promptBox->setSize(55, 48);
	promptBox->setPosition(SCREEN_WIDTH/2 + 32, SCREEN_HEIGHT/2);
	promptBox->hide();
	
	datgriddoe = tgui::Grid::Ptr(gui, "DatGridDoe");
	datgriddoe->setPosition(100, 100);
	datgriddoe->setSize(100, 100);
	
	for (auto layer : maploaderr.GetLayers()){
		if (layer.name == "AREA"){
			for (auto objects : layer.objects){
				areas.push_back(new Area(objects.GetAABB()));
			}
		}

		if (layer.name == "WARP"){
			for (auto objects : layer.objects){
				addWarp(EntityManager::getInstance(), new Warp(objects.GetPosition().x, objects.GetPosition().y, 32, 32, (float)atoi(objects.GetPropertyString("WarpToX").c_str()), (float)atoi(objects.GetPropertyString("WarpToY").c_str())));
			}
		}
		
		if (layer.name == "NPC"){
			for (auto objects : layer.objects){
				addNPC(EntityManager::getInstance(), new NPC(objects.GetPosition().x, objects.GetPosition().y, objects.GetAABB().width, objects.GetAABB().height, (char*)objects.GetName().c_str(), 1, 1, (char*)objects.GetPropertyString("spritefile").c_str()));
			}
		}
		
		if (layer.name == "ENEMY"){
			for (auto objects : layer.objects){
				addEnemy(EntityManager::getInstance(), new Enemy(objects.GetPosition().x, objects.GetPosition().y, objects.GetAABB().width, objects.GetAABB().height, (char*)(objects.GetName().c_str()), atoi(objects.GetPropertyString("HP").c_str()), atoi(objects.GetPropertyString("MP").c_str()), (char*)objects.GetPropertyString("spritefile").c_str()));
			}
		}

		if (layer.name == "RIGID"){
			for (auto objects : layer.objects){
				rigids.push_back(new sf::FloatRect(objects.GetAABB().left, objects.GetAABB().top, objects.GetAABB().width, objects.GetAABB().height));
			}
		}

		if (layer.name == "CRAFTTABLE"){
			for (auto objects : layer.objects){
				craftTables.push_back(new CraftTable(objects.GetAABB(), ""));
			}
		}
		
	}

	overlay.top = 0;
	overlay.left = 0;
	overlay.height = SCREEN_HEIGHT;
	overlay.width = SCREEN_WIDTH;
}

Area::Area(sf::FloatRect rect){
	this->rect = rect;
}
Level::~Level()
{
	delete inv;
}

void Level::initialize()
{
	addItem(EntityManager::getInstance(), new Item(60, 60, 32, 32, "Potion", "Increases your Health by 100.", "test/item/gPotion.png"));
	addItem(EntityManager::getInstance(), new Item(420, -500, 32, 32, "Carbon", "Atomic no. 6", "test/item/element/carbon.png"));
	
}

void Level::addItem(EntityManager* em, Item* i){

	i->setPublic(true);
	em->Add(i);
	items.push_back(i);
	return;
}

void Level::addWarp(EntityManager* em, Warp* w){
	em->Add(w);
	warps.push_back(w);
}

void Level::removeItem(Item* i){
	for (auto it = items.begin(); it != items.end(); it++){
		if (*it == i){
			items.erase(it);
			return;
		}
	}
}

void Level::addNPC(EntityManager* em, NPC* n){
	em->Add(n);
	npcs.push_back(n);

}

void Level::addEnemy(EntityManager* em, Enemy* e){
	em->Add(e);
	enemies.push_back(e);
}
void Level::removeEntity(EntityManager* em, int index){
	em->Remove(index);
}

void Level::update(){

	for (auto warp : warps){
		if (warp->isActive())
			warp->updateWarp(player, this->getBlackSprite());
	}

	player->move(player->getXVel(), player->getYVel());
	levelView.setCenter(player->getX(), player->getY());
	overlay.left = levelView.getCenter().x - SCREEN_WIDTH / 2;
	overlay.top = levelView.getCenter().y - SCREEN_HEIGHT / 2;
	for (auto npc : npcs){
		npc->update();
		npc->moveAI();
		npc->getConversation().setPosition(npc->getX() +npc->getW(),npc->getY() + npc->getH());
	}

	for (auto enemy : enemies){
		enemy->update();
		enemy->moveAI();
	}

	
	for (auto quest : QuestManager::getInstance()->getQuestList()){
		
		if (quest->getQuestType() == Quest::QUEST_TYPE::GOTOAREA && quest->isStarted() && !quest->isSatisfied()){
			if (checkCollisionBodies(&player->getSprite(), &((Quest_GoTo_Area*)quest)->getTargetArea())){
				quest->Satisfy();
			}
		}
		quest->update();
	}
		
	inv->setHardPosition(overlay.left + 600, overlay.top  + 200);
	playerBar[0]->setHardPosition(overlay.left, overlay.top + SCREEN_HEIGHT - playerBar[0]->getH());
	playerBar[1]->setHardPosition(overlay.left + 10, overlay.top + 30 + SCREEN_HEIGHT - playerBar[0]->getH());
	playerBar[2]->setHardPosition(overlay.left + 10, overlay.top + 30 + SCREEN_HEIGHT - playerBar[0]->getH()); //Green HP Bar
	playerBar[2]->getSprite().setTextureRect(sf::IntRect(0, 0, playerBar[2]->getMaxWidth()*player->getHP() / player->getMaxHP(), 32));
	playerBar[3]->setHardPosition(overlay.left + 600, overlay.top + 30 + SCREEN_HEIGHT - playerBar[0]->getH());
	playerBar[4]->getSprite().setTextureRect(sf::IntRect(playerBar[4]->getMaxWidth()*(1 - ((float)player->getMP() / (float)player->getMaxMP())), 0, 416, 32));
	playerBar[4]->setHardPosition(overlay.left + 600 + playerBar[4]->getMaxWidth()*(1 - ((float)player->getMP() / (float)player->getMaxMP())), overlay.top + 30 + SCREEN_HEIGHT - playerBar[0]->getH());
	
	for (int i = 0; i < player->getInvSize(); i++){
		player->getInv()[i]->setHardPosition(inv->getX() + ((i*player->getInv()[i]->getW() * 2) % 320), //1 cell of inventory should be taken up by 1 32x32
			inv->getY() + i*(player->getInv()[i]->getH() * 2) / 320 * player->getInv()[i]->getH() * 2); //clean later
		player->getInv()[i]->getNumberofText().setString(std::to_string(player->getInv()[i]->getNumberOf()));
		player->getInv()[i]->getNumberofText().setPosition(player->getInv()[i]->getX() + 32, player->getInv()[i]->getY() + 32);
	}
	
	player->setXVel(0);
	player->setYVel(0);
		
	if (player->getTargetNPC() != NULL){
		player->getTargetNPC()->getPortraitSprite().setPosition(levelView.getCenter().x + (SCREEN_WIDTH / 2) - player->getTargetNPC()->getPortraitSprite().getTextureRect().width,
			levelView.getCenter().y - (SCREEN_HEIGHT / 2));
	}
	this->rw->setView(levelView);
	
}
void Level::pollInput(sf::Event& event){
	int INDEX = 0;
	int mouse_gx = sf::Mouse::getPosition().x;
	int mouse_gy = sf::Mouse::getPosition().y;
	int mouse_x = -(rw->getPosition().x - sf::Mouse::getPosition().x + 8) + (levelView.getCenter().x - SCREEN_WIDTH / 2 ); 
	int mouse_y = -(rw->getPosition().y - sf::Mouse::getPosition().y + 30) + (levelView.getCenter().y - SCREEN_HEIGHT / 2);

	gui.handleEvent(event); 

	if (event.type == sf::Event::MouseButtonPressed){
		if (event.mouseButton.button == sf::Mouse::Right){
			if (inv->isActive()){
					INDEX = (int)((((mouse_gx + levelView.getCenter().x - SCREEN_WIDTH / 2 + 144) - (levelView.getCenter().x - SCREEN_WIDTH / 2 + 600)) - 600) / 64)
					+ 5 * (int)((((mouse_gy + levelView.getCenter().y - SCREEN_HEIGHT / 2 - 170) - (levelView.getCenter().y - SCREEN_HEIGHT / 2 + 200)) / 64));
				if (player->getInv()[INDEX] != NULL){
					player->useItem(L, player->getInv()[INDEX]);
				}
			}
		}
		if (event.mouseButton.button == sf::Mouse::Left){
			if (inv->isActive()){
				INDEX = (int)((((mouse_gx + levelView.getCenter().x - SCREEN_WIDTH / 2 + 144) - (levelView.getCenter().x - SCREEN_WIDTH / 2 + 600)) - 600) / 64)
					+ 5 * (int)((((mouse_gy + levelView.getCenter().y - SCREEN_HEIGHT / 2 - 170) - (levelView.getCenter().y - SCREEN_HEIGHT / 2 + 200)) / 64));
				if (player->getInv()[INDEX] != NULL){
				}
			}
		}
		std::cout << mouse_x << " " << mouse_y << std::endl;
		if (event.mouseButton.button == sf::Mouse::Left){
			player->setTargetNPC(NULL);
			for (auto it = npcs.begin(); it != npcs.end(); it++){
				if (mouse_x > (*it)->getX() && mouse_x < (*it)->getX() + (*it)->getW() &&
					mouse_y >(*it)->getY() && mouse_y < (*it)->getY() + (*it)->getH()){
					player->setTargetNPC((*it));
					std::cout << "Target is now: " << (*it)->getName() << std::endl;
				}
			}
			for (auto it = enemies.begin(); it != enemies.end(); it++){
				if (mouse_x >(*it)->getX() && mouse_x < (*it)->getX() + (*it)->getW() &&
					mouse_y >(*it)->getY() && mouse_y < (*it)->getY() + (*it)->getH()){
					player->setTargetNPC((*it));
					std::cout << "Target is now: " << (*it)->getName() << std::endl;
				}
			}
		}
		
	}
	if (event.type == sf::Event::KeyPressed){
		if (event.key.code == sf::Keyboard::Return){
			tgui::TextBox::Ptr box = gui.get("PictureWindow");
			std::cout << box->getText().toAnsiString().c_str() << std::endl;
			luaL_dostring(L, box->getText().toAnsiString().c_str());
		}
	}
}
void Level::input()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && !inv->toggled()){
		inv->toggleToggle();
		inv->toggleActive();
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::I) && inv->toggled()){
		inv->toggleToggle();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		player->setDir(Character::FACING_DIRECTION::LEFT);
		player->incXVel(-player->getMyMaxVel());
		player->xFrame--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		player->setDir(Character::FACING_DIRECTION::RIGHT);
		player->incXVel(player->getMyMaxVel());
		player->xFrame++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		player->setDir(Character::FACING_DIRECTION::UP);
		player->incYVel(-player->getMyMaxVel());
		player->yFrame++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		player->setDir(Character::FACING_DIRECTION::DOWN);
		player->incYVel(player->getMyMaxVel());
		player->yFrame++;
	}
	
	
	
}

void Level::checkCollision()
{
	
	//Check Level against Enemies
	for (auto enemy : enemies){
		if (!encapsulatedByArea(enemy)){
			enemy->setXVel(0);
			enemy->setYVel(0);
		}
	}
	//Check Level against NPCs
	for (auto npc : npcs){
		if (!encapsulatedByArea(npc)){
			npc->setXVel(0);
			npc->setYVel(0);
		}
	}
	
	if (!encapsulatedByArea(player)){
		player->setXVel(0);
		player->setYVel(0);
	}

	for (auto rigid : rigids){
		separateBodies(player, rigid);
		for (auto enemy : enemies){
			separateBodies(enemy, rigid);
		}
		for (auto npc : npcs){
			separateBodies(npc, rigid);
		}
	}
	if (promptBox->isVisible()){
		promptBox->hide();
	}

	for (auto npc : npcs){
		if (checkCollisionBodies(player, npc)){
			npc->freeze();
			rw->draw(npc->getConversation());

			//Allow for input for questshit
			for (auto quest : QuestManager::getInstance()->getQuestList()){
				//Check all for Start NPCs
				if (quest->getStartNPC() == npc &&
					quest->isActive() &&
					!quest->isSatisfied()){
					promptBox->show();
					//promptBox->setPosition(0, 0);

					if (promptBox->getSelectedItem().toAnsiString().c_str() == promptBox->getItem(promptBox->getItemIndex("Yes"))){
						quest->start();
						promptBox->setSelectedItem(-1);
					}

				}

				//Check for satisfication
				if (quest->getQuestType() == Quest::QUEST_TYPE::GOTONPC){
					if (((Quest_GoTo_NPC*)quest)->getTargetNPC() == npc &&
						quest->isStarted()){
						((Quest_GoTo_NPC*)quest)->getTargetNPC()->setConversation("GTFO NERD");
						quest->Satisfy();
					}
				}
				//Check for end
				if (((Quest_GoTo_NPC*)quest)->getStartNPC() == npc &&
					quest->isSatisfied() &&
					!quest->isCompleted()){
					promptBox->show();
					if (promptBox->getSelectedItem().toAnsiString().c_str() == promptBox->getItem(promptBox->getItemIndex("Yes"))){
						if (quest->isSatisfied()){
							promptBox->setSelectedItem(-1);
							quest->complete();
							quest->award(player);
						}
					}
				}
			}
		}

		else{
			npc->unfreeze();
		}
	}
	
	//Check Items against player
	for (auto item : items){
		if (checkCollisionBodies(player, (Entity*)item) && !player->isInvFull()){
			std::cout << item->getName() << std::endl;
			for (auto quest : QuestManager::getInstance()->getInstance()->getQuestList()){
				if (((Quest_Deliver*)quest)->getItem() == item){
					quest->Satisfy();
				}
			}
			player->addItem(item);
			removeItem(item);
			break;
		}
	}
	//Check Warps against player
	for (auto warp : warps){
		if (checkCollisionBodies(player, (Warp*)(warp)) && !(warp)->isActive()){
			(warp)->activate();
		}
	}

	
	
}

bool Level::checkCollisionBodies(Entity* c, Entity* d){
	if ((c->getX() + c->getW() > d->getX() &&
		c->getY() < d->getY() + d->getH()) &&
		(d->getX() + d->getW() > c->getX() &&
		d->getY() < c->getY() + c->getH()))
	{
		return true;
	}
	return false;
}

void Level::separateBodies(Character* c, sf::FloatRect* b){
	int newX = c->getX() + c->getXVel();
	int newY = c->getY() + c->getYVel();

	if (newX + c->getW() > b->left &&
		newY < b->top + b->height &&
		b->left + b->width > newX &&
		b->top < newY + c->getH()){
		c->setXVel(0);
		c->setYVel(0);
	}
}

bool Level::checkCollisionBodies(sf::Sprite* a, sf::FloatRect* b){

	if (a->getPosition().x + a->getTextureRect().width > b->left &&
		a->getPosition().y < b->top + b->height &&
		b->left + b->width > a->getPosition().x &&
		b->top < a->getPosition().y + a->getTextureRect().height){
		return true;
	}
	
	return false;
}

bool Level::encapsulatedByArea(Character* c)
{
	for (auto area : areas){
		if (c->getX() + c->getXVel() >= area->getBounds().left &&
			c->getX() + c->getXVel() + c->getW() <= area->getBounds().left + area->getBounds().width &&
			c->getY() + c->getYVel() >= area->getBounds().top &&
			c->getY() + c->getYVel() + c->getH() <= area->getBounds().top + area->getBounds().height){
			return true;
		}
	}
	return false;
}

void Level::draw(){
	rw->clear();
	rw->draw(maploaderr);

	for (auto npc : npcs){
		rw->draw(npc->getSprite());
		if (checkCollisionBodies(player, npc))
			rw->draw(npc->getConversation());
	}

	for (auto enemy : enemies){
		rw->draw(enemy->getSprite());
		rw->draw(enemy->getHPBar()->getSprite());
		rw->draw(enemy->getMPBar()->getSprite());
	}

	for (auto item : items){
		rw->draw(item->getSprite());
	}

	rw->draw(player->getSprite());

	if (inv->isActive()){
		rw->draw(inv->getSprite());
		for (auto i = 0; i < player->getInvSize(); i++){
			rw->draw(player->getInv()[i]->getSprite());
			rw->draw(player->getInv()[i]->getNumberofText());
		}
	}

	for (auto bar: playerBar)
		if (bar->isActive())
			rw->draw(bar->getSprite());

	if (player->getTargetNPC() != NULL){
		rw->draw(player->getTargetNPC()->getPortraitSprite());
	}
	gui.draw();
	rw->draw(_blackSprite);
	rw->display();
}



