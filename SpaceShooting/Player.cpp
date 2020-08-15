//Player.cpp

//########### �w�b�_�t�@�C���ǂݍ��� #############
#include "Player.hpp"

//########### �N���X��` ############

//�R���X�g���N�^
//�����FImage *�F�L�����N�^�[�̉摜
Player::Player(Image* img)
{
	//�����o�[������
	collision = { 0 };	//�����蔻��
	Hp = 0;				//HP
	rota = 0.0;			//�p�x

	this->img = img;
	bullet.push_back(new Bullet());
}

//�f�X�g���N�^
Player::~Player()
{
	for (auto b : bullet) { delete b; }
	vector<Bullet*> v;
	bullet.swap(v);

	delete img;	//img�j��
}

//����s������
void Player::UpDate()
{

	//�p�x�v�Z
	CalcRota();

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

	for (auto b : bullet) { b->SetInit(GAME_WIDTH / 2, collision.top); }	//�e�̏�����

}

//�`��
void Player::Draw()
{
	img->DrawRota(collision.left, collision.top,rota);	//�`��(�L����)
	for (auto b : bullet) { b->Draw(); }		//�e�`��
}

//�e������
void Player::Shot()
{
	bullet.back()->SetIsDraw(true);
}

//�����蔻��擾
RECT Player::GetCol()
{
	return collision;
}

//�e�̓����蔻��擾
RECT Player::GetBulletCol(int element)
{
	return bullet.at(element)->GetCol();
}

//���݂̒e�̐����擾
int Player::GetBulleMax()
{
	return Bullet::GetElementMax();
}

//�p�x�v�Z
void Player::CalcRota()
{
	int x = 0, y = 0;		//�}�E�X�ʒu�擾�p
	Mouse::GetPos(&x, &y);	//�}�E�X�ʒu�擾

	if (x < GAME_LEFT || x > GAME_WIDTH)	//��ʊO�̏ꍇ
		return;			//�v�Z���Ȃ�

	x -= ROTA_BASE;			//��l����̋����𑪒�

	//�p�x�v�Z����
	rota = (double)x / ROTA_BASE;

}