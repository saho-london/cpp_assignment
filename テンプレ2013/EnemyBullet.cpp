#include "GameManager.h"
#include <algorithm>

EnemyBullet::EnemyBullet(double xx, double yy, double vx_, double vy_) :
x(xx),
y(yy),
vx(vx_),
vy(vy_)
{
	r = 8;
	eraseFlag = false;
}

double EnemyBullet::get_x() const { return x;}
double EnemyBullet::get_y() const { return y;}

void EnemyBullet::update(){
		x += vx;
		y += vy;
		if (off_screen(get_x(), get_y())){
			eraseFlag = true;
		}
		//自機に弾が当たったときeraseFlagをtrueに・シークエンス遷移
		if (hit_circle(GameManager::get().player.get_x(), GameManager::get().player.get_y(), 16, x, y, 16)
			&& GameManager::get().state == 0
			){
				GameManager::get().effectmanager.add_effect(x, y, 30, 100);
				GameManager::get().state = 1;
				eraseFlag = true;
		}
}

void EnemyBullet::draw() const {
	DrawCircle(x, y, r, GetColor(255, 255, 255), 1);
}


void EnemyBulletManager::update(){
	for (auto element : vec){
		element->update();
	}
	//eraseFlagがtrueの敵を消去
	auto removeiter = std::remove_if(vec.begin(), vec.end(), [](std::shared_ptr<EnemyBullet> i){return i->eraseFlag; });
	vec.erase(removeiter, vec.end());
}

void EnemyBulletManager::draw() const {
	for (auto element: vec){
		element->draw();
	}
}

void EnemyBulletManager::add_bullet(std::shared_ptr<EnemyBullet> ptr){
	vec.emplace_back(ptr);
}