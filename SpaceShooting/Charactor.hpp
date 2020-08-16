//Charactor.hpp
//�G�A�����̊�ɂȂ�N���X

#pragma once

//##################### �w�b�_�t�@�C���ǂݍ��� #####################
#include "Global.hpp"
#include "Image.hpp"
#include "Bullet.hpp"

//##################### �}�N����` ##################


//##################### �N���X��` ##################
class Charactor
{

protected:

	Image* img;		//�摜
	RECT collision;	//�����蔻��
	vector<Bullet*> bullet;	//�e

	int Hp;			//HP

public:

	Charactor();	//�R���X�g���N�^
	~Charactor();	//�f�X�g���N�^

	virtual void UpDate(Charactor*);	//����s������

	virtual void Draw();	//�`��
	virtual void SetInit();	//�����ݒ�

	RECT GetCol();			//�����蔻��擾

};
