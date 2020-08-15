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
	IsLoad = false;		//�ǂݍ��߂���

	exp_se = new Music(MUSIC_DIR_EFFECT, SE_NAME_EFFECT_EXPLOSION);	//�������ʉ��ǂݍ���
	IsLoad = exp_se->GetIsLoad();	//�ǂݍ��߂���
	explosion = new Effect(new Animation(ANIM_EXPLOSION, ANIM_EXPLOSION_SPEED, false), exp_se);	//�����G�t�F�N�g����

}

//�f�X�g���N�^
Enemy::~Enemy() 
{
	delete img;			//img�j��
	delete explosion;	//explosion�j��
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

	if (Hit)	//����������
	{
		explosion->DrawCenter(collision);	//����
		if (explosion->GetIsEffectEnd())	//�G�t�F�N�g�`��I��������
		{
			explosion->Reset();	//�G�t�F�N�g���Z�b�g
			Hit = false;
		}
	}

}


//�����ݒ�
void Enemy::SetInit()
{
	img->SetInit();			//�摜
	explosion->SetInit();	//�G�t�F�N�g

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

//�ǂݍ��߂����擾
bool Enemy::GetIsLoad()
{
	return IsLoad;
}
