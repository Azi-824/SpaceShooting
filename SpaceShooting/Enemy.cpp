//Enemy.cpp

//########### �w�b�_�t�@�C���ǂݍ��� #############
#include "Enemy.hpp"

//########### �N���X��` ###############

//�R���X�g���N�^
//�����FImage *�F�L�����N�^�[�̉摜
Enemy::Enemy(Image* img)
{
	this->img = img;

	//�e
	b_anim = new Animation(ANIM_DIR, ANIM_NAME_E_BULLET, ANIM_BULLET_ALL_CNT, ANIM_BULLET_YOKO_CNT, ANIM_BULLET_TATE_CNT,
		ANIM_BULLET_WIDTH, ANIM_BULLET_HEIGHT, ANIM_BULLET_SPEED, true);	//�e�A�j���[�V����
	bullet = new Bullet(b_anim);	//�e����

}

//�f�X�g���N�^
Enemy::~Enemy() {}

//�����ݒ�
void Enemy::SetInit()
{
	img->SetInit();		//�摜�����ݒ�

	//�����蔻��ݒ�
	collision.left = (GAME_WIDTH / 2) - (img->GetWidth() / 2);		//����X
	collision.top = GAME_TOP + img->GetHeight();					//����Y
	collision.right = collision.left + img->GetWidth();				//�E��X
	collision.bottom = collision.top + img->GetHeight();			//�E��Y

	bullet->SetInit(GAME_WIDTH / 2, collision.top);	//�e�����ݒ�

}

//�`��
void Enemy::Draw()
{
	img->Draw(collision.left, collision.top);	//�`��(�L����)
	bullet->Draw();								//�`��(�e)
}

//�e������
void Enemy::Shot()
{
	bullet->SetIsDraw(true);	//�e�̕`����I����
}