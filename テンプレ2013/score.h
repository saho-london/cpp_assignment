#pragma once
#include "GameManager.h"



//�X�R�A���Ǘ�����N���X
class Score{
	int x;
public:
	int get_score() const;

	Score();

	void add_score(int xx);

	void draw() const;
};