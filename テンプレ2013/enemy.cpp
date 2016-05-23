#include "GameManager.h"
#include <algorithm>
#include <memory>



Enemy_Pink::Enemy_Pink(double xx, double yy) :
x(xx),
y(yy),
HP(5),
eraseFlag(false),
angle(atan2(GameManager::get().player.get_y() - y, GameManager::get().player.get_x() - x)),
movev(1),
r(32)
{
}

Enemy_Blue::Enemy_Blue(double xx, double yy) :
x(xx),
y(yy),
HP(5),
eraseFlag(false),
enemyFrame(0),
r(32),
shotRate(50),
bulletSpeed(1)
{
}

Enemy_Yellow::Enemy_Yellow(double xx, double yy) :
x(xx),
y(yy),
HP(5),
eraseFlag(false),
enemyFrame(0),
r(32),
shotRate(100),
movev(1),
bulletSpeed(8)
{
}


//Pink‚ÌÀ‘•
double Enemy_Pink::get_x() const { return x; }
double Enemy_Pink::get_y() const { return y; }
int    Enemy_Pink::get_HP() const { return HP; }
double Enemy_Pink::get_r() const { return r; }
bool   Enemy_Pink::is_dead() const{ return eraseFlag; }
void Enemy_Pink::reduce_HP() { HP -= 1; }
void Enemy_Pink::set_flag() { eraseFlag = true; }

void Enemy_Pink::add_bullet(int xx, int yy){
}

//©‹@‚ÉŒü‚©‚¤
void Enemy_Pink::update(){
	x += movev * cos(angle);
	y += movev * sin(angle);
	if (off_screen(x, y)){
		eraseFlag = true;
	}
	if (hit_circle(GameManager::get().player.get_x(), GameManager::get().player.get_y(), GameManager::get().player.r, x, y, r) && GameManager::get().state == 0){
		GameManager::get().state = 1;
		GameManager::get().effectmanager.add_effect(x, y, 30, 100);
	}
}

void Enemy_Pink::draw() const {
	DrawCircle(x, y, r, GetColor(255, 150, 200), 1);
}

std::shared_ptr<EnemyBullet> Enemy_Pink::make_enemy_bullet(double x, double y, double vx, double vy) const {
	return std::make_shared<EnemyBullet>(x, y, vx, vy);
}



//Blue‚ÌÀ‘•
double Enemy_Blue::get_x() const { return x; }
double Enemy_Blue::get_y() const { return y; }
int    Enemy_Blue::get_HP() const { return HP; }
double Enemy_Blue::get_r() const { return r; }
bool   Enemy_Blue::is_dead() const{ return eraseFlag; }
void   Enemy_Blue::reduce_HP() { HP -= 1; }
void   Enemy_Blue::set_flag() { eraseFlag = true; }

void Enemy_Blue::add_bullet(int xx, int yy){
	double angle = atan2(GameManager::get().player.get_y() - yy, GameManager::get().player.get_x() - xx);
	GameManager::get().enemybulletmanager.add_bullet(make_enemy_bullet(xx, yy, bulletSpeed*cos(angle), bulletSpeed*sin(angle)));
}

//Ã~E©‹@‚ÉŒü‚©‚Á‚ÄŒ‚‚Â
void Enemy_Blue::update(){
	enemyFrame++;
	x += 0;
	y += 0;
	if (off_screen(x, y)){
		eraseFlag = true;
	}
	if (enemyFrame % shotRate == 0){
		add_bullet(x, y);
	}
}

void Enemy_Blue::draw() const {
	DrawCircle(x, y, r, GetColor(130, 170, 255), 1);
}

std::shared_ptr<EnemyBullet> Enemy_Blue::make_enemy_bullet(double x, double y, double vx, double vy) const {
	return std::make_shared<EnemyBullet>(x, y, vx, vy);
}



//Yellow‚ÌÀ‘•
double Enemy_Yellow::get_x() const { return x; }
double Enemy_Yellow::get_y() const { return y; }
int    Enemy_Yellow::get_HP() const { return HP; }
double Enemy_Yellow::get_r() const { return r; }
bool   Enemy_Yellow::is_dead() const{ return eraseFlag; }
void   Enemy_Yellow::reduce_HP() { HP -= 1; }
void   Enemy_Yellow::set_flag() { eraseFlag = true; }

//l•û‚ÉŒ‚‚Â
void Enemy_Yellow::add_bullet(int xx, int yy){
	GameManager::get().enemybulletmanager.add_bullet(make_enemy_bullet(xx, yy, 0, -bulletSpeed));
	GameManager::get().enemybulletmanager.add_bullet(make_enemy_bullet(xx, yy, bulletSpeed, 0));
	GameManager::get().enemybulletmanager.add_bullet(make_enemy_bullet(xx, yy, 0, bulletSpeed));
	GameManager::get().enemybulletmanager.add_bullet(make_enemy_bullet(xx, yy, -bulletSpeed, 0));
}

//‰~‰^“®El•û‚ÉŒ‚‚Â
void Enemy_Yellow::update(){
	enemyFrame++;
	x += movev * cos(enemyFrame * 0.02);
	y += movev * sin(enemyFrame * 0.02);
	if (off_screen(x, y)){
		eraseFlag = true;
	}
	if (enemyFrame % shotRate == 1){
		add_bullet(x, y);
	}
}

void Enemy_Yellow::draw()const {
	DrawCircle(x, y, r, GetColor(255, 255, 130), 1);
}

std::shared_ptr<EnemyBullet> Enemy_Yellow::make_enemy_bullet(double x, double y, double vx, double vy) const {
	return std::make_shared<EnemyBullet>(x, y, vx, vy);
}



void EnemyManager::update(){
	for (auto element : vec){
		element->update();
	}
	//eraseFrag‚ªtrue‚Ì“G‚ğÁ‹
	auto removeIter = std::remove_if(vec.begin(), vec.end(), [](std::shared_ptr<I_Enemy> i){return i->is_dead(); });
	vec.erase(removeIter, vec.end());
}

void EnemyManager::draw() const {
	for (auto element : vec){
		element->draw();
	}
}


std::shared_ptr<I_Enemy> EnemyManager::make_enemy_pink(double x, double y){
	return std::make_shared<Enemy_Pink>(x, y);
}

std::shared_ptr<I_Enemy> EnemyManager::make_enemy_blue(double x, double y){
	return std::make_shared<Enemy_Blue>(x, y);
}

std::shared_ptr<I_Enemy> EnemyManager::make_enemy_yellow(double x, double y){
	return std::make_shared<Enemy_Yellow>(x, y);
}

void EnemyManager::add_enemy(std::shared_ptr<I_Enemy> ptr){
	vec.emplace_back(ptr);
}