#include "Warp.h"
#include "constants.h"
#include <iostream>
Warp::Warp(float X, float Y, int W, int H, float toX, float toY)
	: Entity(X, Y, W, H, "Warp", "test/warp.png"){
	//changeAlpha(255);
	warpToX = toX;
	warpToY = toY;
	bIsActive = false;
	playerWarped = false;
}

void Warp::activate(){
	transition.start();
	bIsActive = true;
}

void Warp::updateWarp(Player* p, sf::Sprite& s){
	
	static int _alpha = 0;
	s.setColor(sf::Color(0, 0, 0, 255));
	if (!playerWarped){
		_alpha = transition.get_ticks() / 10;
		s.setColor(sf::Color(0, 0, 0, _alpha));
		if (_alpha >= 255){
			_alpha = 255;		
			s.setColor(sf::Color(0, 0, 0, _alpha));
			p->setHardPosition(warpToX, warpToY);		
			playerWarped = true;
			transition.stop();
			transition.start();
		}
	}

	if (playerWarped){
		_alpha = -75 + (transition.get_ticks() / 10);
		if (_alpha > 0){
			s.setColor(sf::Color(0, 0, 0, 255 - _alpha));
			if (255 - _alpha <= 0){
				_alpha = 255;
				s.setColor(sf::Color(0, 0, 0, 255 - _alpha));
				transition.stop();
				playerWarped = false;
				bIsActive = false;
			}
		}

	}
	s.setPosition(p->getX() - SCREEN_WIDTH / 2, p->getY() - SCREEN_HEIGHT / 2);
	p->setXVel(0);
	p->setYVel(0);
	return;
	
}