//Charactor.cpp

//############ �w�b�_�t�@�C���ǂݍ��� ###############
#include "Charactor.hpp"

//############ �N���X��` ############

//�R���X�g���N�^
Charactor::Charactor()
{
	//�����o�[������
	img = new Image();	//�C���X�^���X����
	collision = { 0 };	//�����蔻��
	Hp = 0;				//HP
}

//�f�X�g���N�^
Charactor::~Charactor()
{
	delete img;	//img�j��
}
