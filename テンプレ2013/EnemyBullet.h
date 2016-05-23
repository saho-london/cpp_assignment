#pragma once
#include "GameManager.h"
#include <vector>



class EnemyBullet{
	double x, y;
public:
	double vx, vy;
	double r;
	bool eraseFlag;

	EnemyBullet(double xx, double yy, double vx_, double vy_);

	double get_x() const;
	double get_y() const;

	void update();

	void draw() const;
};


class EnemyBulletManager{
public:
	std::vector<std::shared_ptr<EnemyBullet>> vec;

	void update();

	void draw() const;

	void add_bullet(std::shared_ptr<EnemyBullet> ptr);
};