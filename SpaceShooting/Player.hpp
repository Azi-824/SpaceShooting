//Player.hpp
//�v���C���[���Ǘ�����N���X

#pragma once

//############# �w�b�_�t�@�C���ǂݍ��� ###########
#include "Global.hpp"
#include "Charactor.hpp"

//############# �}�N����` ############

//############# �N���X��` ############
class Player : public Charactor	//Charactor�p��
{
private:

	//Image* img;		//�摜
	//RECT collision;	//�����蔻��

	int SpawnX;		//�e���˒n�_X
	int SpawnY;		//�e���˒n�_Y
	//int Hp;			//HP

	void Move();	//�ړ�

public:

	Player(Image*);			//�R���X�g���N�^
	~Player();				//�f�X�g���N�^

	void UpDate(Charactor*) override;	//����s������
	void Draw() override;	//�`��
	void SetInit() override;//�����ݒ�
	RECT GetBulletCol(int);	//�e�̓����蔻��擾
	int GetBulleMax();		//���݂̋ʂ̐����擾

};
