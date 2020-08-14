//Player.cpp

//########### �w�b�_�t�@�C���ǂݍ��� #############
#include "Player.hpp"

//########### �N���X��` ############

//�R���X�g���N�^
//�����FImage *�F�L�����N�^�[�̉摜
Player::Player(Image* img)
{
	this->img = img;
	Animation::CreateList();
	bullet.push_back(new Bullet());
}

//�f�X�g���N�^
Player::~Player()
{
	for (auto b : bullet) { delete b; }
	vector<Bullet*> v;
	bullet.swap(v);
}

//����s������
void Player::UpDate()
{
	if (Mouse::OnLeftClick())	//���N���b�N���ꂽ��
	{
		Shot();	//�e������
		bullet.push_back(new Bullet());	//�e�𐶐�
		bullet.back()->SetInit(GAME_WIDTH / 2, collision.top);	//�����ݒ�
	}

	//��ʊO�ɏo���e���폜
	for (int i = 0; i < bullet.size(); ++i)
	{
		if (!bullet.at(i)->InScreen())
		{
			delete bullet.at(i);	//�j��
			bullet.erase(bullet.begin() + i);
		}
	}
	Draw();
}


//�����ݒ�
void Player::SetInit()
{
	img->SetInit();		//�摜�����ݒ�
	
	//�����蔻��ݒ�
	collision.left = (GAME_WIDTH / 2) - (img->GetWidth() / 2);		//����X
	collision.top = GAME_HEIGHT - img->GetHeight();					//����Y
	collision.right = collision.left + img->GetWidth();				//�E��X
	collision.bottom = collision.top + img->GetHeight();			//�E��Y

	for (auto b : bullet) { b->SetInit(GAME_WIDTH / 2, collision.top); }

}

//�`��
void Player::Draw()
{
	img->Draw(collision.left, collision.top);	//�`��(�L����)
	for (auto b : bullet) { b->Draw(); }
}

//�e������
void Player::Shot()
{
	bullet.back()->SetIsDraw(true);
}