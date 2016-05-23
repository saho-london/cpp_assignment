#include <DxLib.h>
#include <iostream>
#include <vector>
#include "GameManager.h"






int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);//非全画面にセット
	SetGraphMode(600, 600, 32);//画面サイズ指定
	SetOutApplicationLogValidFlag(FALSE);//Log.txtを生成しないように設定
	if (DxLib_Init() == 1){ return -1; }//初期化に失敗時にエラーを吐かせて終了


	FontHandle = CreateFontToHandle("Segoe UI", 20, 5, DX_FONTTYPE_ANTIALIASING_4X4);//フォントを読み込み

	//
	//ここで敵やプレイヤーのオブジェクトの実体を作る
	//
	GameManager::get().state = 0;


	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();//裏画面消す
		SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に

		input::get().update();

		//説明用・文字を描画：keystate配列（自作）には、各キーが何フレーム押され続けているかが入っている
		//DrawFormatStringToHandle(300, 300, 0xFFFFFF, FontHandle , "Z KEY %d", input::get().keystate[KEY_INPUT_Z]) ;
		//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

		//
		//　ここに敵やプレイヤーのupdate,drawを書く
		//

		if (GameManager::get().state == 1){
			DrawFormatStringToHandle(250, 300, 0xFF0000, FontHandle, "Game over");
		}

		GameManager::get().addupdate();
		GameManager::get().update();
		GameManager::get().draw();


		//左上に文字（マウスの座標）を描画
		//DrawFormatStringToHandle(20, 20, 0xFFFFFF, FontHandle , "MX:%3d MY:%3d", input::get().mousex,input::get().mousey) ;
		//DrawFormatStringToHandle(20, 40, 0xFFFFFF, FontHandle, "敵の数:%3d", GameManager::get().enemymanager.vec.size());
		//DrawFormatStringToHandle(20, 60, 0xFFFFFF, FontHandle, "%d", GameManager::get().state);

		ScreenFlip();//裏画面を表画面にコピー
	}

	DxLib_End();
	return 0;
}