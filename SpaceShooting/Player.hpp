//Player.hpp
//�v���C���[���Ǘ�����N���X

#pragma once

//############# �w�b�_�t�@�C���ǂݍ��� ###########
#include "Charactor.hpp"

//############# �}�N����` ############

//############# �N���X��` ############
class Player : public Charactor	//Charactor���p��
{
private:

public:

	Player(Image*);		//�R���X�g���N�^
	~Player();			//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�

};
