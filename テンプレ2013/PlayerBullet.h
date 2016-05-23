#pragma once
#include "GameManager.h"
#include <vector>



class PlayerBullet{
	double x, y;
	double vx, vy;
	double r;
	bool eraseFlag;
public:
	PlayerBullet(double xx, double yy);

	double get_x() const;
	double get_y() const;
	double get_r() const;

	bool is_dead();

	void update();

	void draw() const;
};


class PlayerBulletManager{
public:
	std::vector<std::shared_ptr<PlayerBullet>> vec;

	void update();
	void draw() const;
};