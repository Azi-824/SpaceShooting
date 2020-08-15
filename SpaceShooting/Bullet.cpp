//Bullet.cpp

//############## �w�b�_�t�@�C���ǂݍ��� ####################
#include "Bullet.hpp"

//############## �N���X��` ################

int Bullet::ElementCnt = 0;	//�v�f��

//�R���X�g���N�^
/*
�����FAnimation *�F�e�̃A�j���[�V����
*/
Bullet::Bullet(Animation* anim)
{
	//�����o�[������
	this->anim = anim;		//�e�̃A�j���[�V����
	collision = { 0 };		//�����蔻��
	Speed = 0;				//����
	IsDraw = false;			//�ŏ��͕`�悵�Ȃ�
	++ElementCnt;			//�v�f���J�E���g
}

//�R���X�g���N�^
Bullet::Bullet()
{
	//�����o�[������
	anim = new Animation(ANIM_BULLET, ANIM_BULLET_SPEED,true);		//�e�̃A�j���[�V����
	collision = { 0 };		//�����蔻��
	Speed = 0;				//����
	IsDraw = false;			//�ŏ��͕`�悵�Ȃ�
	++ElementCnt;			//�v�f���J�E���g
}

//�f�X�g���N�^
Bullet::~Bullet()
{
	delete anim;	//anim�j��
	--ElementCnt;	//�J�E���g�_�E��
}

//�����ݒ�
void Bullet::SetInit(int x, int y)
{
	Speed = BULLET_SPEED;
	//�����蔻��ݒ�
	collision.left = x;
	collision.top = y;
	collision.right = x + anim->GetWidth();
	collision.bottom = y + anim->GetHeight();
	IsDraw = false;	//�ŏ��͕`�悵�Ȃ�
}

//�`�悷�邩�ݒ�
void Bullet::SetIsDraw(bool draw)
{
	IsDraw = draw;
}

//�`��
void Bullet::Draw()
{
	if (IsDraw)	//�`�悷��Ƃ�
	{
		anim->Draw(collision.left,collision.top);	//�`��
		//�e���ړ�
		collision.top -= Speed;
		collision.bottom -= Speed;
	}
}

//��ʓ���
bool Bullet::InScreen()
{
	if (collision.top < GAME_TOP ||
		collision.left < GAME_LEFT ||
		collision.right > GAME_WIDTH)
		return false;
	else
		return true;

}

//�����蔻��擾
RECT Bullet::GetCol()
{
	return collision;
}

//�v�f���擾
int Bullet::GetElementMax()
{
	return ElementCnt;
}
