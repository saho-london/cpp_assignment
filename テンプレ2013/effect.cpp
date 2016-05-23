#include "GameManager.h"
#include <DxLib.h>
#include <algorithm>

Effect::Effect(double xx, double yy) :
x(xx),
y(yy),
frame(0)
{

}

double Effect::get_x()     const { return x; }
double Effect::get_y()     const { return y; }
int    Effect::getframe()  const { return frame; }

void Effect::update(){
	frame++;
}

void Effect::draw() const {
	    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 63);
		DrawCircle(x, y, 64, GetColor(255, 255, 255), 1);
}


void EffectManager::update(){
	for (auto element :vec){
		element->update();
	}
	//•\¦‚µ‚Ä‚©‚çˆê’èŠÔ‚ªŒo‰ß‚µ‚½‚çÁ‹
	auto removeIter = std::remove_if(vec.begin(), vec.end(), [](std::shared_ptr<Effect> i){return i->getframe() >= 5; });
	vec.erase(removeIter, vec.end());
}

void EffectManager::draw() const {
	for (auto element : vec){
		element->draw();
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
}

void EffectManager::add_effect(double x, double y, int volume, double size){
	for (int i = 0; i < volume; i++){
		vec.emplace_back(std::make_shared<Effect>(x + GetRand(2*size) - size, y + GetRand(2*size) - size));
	}
}