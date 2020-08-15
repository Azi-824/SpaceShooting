//Bullet.hpp
//�e���Ǘ�����N���X

#pragma once

//################# �w�b�_�t�@�C���ǂݍ��� #################
#include "Global.hpp"
#include "Animation.hpp"

//################## �}�N����` ####################
#define BULLET_SPEED 5	//�e�̑��x

//################## �N���X��` ####################
class Bullet
{
private:

	Animation* anim;		//�e�̃A�j���[�V����
	RECT collision;			//�����蔻��
	int Speed;				//����
	bool IsDraw;			//�`�悵�Ă��邩
	static int ElementCnt;	//�v�f�ԍ��J�E���g�p

public:

	Bullet(Animation*);	//�R���X�g���N�^
	Bullet();			//�R���X�g���N�^
	~Bullet();			//�f�X�g���N�^

	void SetInit(int,int);		//�����ݒ�
	void SetIsDraw(bool);		//�`�悷�邩�ݒ�

	void Draw();				//�`��
	bool InScreen();			//��ʓ���
	RECT GetCol();				//�����蔻��擾
	static int GetElementMax();	//�v�f�ԍ��擾

};
