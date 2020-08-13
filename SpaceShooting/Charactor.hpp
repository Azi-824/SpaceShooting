//Charactor.hpp
//�G�A�����̊�ɂȂ�N���X

#pragma once

//##################### �w�b�_�t�@�C���ǂݍ��� #####################
#include "Global.hpp"
#include "Image.hpp"

//##################### �}�N����` ##################

//##################### �N���X��` ##################
class Charactor
{

protected:

	Image* img;		//�摜
	RECT collision;	//�����蔻��

	int Hp;			//HP

public:

	Charactor();	//�R���X�g���N�^
	~Charactor();	//�f�X�g���N�^

	virtual void Draw() = 0;	//�`��
	virtual void SetInit() = 0;	//�����ݒ�

};
