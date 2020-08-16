//Collision.cpp

//################## �w�b�_�t�@�C���ǂݍ��� ###############
#include "Collision.hpp"

//################## �N���X��` ##################

//�R���X�g���N�^
/*
�����Fint�F��(X)
�����Fint�F��(Y)
�����Fint�F�E(X)
�����Fint�F�E(Y)
*/
Collision::Collision(int left, int top, int right, int bottom)
{
	//���W�ݒ�
	LeftTop.X = left;		//����(X)
	LeftTop.Y = top;		//����(Y)
	RightTop.X = right;		//�E��(X)
	RightTop.Y = top;		//�E��(Y)
	LeftBottom.X = left;	//����(X)
	LeftBottom.Y = bottom;	//����(Y)
	RightBottom.X = right;	//�E��(X)
	RightBottom.Y = bottom;	//�E��(Y)
}

//�R���X�g���N�^
Collision::Collision()
{
	//������
	LeftTop = { 0 };
	RightTop = { 0 };
	LeftBottom = { 0 };
	RightBottom = { 0 };
}

//�f�X�g���N�^
Collision::~Collision(){}

//�ݒ�
/*
�����Fint�F��(X)
�����Fint�F��(Y)
�����Fint�F�E(X)
�����Fint�F�E(Y)
*/
void Collision::Set(int left, int top, int right, int bottom)
{
	//���W�ݒ�
	LeftTop.X = left;		//����(X)
	LeftTop.Y = top;		//����(Y)
	RightTop.X = right;		//�E��(X)
	RightTop.Y = top;		//�E��(Y)
	LeftBottom.X = left;	//����(X)
	LeftBottom.Y = bottom;	//����(Y)
	RightBottom.X = right;	//�E��(X)
	RightBottom.Y = bottom;	//�E��(Y)
}

//�`��
void Collision::Draw()
{

	//�����蔻��̗̈���l�p�`�ŕ`��(��ŏC�����邩��)
	DrawLine(LeftTop.X, LeftTop.Y, RightTop.X, RightTop.Y, COLOR_RED);
	DrawLine(RightTop.X, RightTop.Y, RightBottom.X, RightBottom.Y, COLOR_RED);
	DrawLine(RightBottom.X, RightBottom.Y, LeftBottom.X, LeftBottom.Y, COLOR_RED);
	DrawLine(LeftBottom.X, LeftBottom.Y, LeftTop.X, LeftTop.Y, COLOR_RED);

}