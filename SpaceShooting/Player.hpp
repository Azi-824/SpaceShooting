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

	vector<Bullet*> bullet;	//�e
	Image* img;		//�摜
	RECT collision;	//�����蔻��

	int Hp;			//HP

	int SpawnX;		//�e���˒n�_X
	int SpawnY;		//�e���˒n�_Y

	void Move();	//�ړ�

public:

	Player(Image*);			//�R���X�g���N�^
	~Player();				//�f�X�g���N�^

	void UpDate();		//����s������
	void Draw();		//�`��
	void SetInit();		//�����ݒ�
	RECT GetCol();			//�����蔻��擾
	RECT GetBulletCol(int);	//�e�̓����蔻��擾
	int GetBulleMax();		//���݂̋ʂ̐����擾
	void HitBullet(int);	//�G�ɒe����������

};
