//Enemy.hpp
//�G�L�������Ǘ�����N���X

#pragma once

//############ �w�b�_�t�@�C���ǂݍ��� ###############
#include "Charactor.hpp"

//############ �}�N����` ################

//############ �N���X��` ################
class Enemy : public Charactor	//Charactor�N���X�p��
{

private:

public:

	Enemy(Image*);		//�R���X�g���N�^
	~Enemy();			//�f�X�g���N�^

	//virtual void UpDate();	//����s������
	void SetInit() override;	//�����ݒ�

};
