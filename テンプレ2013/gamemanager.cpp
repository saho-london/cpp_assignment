#include "GameManager.h"


void GameManager::update(){
	if (state == 0){
		player.update();
	}
	enemymanager.update();
	playerbulletmanager.update();
	enemybulletmanager.update();
	effectmanager.update();


}

void GameManager::draw(){
	enemybulletmanager.draw();
	if (state == 0){
		player.draw();
	}
	enemymanager.draw();
	playerbulletmanager.draw();
	effectmanager.draw();
	score.draw();
}

//“G‚Ì¶¬
void GameManager::addupdate(){
	if (input::get().keystate[KEY_INPUT_A] == 1){
		enemymanager.add_enemy(enemymanager.make_enemy_pink(GetRand(600), GetRand(200)));
	}
	if (input::get().keystate[KEY_INPUT_S] == 1){
		enemymanager.add_enemy(enemymanager.make_enemy_blue(GetRand(600), GetRand(200)));
	}
	if (input::get().keystate[KEY_INPUT_D] == 1){
		enemymanager.add_enemy(enemymanager.make_enemy_yellow(GetRand(600), GetRand(200)));
	}
}
