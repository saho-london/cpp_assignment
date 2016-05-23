#include "GameManager.h"


Score::Score() :
x(0){

}

int Score::get_score() const {
	return x;
}

void Score::add_score(int xx){
	x += xx;
}

void Score::draw() const {
	DrawFormatStringToHandle(20, 20, 0xFFFFFF, FontHandle, "SCORE %d", x);
}