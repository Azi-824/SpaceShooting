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
	Coordinate LeftTop = { left,top };		//����
	Coordinate RightTop = { right,top };	//�E��
	Coordinate RightBottom{ right,bottom };	//�E��
	Coordinate LeftBottom{ left,bottom };	//����

	Pos.push_back(LeftTop);		//����
	Pos.push_back(RightTop);	//�E��
	Pos.push_back(RightBottom);	//�E��
	Pos.push_back(LeftBottom);	//����

	CenterX = (left + right) / 2;
	CenterY = (top + bottom) / 2;
}

//�R���X�g���N�^
Collision::Collision()
{
	//������
	CenterX = 0;
	CenterY = 0;
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
	Coordinate LeftTop = { left,top };		//����
	Coordinate RightTop = { right,top };	//�E��
	Coordinate RightBottom{ right,bottom };	//�E��
	Coordinate LeftBottom{ left,bottom };	//����

	Pos.push_back(LeftTop);		//����
	Pos.push_back(RightTop);	//�E��
	Pos.push_back(RightBottom);	//�E��
	Pos.push_back(LeftBottom);	//����

	CenterX = (left + right) / 2;
	CenterY = (top + bottom) / 2;

}

//�`��
void Collision::Draw()
{

	//�����蔻��̗̈���l�p�`�ŕ`��(��ŏC�����邩��)
	for (int i = 0; i < Pos.size(); ++i)
	{
		if (i == Pos.size() - 1)	//�Ō�̏ꍇ
		{
			DrawLine(Pos.at(i).X, Pos.at(i).Y, Pos.front().X, Pos.front().Y, COLOR_RED);
		}
		else //����ȊO
		{
			DrawLine(Pos.at(i).X, Pos.at(i).Y, Pos.at(i + 1).X, Pos.at(i + 1).Y, COLOR_RED);
		}
	}

}

//��]
void Collision::Rota(int rota)
{

	double cos_value = cos(rota);	//cos
	double sin_value = sin(rota);	//sin

}