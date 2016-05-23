#include "GameManager.h"

Player::Player() :
shotRate(5)
{
	x = 400;
	y = 500;
	movev = 3;
	r = 16;
}

double Player::get_x() const { return x; }
double Player::get_y() const { return y; }

//è„â∫ç∂âEÇ…à⁄ìÆ
void Player::update(){
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1){
		x += movev;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) == 1){
		x -= movev;
	}
	if (CheckHitKey(KEY_INPUT_UP) == 1){
		y -= movev;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1){
		y += movev;
	}
	if (input::get().keystate[KEY_INPUT_Z] % shotRate == 1){
		add_bullet(GameManager::get().player.get_x(), GameManager::get().player.get_y());
	}
}

void Player::draw() const {
	DrawCircle(x, y, r, GetColor(255, 120, 60), 1);
}

void Player::add_bullet(int xx, int yy){
	GameManager::get().playerbulletmanager.vec.emplace_back(std::make_shared<PlayerBullet>(xx, yy));
}