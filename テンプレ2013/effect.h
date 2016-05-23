#pragma once
#include <vector>
#include "GameManager.h"
#include <memory>


//�G�t�F�N�g�̊e�p�[�e�B�N���̃N���X
class Effect{
	double x, y;
	int frame;

public:
	double get_x()     const;
	double get_y()     const;
	int    getframe() const;

	Effect(double xx, double yy);

	void update();

	void draw() const;
};


//�G�t�F�N�g���Ǘ�����N���X
class EffectManager{
public:
	std::vector<std::shared_ptr<Effect>> vec;

	void update();

	void draw() const;

	void add_effect(double x, double y, int volume, double range);
};