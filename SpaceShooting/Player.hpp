//Player.hpp
//�v���C���[���Ǘ�����N���X

#pragma once

//############# �w�b�_�t�@�C���ǂݍ��� ###########
#include "Charactor.hpp"
#include "Bullet.hpp"

//############# �}�N����` ############

//############# �N���X��` ############
class Player : public Charactor	//Charactor���p��
{
private:

	Animation* b_anim;	//�e�̃A�j���[�V����
	Bullet* bullet;		//�e

public:

	Player(Image*);		//�R���X�g���N�^
	~Player();			//�f�X�g���N�^

	void UpDate() override;		//����s������
	void Draw() override;		//�`��
	void SetInit() override;	//�����ݒ�
	void Shot();				//�e��ł�

};
