//Enemy.cpp

//########### �w�b�_�t�@�C���ǂݍ��� #############
#include "Enemy.hpp"

//########### �N���X��` ###############

//�R���X�g���N�^
//�����FImage *�F�L�����N�^�[�̉摜
Enemy::Enemy(Image* img)
{
	//�����o�[������
	collision = { 0 };	//�����蔻��
	Hp = 0;				//HP
	this->img = img;	//�摜

}

//�f�X�g���N�^
Enemy::~Enemy() 
{
	delete img;	//img�j��
}

//����s������
void Enemy::UpDate()
{
	Draw();	//�`��
}


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

//�����蔻��擾
RECT Enemy::GetCol()
{
	return collision;
}

//�`��
void Enemy::Draw()
{
	img->Draw(collision.left, collision.top);	//�`��
}
