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
	Speed = 0;			//����
	this->img = img;	//�摜
	Hit = false;		//�������ĂȂ�
	IsLoad = false;		//�ǂݍ��߂���
	IsMove = true;		//�ړ�����

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

	if (img->GetIsDraw())	//�\�����Ȃ�
	{

		if (InScreen())	//��ʓ��Ȃ�
		{
			//�����蔻��
			if (OnCollision(player->GetCol()))	//�v���C���[�Ɠ������Ă�����
			{
				Hit = true;	//��������
			}

			//�e�Ƃ̓����蔻��
			for (int i = 0; i < player->GetBulleMax(); ++i)
			{
				if (OnCollision(player->GetBulletCol(i)))	//�e�Ɠ������Ă�����
				{
					Hit = true;		//��������
					player->HitBullet(i);	//�e����������
				}
			}

			Move();	//�ړ�
			Draw();	//�`��

		}
		else	//��ʊO�ɏo����
		{
			Spawn();		//�V��������
		}

	}

	if (Hit)	//����������
	{
		img->SetIsDraw(false);	//��\��
		IsMove = false;			//�����Ȃ�
		explosion->DrawCenter(collision);	//����

		if (explosion->GetIsEffectEnd())	//�G�t�F�N�g�`��I��������
		{
			explosion->Reset();		//�G�t�F�N�g���Z�b�g
			Spawn();				//����
		}
	}

}

//�����ݒ�
void Enemy::SetInit()
{
	img->SetInit();			//�摜
	explosion->SetInit();	//�G�t�F�N�g
	
	Spawn();	//����

}

//����
void Enemy::Spawn()
{

	Speed = GetRand(ENEMY_SPD_MAX - ENEMY_SPD_MIN) + ENEMY_SPD_MIN;	//����

	//�����蔻��ݒ�
	collision.left = GetRand(SPAWN_RIGHT - SPAWN_LEFT) + SPAWN_LEFT;//����X
	collision.top = -GetRand(SPAWN_HEIGHT);							//����Y
	collision.right = collision.left + img->GetWidth();				//�E��X
	collision.bottom = collision.top + img->GetHeight();			//�E��Y

	img->SetIsDraw(true);	//�\��
	Hit = false;	//�������Ă��Ȃ�
	IsMove = true;	//����

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

//�ړ�
void Enemy::Move()
{
	if (IsMove)	//�ړ�����Ƃ���
	{
		collision.top += Speed;
		collision.bottom += Speed;
	}
}

//��ʓ���
bool Enemy::InScreen()
{
	//��ʓ��Ȃ�true�A��ʊO�Ȃ�false��Ԃ�
	return collision.top < GAME_HEIGHT ? true : false;
}
