//Collision.hpp
//�����蔻��̃N���X

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ##################
#include "Global.hpp"

//################### �}�N����` ####################

//################### �\���� #######################
struct Coordinate
{
	int X;	//X
	int Y;	//Y
};	//���W

//################### �N���X��` ####################
class Collision
{
private:

	Coordinate LeftTop;		//����
	Coordinate RightTop;	//�E��
	Coordinate LeftBottom;	//����
	Coordinate RightBottom;	//�E��

public:

	Collision(int, int, int, int);	//�R���X�g���N�^
	Collision(	);					//�R���X�g���N�^
	~Collision();					//�f�X�g���N�^

	void Set(int, int, int, int);	//�ݒ�
	void Draw();					//�`��

};
