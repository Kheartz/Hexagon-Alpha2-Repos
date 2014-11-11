#pragma once

#include "Entity.h"
#include "stdafx.h"

class GUI : public Entity{
private:

	bool bIsActive;
	bool bToggled;
	int maxWidth;
	int maxHeight;

public:
	GUI();
	GUI(float X, float Y, int W, int H, char* filename, int alpha, bool active);

	virtual bool isActive(){ return bIsActive; }
	virtual void toggleActive();
	virtual bool toggled(){ return bToggled; }
	virtual void toggleToggle();
	virtual void changeAlpha(int del);

	int getMaxWidth() { return maxWidth; }
	int getMaxHeight(){ return maxHeight; }

};