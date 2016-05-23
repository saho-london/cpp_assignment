#pragma once
#include <iostream>
#include "Player.h"
#include "enemy.h"
#include "PlayerBullet.h"
#include "EnemyBullet.h"
#include "effect.h"
#include "Score.h"
#include "myglobal.h"
#include "input.h"



class GameManager{

public:
	static GameManager& get(){
		static GameManager inst;
		return inst;
	}

	int state;
	Player player;
	EnemyManager enemymanager;
	PlayerBulletManager playerbulletmanager;
	EnemyBulletManager enemybulletmanager;
	EffectManager effectmanager;
	Score score;

	void update();

	void draw();

	//�G�̐���
	void addupdate();

private:
	GameManager(){
	};
	GameManager(const GameManager& r) = delete;//�R�s�[�֎~
	GameManager& operator=(const GameManager& r) = delete;//����֎~
};