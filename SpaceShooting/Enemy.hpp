//Enemy.hpp
//�G�L�������Ǘ�����N���X

#pragma once

//############ �w�b�_�t�@�C���ǂݍ��� ###############
#include "Global.hpp"
#include "Image.hpp"
#include "Player.hpp"
#include "Effect.hpp"

//############ �}�N����` ################
#define ENEMY_SPD	3	//�G�̈ړ����x

//############ �N���X��` ################
class Enemy
{

private:

	Effect* explosion;	//�����G�t�F�N�g
	Music* exp_se;		//������
	Image* img;		//�摜
	RECT collision;	//�����蔻��

	int Hp;			//HP
	int Speed;		//����

	bool Hit;		//��������
	bool IsLoad;	//�ǂݍ��߂�
	bool IsMove;	//�ړ����Ă��邩

	bool OnCollision(RECT);	//�����蔻��̏���

public:

	Enemy(Image*);			//�R���X�g���N�^
	~Enemy();				//�f�X�g���N�^

	void UpDate(Player*);	//����s������
	void SetInit();			//�����ݒ�
	void Draw();			//�`��
	bool GetIsLoad();		//�ǂݍ��߂����擾
	void Move();			//�ړ�

};
