//Enemy.hpp
//�G�L�������Ǘ�����N���X

#pragma once

//############ �w�b�_�t�@�C���ǂݍ��� ###############
#include "Global.hpp"
#include "Charactor.hpp"
#include "Player.hpp"
#include "Effect.hpp"

//############ �}�N����` ################

//############ �N���X��` ################
class Enemy : public Charactor	//Charactor�p��
{

private:

	Effect* explosion;	//�����G�t�F�N�g
	Music* exp_se;		//������

	bool Hit;		//��������
	bool IsLoad;	//�ǂݍ��߂�

	bool OnCollision(RECT);	//�����蔻��̏���

public:

	Enemy(Image*);			//�R���X�g���N�^
	~Enemy();				//�f�X�g���N�^

	void UpDate(Charactor*) override;	//����s������
	void SetInit() override;			//�����ݒ�
	void Draw() override;			//�`��
	bool GetIsLoad();		//�ǂݍ��߂����擾

};
