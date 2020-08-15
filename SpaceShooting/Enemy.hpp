//Enemy.hpp
//�G�L�������Ǘ�����N���X

#pragma once

//############ �w�b�_�t�@�C���ǂݍ��� ###############
#include "Global.hpp"
#include "Image.hpp"
#include "Player.hpp"

//############ �}�N����` ################

//############ �N���X��` ################
class Enemy
{

private:

	Image* img;		//�摜
	RECT collision;	//�����蔻��

	int Hp;			//HP
	bool Hit;		//��������

	bool OnCollision(RECT);	//�����蔻��̏���

public:

	Enemy(Image*);			//�R���X�g���N�^
	~Enemy();				//�f�X�g���N�^

	void UpDate(Player*);	//����s������
	void SetInit();			//�����ݒ�
	void Draw();			//�`��

};
