//Player.hpp
//�v���C���[���Ǘ�����N���X

#pragma once

//############# �w�b�_�t�@�C���ǂݍ��� ###########
#include "Global.hpp"
#include "Image.hpp"
#include "Bullet.hpp"

//############# �}�N����` ############

//############# �N���X��` ############
class Player
{
private:

	Image* img;		//�摜
	RECT collision;	//�����蔻��
	vector<Bullet*> bullet;	//�e

	int SpawnX;		//�e���˒n�_X
	int SpawnY;		//�e���˒n�_Y
	int Hp;			//HP
	double rota;	//�p�x

	void Move();	//�ړ�

public:

	Player(Image*);			//�R���X�g���N�^
	~Player();				//�f�X�g���N�^

	void UpDate();			//����s������
	void Draw();			//�`��
	void SetInit();			//�����ݒ�
	void Shot();			//�e��ł�
	RECT GetCol();			//�����蔻��擾
	RECT GetBulletCol(int);	//�e�̓����蔻��擾
	int GetBulleMax();		//���݂̋ʂ̐����擾

};
