#pragma once
#include "GameManager.h"
#include <DxLib.h>



class Player{
	double x, y;

public:
	double movev;
	double r;
	const int shotRate;

	Player();

	double get_x() const;
	double get_y() const;

	void update();

	void draw() const;

	void add_bullet(int xx, int yy);
};