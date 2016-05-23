#pragma once

#include <DxLib.h>
#include <iostream>

class input{
private:
	input(){//�R���X�g���N�^��private�ɒu���A�N���X�O�Ő�������̂��֎~
		x = 30;
	}

	input(const input& r){}//�R�s�[���֎~
	input& operator=(const input& r){} //������֎~

public:
	static input& get(){
		static input inst;
		return inst;
	}

	int x;
	int keystate[256];
	char buf[256];
	int mousex, mousey;

	void update()
	{
		GetHitKeyStateAll(buf);
		for (int i = 0; i< 256; i++)
		{
			if (buf[i] == 1) keystate[i]++;
			else keystate[i] = 0;
		}
		GetMousePoint(&mousex, &mousey);
	}

	static bool keynow(int keynum){
		return get().keystate[keynum] > 0;
	}

	static bool keydown(int keynum){
		return get().keystate[keynum] == 1;
	}

	static int keytime(int keynum){
		return get().keystate[keynum];
	}
};
