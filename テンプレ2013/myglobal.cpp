#include "GameManager.h"
#include <iostream>

int FontHandle;//フォント読み込み用変数

bool hit_circle(double x1, double y1, double r1, double x2, double y2, double r2){
	double Dist = pow(x1 - x2, 2) + pow(y1 - y2, 2);
	return Dist < pow(r1 + r2, 2);
	//return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) < (r1 + r2) * (r1 + r2);
}

//画面外に出たかの判定
bool off_screen(double x, double y){
	return y > 650 || y < -50 || x > 850 || x < -50;
}