//Enemy.hpp
//�G�L�������Ǘ�����N���X

#pragma once

//############ �w�b�_�t�@�C���ǂݍ��� ###############
#include "Global.hpp"
#include "Image.hpp"

//############ �}�N����` ################

//############ �N���X��` ################
class Enemy
{

private:

	Image* img;		//�摜
	RECT collision;	//�����蔻��

	int Hp;			//HP

public:

	Enemy(Image*);		//�R���X�g���N�^
	~Enemy();			//�f�X�g���N�^

	void UpDate();		//����s������
	void SetInit();		//�����ݒ�
	RECT GetCol();		//�����蔻��擾
	void Draw();		//�`��

};
