#include <DxLib.h>
#include <iostream>
#include <vector>
#include "GameManager.h"






int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
	SetGraphMode(600, 600, 32);//��ʃT�C�Y�w��
	SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤�ɐݒ�
	if (DxLib_Init() == 1){ return -1; }//�������Ɏ��s���ɃG���[��f�����ďI��


	FontHandle = CreateFontToHandle("Segoe UI", 20, 5, DX_FONTTYPE_ANTIALIASING_4X4);//�t�H���g��ǂݍ���

	//
	//�����œG��v���C���[�̃I�u�W�F�N�g�̎��̂����
	//
	GameManager::get().state = 0;


	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();//����ʏ���
		SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�

		input::get().update();

		//�����p�E������`��Fkeystate�z��i����j�ɂ́A�e�L�[�����t���[�������ꑱ���Ă��邩�������Ă���
		//DrawFormatStringToHandle(300, 300, 0xFFFFFF, FontHandle , "Z KEY %d", input::get().keystate[KEY_INPUT_Z]) ;
		//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

		//
		//�@�����ɓG��v���C���[��update,draw������
		//

		if (GameManager::get().state == 1){
			DrawFormatStringToHandle(250, 300, 0xFF0000, FontHandle, "Game over");
		}

		GameManager::get().addupdate();
		GameManager::get().update();
		GameManager::get().draw();


		//����ɕ����i�}�E�X�̍��W�j��`��
		//DrawFormatStringToHandle(20, 20, 0xFFFFFF, FontHandle , "MX:%3d MY:%3d", input::get().mousex,input::get().mousey) ;
		//DrawFormatStringToHandle(20, 40, 0xFFFFFF, FontHandle, "�G�̐�:%3d", GameManager::get().enemymanager.vec.size());
		//DrawFormatStringToHandle(20, 60, 0xFFFFFF, FontHandle, "%d", GameManager::get().state);

		ScreenFlip();//����ʂ�\��ʂɃR�s�[
	}

	DxLib_End();
	return 0;
}