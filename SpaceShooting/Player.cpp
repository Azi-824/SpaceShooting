//Player.cpp

//########### �w�b�_�t�@�C���ǂݍ��� #############
#include "Player.hpp"

//########### �N���X��` ############

//�R���X�g���N�^
//�����FImage *�F�L�����N�^�[�̉摜
Player::Player(Image* img)
{
	this->img = img;
}

//�f�X�g���N�^
Player::~Player(){}

//�����ݒ�
void Player::SetInit()
{
	img->SetInit();		//�摜�����ݒ�
	
	//�����蔻��ݒ�
	collision.left = (GAME_WIDTH / 2) - (img->GetWidth() / 2);		//����X
	collision.top = GAME_HEIGHT - img->GetHeight();					//����Y
	collision.right = collision.left + img->GetWidth();				//�E��X
	collision.bottom = collision.top + img->GetHeight();			//�E��Y

}