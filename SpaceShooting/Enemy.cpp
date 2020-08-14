//Enemy.cpp

//########### �w�b�_�t�@�C���ǂݍ��� #############
#include "Enemy.hpp"

//########### �N���X��` ###############

//�R���X�g���N�^
//�����FImage *�F�L�����N�^�[�̉摜
Enemy::Enemy(Image* img)
{
	this->img = img;
}

//�f�X�g���N�^
Enemy::~Enemy() {}

//����s������
//void Enemy::UpDate()
//{
//
//}


//�����ݒ�
void Enemy::SetInit()
{
	img->SetInit();		//�摜�����ݒ�

	//�����蔻��ݒ�
	collision.left = (GAME_WIDTH / 2) - (img->GetWidth() / 2);		//����X
	collision.top = GAME_TOP;										//����Y
	collision.right = collision.left + img->GetWidth();				//�E��X
	collision.bottom = collision.top + img->GetHeight();			//�E��Y

}
