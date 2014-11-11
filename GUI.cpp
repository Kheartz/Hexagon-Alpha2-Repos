#include "GUI.h"

GUI::GUI(float X, float Y, int W, int H, char* filename, int alpha, bool active)
	: Entity(X, Y, W, H, "GUI", filename){
	changeAlpha(alpha);
	bIsActive = active;
	bToggled = false;
	maxHeight = H;
	maxWidth = W;
}
GUI::GUI()
	: Entity(0, 0, 0, 0, "GUI", ""){
	bIsActive = false;
	bToggled = true;
	maxHeight = 0;
	maxWidth = 0; 
}

void GUI::toggleActive(){
	if (bIsActive)
		bIsActive = false;
	else if(!bIsActive)
		bIsActive= true;
}

void GUI::toggleToggle(){
	if (bToggled)
		bToggled = false;
	else if (!bToggled)
		bToggled = true;
}

void GUI::changeAlpha(int alpha){
	_sprite.setColor(sf::Color(255, 255, 255, alpha));
}

