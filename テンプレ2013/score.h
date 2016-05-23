#pragma once
#include "GameManager.h"



//スコアを管理するクラス
class Score{
	int x;
public:
	int get_score() const;

	Score();

	void add_score(int xx);

	void draw() const;
};