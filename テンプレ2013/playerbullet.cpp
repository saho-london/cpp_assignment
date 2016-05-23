#include "GameManager.h"
#include <algorithm>

PlayerBullet::PlayerBullet(double xx, double yy) :
x(xx),
y(yy),
vx(0),
vy(-20)
{
	r = 5;
	eraseFlag = false;
}

double PlayerBullet::get_x() const { return x; }
double PlayerBullet::get_y() const { return y; }
double PlayerBullet::get_r() const { return r; }

bool PlayerBullet::is_dead() { return eraseFlag; }

void PlayerBullet::update(){
	x += vx;
	y += vy;
	if (off_screen(get_x(), get_y())){
		eraseFlag = true;
	}
	//’e‚ª“G‚É“–‚½‚Á‚½‚Æ‚«’e‚ÌeraseFlag‚ğtrue‚ÉA“G‚ÌHP‚ğ-1
	for (auto element : GameManager::get().enemymanager.vec){
		if (hit_circle(element->get_x(), element->get_y(), element->get_r(), get_x(), get_y(), get_r())){
			element->reduce_HP();
			eraseFlag = true;
			GameManager::get().effectmanager.add_effect(x, y, 3, 30);
			if (element->get_HP() == 0){
				element->set_flag();
				GameManager::get().effectmanager.add_effect(x, y, 10, 50);
				GameManager::get().score.add_score(100);
			}
		}
	}
}

void PlayerBullet::draw() const {
	DrawCircle(x, y, r, GetColor(200, 200, 200), 1);
}

void PlayerBulletManager::update(){
	for (auto element : vec){
		element->update();
	}
	//eraseFlag‚ªtrue‚Ì’e‚ğÁ‹
	auto removeiter = std::remove_if(vec.begin(), vec.end(), [](std::shared_ptr<PlayerBullet> i){return i->is_dead(); });
	vec.erase(removeiter, vec.end());
}

void PlayerBulletManager::draw() const {
	for (auto element : vec){
		element->draw();
	}
}
