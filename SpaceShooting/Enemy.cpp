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
	Hit = false;		//�������ĂȂ�

}

//�f�X�g���N�^
Enemy::~Enemy() 
{
	delete img;	//img�j��
}

//����s������
void Enemy::UpDate(Player* player)
{

	//�����蔻��
	if (OnCollision(player->GetCol()))	//�v���C���[�Ɠ������Ă�����
	{
		Hit = true;	//��������
	}

	for (int i = 0; i < player->GetBulleMax(); ++i)
	{
		if (OnCollision(player->GetBulletCol(i)))	//�e�Ɠ������Ă�����
		{
			Hit = true;	//��������
		}
	}

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

//�`��
void Enemy::Draw()
{
	img->Draw(collision.left, collision.top);	//�`��
}

//�����蔻��
bool Enemy::OnCollision(RECT col)
{
	if (collision.left < col.right &&
		collision.right > col.left &&
		collision.top < col.bottom &&
		collision.bottom > col.top)
		return true;	//�������Ă�
	else
		return false;	//�������ĂȂ�
}
