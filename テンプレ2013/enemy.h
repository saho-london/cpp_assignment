#pragma once
#include <vector>
#include <DxLib.h>
#include "GameManager.h"
#include <memory>
#include "EnemyBullet.h"


//Šî’êƒNƒ‰ƒX
class I_Enemy{
public:

	virtual double get_x() const = 0;
	virtual double get_y() const = 0;
	virtual int    get_HP() const = 0;
	virtual double get_r() const = 0;
	virtual bool   is_dead() const = 0;

	virtual void reduce_HP() = 0;

	virtual void set_flag() = 0;

	virtual void update() = 0;

	virtual void draw() const = 0;

	virtual void add_bullet(int xx, int yy) = 0;

	virtual std::shared_ptr<EnemyBullet> make_enemy_bullet(double x, double y, double vx, double vy) const = 0;
};


//©‹@‚ÉŒü‚©‚Á‚Ä‚­‚é“G
class Enemy_Pink : public I_Enemy{
	double x, y, vx, vy;
	int HP;
	bool eraseFlag;
	const double angle;
	const double movev;
	const double r;

public:
	Enemy_Pink(double xx, double yy);

	virtual double get_x() const;
	virtual double get_y() const;
	virtual int    get_HP() const;
	virtual double get_r() const;
	virtual bool   is_dead() const;

	virtual void reduce_HP();

	virtual void set_flag();

	virtual void update();

	virtual void draw() const;

	virtual void add_bullet(int xx, int yy);

	virtual std::shared_ptr<EnemyBullet> make_enemy_bullet(double x, double y, double vx, double vy) const;
};


//Ã~‚µ‚Ä‚¢‚é“G
class Enemy_Blue : public I_Enemy{
	double x, y;
	int HP;
	bool eraseFlag;
	int enemyFrame;
	const double r;
	const int shotRate;
	const double bulletSpeed;

public:

	Enemy_Blue(double xx, double yy);

	virtual double get_x() const;
	virtual double get_y() const;
	virtual int    get_HP() const;
	virtual double get_r() const;
	virtual bool   is_dead() const;

	virtual void reduce_HP();

	virtual void set_flag();

	virtual void update();

	virtual void draw() const;

	virtual void add_bullet(int xx, int yy);

	virtual std::shared_ptr<EnemyBullet> make_enemy_bullet(double x, double y, double vx, double vy) const;
};


//‰~‰^“®‚·‚é“G
class Enemy_Yellow : public I_Enemy{
	double x, y, vx, vy;
	int HP;
	bool eraseFlag;
	int enemyFrame;
	const double r; 
	const int shotRate;
	const double movev;
	const double bulletSpeed;

public:

	Enemy_Yellow(double xx, double yy);

	virtual double get_x() const;
	virtual double get_y() const;
	virtual int    get_HP() const;
	virtual double get_r() const;
	virtual bool   is_dead() const;

	virtual void reduce_HP();

	virtual void set_flag();

	virtual void update();

	virtual void draw() const;

	virtual void add_bullet(int xx, int yy);

	virtual std::shared_ptr<EnemyBullet> make_enemy_bullet(double x, double y, double vx, double vy) const;
};



//“G‚ğŠÇ—‚·‚éƒNƒ‰ƒX
class EnemyManager{
public:
	std::vector<std::shared_ptr<I_Enemy>> vec;

	void update();

	void draw() const;

	std::shared_ptr<I_Enemy> make_enemy_pink(double x, double y);
	std::shared_ptr<I_Enemy> make_enemy_blue(double x, double y);
	std::shared_ptr<I_Enemy> make_enemy_yellow(double x, double y);

	void add_enemy(std::shared_ptr<I_Enemy> ptr);
};