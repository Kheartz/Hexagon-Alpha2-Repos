#pragma once

#include "Player.h"
#include "Timer.h"

class Warp : public Entity {
private:
	float warpToX;
	float warpToY;
	Timer transition;
	bool bIsActive;
	bool playerWarped;

public:
	Warp(float X, float Y, int W, int H, float toX, float toY);

	float getToX(){ return warpToX; }
	float getToY(){ return warpToY; }
	bool isActive(){ return bIsActive; }
	void updateWarp(Player* P, sf::Sprite& s);
	void activate();

};